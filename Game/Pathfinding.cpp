#include "Pathfinding.h"

#include <iostream>
#include <queue>

#include "BaseEnemy.h"
#include "GameSingleton.h"
#include "../Engine/Core/CollisionObject.h"
#include "../Engine/Core/Vector.h"

Pathfinding::Pathfinding(int width_, int height_)
{
    mapWidth = width_;
    mapHeight = height_;

    init();
}

Pathfinding::Pathfinding(int width_, int height_, int offsetX_, int offsetY_)
{
    mapWidth = width_;
    mapHeight = height_;
    offsetX = offsetX_;
    offsetY = offsetY_;

    init();
}

AStarNode* Pathfinding::vectorToNode(const Vector& v) const
{
    const int x = (static_cast<int>(v.x) - offsetX) / cellSize;
    const int y = (static_cast<int>(v.y) - offsetX) / cellSize;

    return &nodes[y * mapWidth + x];
}

Vector Pathfinding::nodeToVector(const AStarNode* node) const
{
    const float x = (node->x + 0.5f) * cellSize + offsetX;
    const float y = (node->y + 0.5f) * cellSize + offsetY;

    return Vector(x, y);
}

float Pathfinding::distance(const AStarNode* node1, const AStarNode* node2) const
{
    return abs(sqrt((node1->x - node2->x) * (node1->x - node2->x) + (node1->y - node2->y) * (node1->y - node2->y)));
}

float Pathfinding::heuristic(AStarNode* node1, AStarNode* node2)
{
    //Maybe I need to make a few changes for the heuristic
    return distance(node1, node2) + node1->heat;
}

bool Pathfinding::findPath(Vector& start, Vector& end, std::vector<Vector>& path, const Object* callingObject)
{
    if (start == end)
    {
        path.clear();
        return true;
    }

    resetGrid();

    AStarNode* nodeStart = vectorToNode(start);
    AStarNode* nodeEnd = vectorToNode(end);

    nodeStart->localGoal = 0.f;
    nodeStart->globalGoal = heuristic(nodeStart, nodeEnd);

    auto compareNodes = [](const AStarNode* a, const AStarNode* b)
    {
        return a->globalGoal > b->globalGoal;
    };
    std::priority_queue<AStarNode*, std::vector<AStarNode*>, decltype(compareNodes)> pqOpenNodes(compareNodes);
    pqOpenNodes.push(nodeStart);

    while (!pqOpenNodes.empty())
    {
        AStarNode* nodeCurrent = pqOpenNodes.top();
        pqOpenNodes.pop();
        nodeCurrent->visited = true;

        for (auto neighbour : nodeCurrent->neighbours)
        {
            if (neighbour->visited || (neighbour->blocked && neighbour->blockingObject != callingObject))
                continue;

            float possiblyLowerGoal = nodeCurrent->localGoal + distance(nodeCurrent, neighbour);

            if (possiblyLowerGoal < neighbour->localGoal)
            {
                neighbour->parent = nodeCurrent;
                neighbour->localGoal = possiblyLowerGoal;

                neighbour->globalGoal = neighbour->localGoal + heuristic(neighbour, nodeEnd);
                pqOpenNodes.push(neighbour);
            }
        }

        if (nodeCurrent == nodeEnd)
        {
            AStarNode* p = nodeEnd;
            while (p->parent != nullptr)
            {
                path.push_back(nodeToVector(p));
                p = p->parent;
            }
            std::reverse(path.begin(), path.end());

            return true;
        }
    }

    printf("\033[31m No Path found \n");
    return false;
}

void Pathfinding::applyHeat(AStarNode* node, float heat, Object* heatSrc)
{
    if (node->blocked) { return; }
    if (node->heatSrc == heatSrc) { return; }

    node->heat += heat;
    node->heatSrc = heatSrc;
}

