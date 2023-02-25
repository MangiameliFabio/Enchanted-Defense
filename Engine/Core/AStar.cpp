#include "AStar.h"

#include <list>
#include <stack>

AStar::AStar(int width_, int height_)
{
    mapWidth = width_;
    mapHeight = height_;

    init();
}

AStar::AStar(int width_, int height_, int offsetX_, int offsetY_)
{
    mapWidth = width_;
    mapHeight = height_;
    offsetX = offsetX_;
    offsetY = offsetY_;

    init();
}

AStarNode* AStar::vectorToNode(Vector& v)
{
    const int x = (static_cast<int>(v.x) - offsetX) / cellSize;
    const int y = (static_cast<int>(v.y) - offsetX) / cellSize;

    return &nodes[y * mapWidth + x];
}

Vector AStar::nodeToVector(AStarNode* node)
{
    const float x = (node->x + 0.5f) * cellSize + offsetX;
    const float y = (node->y + 0.5f) * cellSize + offsetY;

    return Vector(x, y);
}

float AStar::distance(AStarNode* node1, AStarNode* node2)
{
    return abs(sqrt((node1->x - node2->x) * (node1->x - node2->x) + (node1->y - node2->y) * (node1->y - node2->y)));
}

float AStar::heuristic(AStarNode* node1, AStarNode* node2)
{
    //Maybe I need to make a few changes for the heuristic
    return distance(node1, node2);
}

bool AStar::findPath(Vector& start, Vector& end, std::stack<Vector>& path)
{
    //setup starting conditions
    resetGrid();

    AStarNode* nodeStart = vectorToNode(start);
    AStarNode* nodeEnd = vectorToNode(end);

    nodeStart->localGoal = 0.f;
    nodeStart->globalGoal = heuristic(nodeStart, nodeEnd);

    std::list<AStarNode*> listOpenNodes;
    listOpenNodes.push_back(nodeStart);

    while (!listOpenNodes.empty())
    {
        // Sort Untested nodes by global goal, so lowest is first
        listOpenNodes.sort([](const AStarNode* a, const AStarNode* b)
        {
            return a->globalGoal < b->globalGoal;
        });
        // Front of listNotTestedNodes is potentially the lowest distance node. Our
        // list may also contain nodes that have been visited, so ditch these...
        while (!listOpenNodes.empty() && listOpenNodes.front()->visited)
            listOpenNodes.pop_front();
        // ...or abort because there are no valid nodes left to test
        if (listOpenNodes.empty())
            break;

        AStarNode* nodeCurrent = listOpenNodes.front();
        nodeCurrent->visited = true; //Only explore node once

        //Check neighbours
        for (auto neighbour : nodeCurrent->neighbours)
        {
            // ... and only if the neighbour is not visited and is 
            // not an obstacle, add it to NotTested List
            if (!neighbour->visited && !neighbour->blocked)
                listOpenNodes.push_back(neighbour);
            // Calculate the neighbours potential lowest parent distance
            float possiblyLowerGoal = nodeCurrent->localGoal + distance(nodeCurrent, neighbour);

            // If choosing to path through this node is a lower distance than what 
            // the neighbour currently has set, update the neighbour to use this node
            // as the path source, and set its distance scores as necessary
            if (possiblyLowerGoal < neighbour->localGoal)
            {
                neighbour->parent = nodeCurrent;
                neighbour->localGoal = possiblyLowerGoal;

                // The best path length to the neighbour being tested has changed, so
                // update the neighbour's score. The heuristic is used to globally bias
                // the path algorithm, so it knows if its getting better or worse. At some
                // point the algo will realise this path is worse and abandon it, and then go
                // and search along the next best path.
                neighbour->globalGoal = neighbour->localGoal + heuristic(neighbour, nodeEnd);
            }
        }
        if (nodeCurrent == nodeEnd)
        {
            AStarNode* p = nodeEnd;
            while (p->parent != nullptr)
            {
                path.push(nodeToVector(p));
                // Set next node to this node's parent
                p = p->parent;
            }

            return true;
        }
    }
    return false;
}

void AStar::resetGrid()
{
    for (int x = 0; x < mapWidth; ++x)
    {
        for (int y = 0; y < mapHeight; ++y)
        {
            nodes[y * mapWidth + x].reset();
        }
    }
}

void AStar::init()
{
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
