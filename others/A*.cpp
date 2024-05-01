#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

struct Node {
    int x, y;
    int cost; // This is g(n)
    int priority; // This is f(n)

    Node(int x, int y, int cost, int priority) : x(x), y(y), cost(cost), priority(priority) {}

    // This is needed to prioritize the node with the lowest f(n) in the priority queue
    bool operator>(const Node& other) const {
        return priority > other.priority;
    }
};

class AStar {
public:
    AStar(int width, int height) : width(width), height(height) {
        grid.resize(height, vector<int>(width, 0));
    }

    void addObstacle(int x, int y) {
        grid[y][x] = 1;
    }

    bool isValid(int x, int y) {
        return (x >= 0 && y >= 0 && x < width && y < height && grid[y][x] == 0);
    }

    int heuristic(int x, int y, int targetX, int targetY) {
        // Manhattan distance
        return abs(x - targetX) + abs(y - targetY);
    }

    vector<pair<int, int>> findPath(int startX, int startY, int targetX, int targetY) {
        priority_queue<Node, vector<Node>, greater<Node>> nodes;
        nodes.emplace(startX, startY, 0, heuristic(startX, startY, targetX, targetY));
        vector<vector<bool>> visited(height, vector<bool>(width, false));
        vector<vector<pair<int, int>>> parent(height, vector<pair<int, int>>(width, {-1, -1}));

        while (!nodes.empty()) {
            Node current = nodes.top();
            nodes.pop();

            if (current.x == targetX && current.y == targetY) {
                return reconstructPath(parent, targetX, targetY);
            }

            if (visited[current.y][current.x]) continue;
            visited[current.y][current.x] = true;

            for (auto [dx, dy] : vector<pair<int, int>>{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}) {
                int nx = current.x + dx, ny = current.y + dy;
                if (isValid(nx, ny) && !visited[ny][nx]) {
                    int newCost = current.cost + 1;
                    int priority = newCost + heuristic(nx, ny, targetX, targetY);
                    nodes.emplace(nx, ny, newCost, priority);
                    parent[ny][nx] = {current.x, current.y};
                }
            }
        }
        // return empty path if no path found
        return {};
    }

private:
    int width, height;
    vector<vector<int>> grid;

    vector<pair<int, int>> reconstructPath(vector<vector<pair<int, int>>>& parent, int targetX, int targetY) {
        vector<pair<int, int>> path;
        for (pair<int, int> at = {targetX, targetY}; at.first != -1; at = parent[at.second][at.first]) {
            path.push_back(at);
        }
        reverse(path.begin(), path.end());
        return path;
    }
};

int main() {
    AStar astar(10, 10);
    astar.addObstacle(5, 5);
    astar.addObstacle(5, 6);
    astar.addObstacle(5, 7);

    auto path = astar.findPath(0, 0, 9, 9);
    for (auto [x, y] : path) {
        cout << "(" << x << ", " << y << ")" << endl;
    }

    return 0;
}
