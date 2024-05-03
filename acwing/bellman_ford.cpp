#include <iostream>
#include <cstring>
using namespace std;

const int N = 50010, M = 100010;
const int INF = 0x3f3f3f3f;

struct Edge{
    int a,b,c;
} edges[M];

int n,m,k;
int dist[N];
int backup[N];

void bellman_ford(){
    memset(dist,0x3f,sizeof(dist));
    dist[1] = 0;
    for(int i=0;i<k;++i){
        memcpy(backup,dist, sizeof(dist));
        for(int j = 0; j<m; ++j){
            int a = edges[j].a;
            int b = edges[j].b;
            int c = edges[j].c;
            if(backup[a] != INF && backup[a] + c < dist[b]){
                dist[b] = backup[a] + c;
            }
        }
    }
    if (dist[n] == INF) {
        cout << "impossible" << endl;
    } else {
        cout << dist[n] << endl;
    }
}

int main(){
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < m; i ++ )
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edges[i] = {a, b, c};
    }

    bellman_ford();
    return 0;
}