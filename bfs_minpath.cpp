#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> mat;
#define INF 2<<22;

int n, m;

int bfs(mat adj, int src, int dest, int v) { 
    list<int> queue; 
    bool visited[n+5];
    int dist[n+5];

    for (int i=0; i<n+5; i++) dist[i] = INT_MAX;
    for (int i=0; i<n+5; i++) visited[i] = false;

    for (int i = 0; i < v; i++) { 
        visited[i] = false; 
        dist[i] = INT_MAX; 
    } 
  
    visited[src] = true; 
    dist[src] = 0; 
    queue.push_back(src); 
  
    // standard BFS algorithm 
    while (!queue.empty()) { 
        int u = queue.front(); 
        queue.pop_front(); 
        for (int i = 0; i < adj[u].size(); i++) { 
            if (visited[adj[u][i]] == false) { 
                visited[adj[u][i]] = true; 
                dist[adj[u][i]] = dist[u] + 1; 
                queue.push_back(adj[u][i]); 
  
                // We stop BFS when we find 
                // destination. 
                if (adj[u][i] == dest) {
                //    for (int i=1; i<=n; i++) cout << dist[i] << " ";
                //    cout << endl;
                   return dist[dest]; 
                }
            } 
        } 
    }

    // for (int i=1; i<=n; i++) cout << dist[i] << " ";
    // cout << endl;
    return -1; 
} 

int main(){
    
}
