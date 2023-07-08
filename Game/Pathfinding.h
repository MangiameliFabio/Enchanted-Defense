#pragma once
#include <vector>

#include "../Engine/Core/Object.h"

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

    float x;
    float y;

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
    void update() override;

    AStarNode* vectorToNode(const Vector& v) const;
    Vector nodeToVector(const AStarNode* node) const;

    float distance(const AStarNode* node1, const AStarNode* node2) const;
    float heuristic(AStarNode* node1, AStarNode* node2);

    AStarNode* nodes = nullptr;
    int mapWidth = 0;
    int mapHeight = 0;
    float offsetX = 0;
    float offsetY = 0;
    float cellSize = 10;

public:
    Pathfinding(int width_, int height_);
    Pathfinding(int width_, int height_, int offsetX_, int offsetY_);
    
    void init() override;

    ~Pathfinding() override = default;

    bool findPath(Vector& start, Vector& end, std::vector<Vector>& path, const Object* callingObject);

    void applyHeat(AStarNode* node,float heat, Object* heatSrc);
};
