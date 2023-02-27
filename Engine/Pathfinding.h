#pragma once
#include <stack>
#include <vector>

#include "Core/Object.h"
#include "Core/Vector.h"

class GameClock;
class BaseEnemy;
class Object;
class MeasurePerformance;

struct AStarNode
{
    std::vector<AStarNode*> neighbours;

    Object* blockingObject = nullptr;
    Object* heatSrc = nullptr;

    AStarNode* parent = nullptr;

    float globalGoal = INFINITY;
    float localGoal = INFINITY;
    float heat = 0.f;

    int x;
    int y;

    bool blocked = false;
    bool visited = false;

    void reset()
    {
        visited = false;
        globalGoal = INFINITY;
        localGoal = INFINITY;
        parent = nullptr;
    }
};

// Credits to Javidx: https://www.youtube.com/watch?v=icZj67PTFhc
class Pathfinding : public Object
{
    void resetGrid();
    void init();
    void update() override;

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
    Pathfinding(int width_, int height_);
    Pathfinding(int width_, int height_, int offsetX_, int offsetY_);

    ~Pathfinding() override = default;

    bool findPath(Vector& start, Vector& end, std::vector<Vector>& path, const Object* callingObject);

    void applyHeat(AStarNode* node,float heat, Object* heatSrc);
};
