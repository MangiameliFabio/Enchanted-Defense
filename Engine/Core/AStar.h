#pragma once
#include <stack>
#include <vector>

#include "Vector.h"

// Credits to Javidx: https://www.youtube.com/watch?v=icZj67PTFhc
struct AStarNode
{
    bool blocked = false;
    bool visited = false;
    float globalGoal = INFINITY;
    float localGoal = INFINITY;
    int x;
    int y;
    std::vector<AStarNode*> neighbours;
    AStarNode* parent = nullptr;

    void reset()
    {
        blocked = false;
        visited = false;
        globalGoal = INFINITY;
        localGoal = INFINITY;
        parent = nullptr;
    }
};

class AStar
{
    void resetGrid();
    void init();

    AStarNode* vectorToNode(Vector& v);
    Vector nodeToVector(AStarNode* node);

    float distance(AStarNode* node1, AStarNode* node2);
    float heuristic(AStarNode* node1, AStarNode* node2);

    AStarNode* nodes = nullptr;
    int mapWidth = 0;
    int mapHeight = 0;
    int offsetX = 0;
    int offsetY = 0;
    int cellSize = 10;

public:
    AStar(int width_, int height_);
    AStar(int width_, int height_, int offsetX_, int offsetY_);
    ~AStar();

    bool findPath(Vector& start, Vector& end, std::stack<Vector>& path);
};