void Pathfinding::resetGrid()
{
    for (int x = 0; x < mapWidth; ++x)
    {
        for (int y = 0; y < mapHeight; ++y)
        {
            nodes[y * mapWidth + x].reset();
        }
    }
}

void Pathfinding::init()
{
    name = typeid(this).name();
    nodes = new AStarNode[mapHeight * mapWidth];

    //Allocate Space for pathfinding grid
    for (int x = 0; x < mapWidth; ++x)
    {
        for (int y = 0; y < mapHeight; ++y)
        {
            nodes[y * mapWidth + x].x = x;
            nodes[y * mapWidth + x].y = y;
        }
    }


    //Get neighbours of nodes
    for (int x = 0; x < mapWidth; ++x)
    {
        for (int y = 0; y < mapHeight; ++y)
        {
            if (y > 0) //Top
                nodes[y * mapWidth + x].neighbours.push_back(&nodes[(y - 1) * mapWidth] + (x + 0));

            if (y < mapHeight - 1) //Down
                nodes[y * mapWidth + x].neighbours.push_back(&nodes[(y + 1) * mapWidth] + (x + 0));

            if (y > 0) //Left
                nodes[y * mapWidth + x].neighbours.push_back(&nodes[(y + 0) * mapWidth] + (x - 1));

            if (y < mapHeight - 1) //Right
                nodes[y * mapWidth + x].neighbours.push_back(&nodes[(y + 0) * mapWidth] + (x + 1));

            if (y > 0 && x > 0) //Top Left
                nodes[y * mapWidth + x].neighbours.push_back(&nodes[(y - 1) * mapWidth + (x - 1)]);

            if (y < mapHeight - 1 && x > 0) //Down Left
                nodes[y * mapWidth + x].neighbours.push_back(&nodes[(y + 1) * mapWidth + (x - 1)]);

            if (y > 0 && x < mapWidth - 1) //Top Right
                nodes[y * mapWidth + x].neighbours.push_back(&nodes[(y - 1) * mapWidth + (x + 1)]);

            if (y < mapHeight - 1 && x < mapWidth - 1) //Down Right
                nodes[y * mapWidth + x].neighbours.push_back(&nodes[(y + 1) * mapWidth + (x + 1)]);
        }
    }
}

void Pathfinding::update()
{
    Object::update();

    for (int x = 0; x < mapWidth; ++x)
    {
        for (int y = 0; y < mapHeight; ++y)
        {
            nodes[y * mapWidth + x].blocked = false;
            nodes[y * mapWidth + x].blockingObject = nullptr;
            nodes[y * mapWidth + x].heat = 0.f;
        }
    }
    for (int x = 0; x < mapWidth; ++x)
    {
        for (int y = 0; y < mapHeight; ++y)
        {
            for (int enemy = 0; enemy < GAME->sizeEnemiesList; ++enemy)
            {
                Vector topLeft = nodeToVector(&nodes[y * mapWidth + x]);
                Vector bottomRight = topLeft;
                topLeft.x -= cellSize / 2;
                topLeft.y += cellSize / 2;
                bottomRight.x += cellSize / 2;
                bottomRight.y -= cellSize / 2;

                if (GAME->gEnemiesList[enemy]->collision.checkForIntersection(topLeft, bottomRight))
                {
                    nodes[y * mapWidth + x].blocked = true;
                    nodes[y * mapWidth + x].blockingObject = GAME->gEnemiesList[enemy];

                    //Generate heat map
                    for (auto neighbour : nodes[y * mapWidth + x].neighbours)
                    {
                        applyHeat(neighbour, 50, nodes[y * mapWidth + x].blockingObject);
                        for (auto secondIt : neighbour->neighbours)
                        {
                            applyHeat(secondIt, 25, nodes[y * mapWidth + x].blockingObject);
                            for (auto thirdIt : neighbour->neighbours)
                            {
                                applyHeat(thirdIt, 10, nodes[y * mapWidth + x].blockingObject);
                            }
                        }
                    }
                }
            }
        }
    }
}
