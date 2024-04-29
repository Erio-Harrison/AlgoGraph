#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;
/*
 * Firstly, we need to store the input numbers into graph
 * In graph, we have a vector to store all nodes and every node has a vector which means their paths(Edge(to, cost))
 *
 * Use priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int,int>>>
 * Because we always begin from the shortest path Init: Begin from node1 which has 0 cost
 * Use dist[n] to store the current cost for node n
 *
 * The top one should be the shortest path, we use this then pop it, which means we already go through
 * Only when the current node's cost plus path's cost is smaller than next node's cost, we update the next node's cost
 *
 * Notice there is an improvement: if the cost is already larger than the dist[node], ignore this path
 *
 * */
struct Edge{
    int to, cost;
    Edge(int t, int co): to(t), cost(co){}
};

void addEdge(vector<vector<Edge>>& graph,int x, int y, int z){
    graph[x].push_back(Edge(y,z));
}

int dijkstra2(int n, vector<vector<Edge>> graph){
    vector<int> dist(n+1,INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int,int>>>  pq;
    dist[1] = 0;
    pq.push({0,1});

    while(!pq.empty()){
        auto [cost,node] = pq.top();
        pq.pop();

        if (cost > dist[node]) continue;
        for(auto & edge : graph[node]){
            int to = edge.to;
            int cost = edge.cost;

            if(dist[node] + cost < dist[to]){
                dist[to] = dist[node] + cost;
                pq.push({dist[to],to});
            }
        }
    }

    return dist[n] == INT_MAX ? -1 : dist[n];
}

/*
int main(){
    cout << "Please input n and m: " << endl;
    int n,m;
    cin >> n >> m;

    vector<vector<Edge>> graph(n+1);
    cout<<"please input three numbers which mean begin node, end node and cost: " << endl;
    for(int i=0; i<m; i++){
        int x,y,z;
        cin >> x >> y >> z;
        addEdge(graph,x,y,z);
    }
    cout << dijkstra2(n,graph) << endl;
}
 */