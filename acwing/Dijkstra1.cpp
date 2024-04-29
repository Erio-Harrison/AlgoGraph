#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;
struct Edge{
    int to, cost;
    Edge(int t, int c): to(t), cost(t){}
};

int dijkstra1(int n, vector<vector<Edge>>& graph) {
    vector<int> dist(n + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[1] = 0;
    pq.push({0, 1});  // cost, node

    while (!pq.empty()) {
        auto [cost, u] = pq.top();
        pq.pop();

        if (cost > dist[u]) continue;

        for (auto& e : graph[u]) {
            int v = e.to;
            int weight = e.cost;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist[n] == INT_MAX ? -1 : dist[n];
}

/*
 int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        graph[x].push_back({y, z});
    }

    cout << dijkstra(n, graph) << endl;

    return 0;
}
*/