#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

typedef pair<int, int> pii;  // pair of node and distance

void dijkstra(vector<vector<pii>>& graph, vector<int>& dist, int start) {
    int n = graph.size();
    dist[start] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int node = pq.top().second;
        int distance = pq.top().first;
        pq.pop();

        // Skip if the distance is already larger than the current value in dist[]
        if (distance > dist[node]) {
            continue;
        }

        for (const auto& neighbor : graph[node]) {
            int nextNode = neighbor.first;
            int nextDist = neighbor.second;

            // Relax the edge if a shorter path is found
            if (dist[node] + nextDist < dist[nextNode]) {
                dist[nextNode] = dist[node] + nextDist;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }
}

int main() {
    int n, m,q;
    cin >> n >> m>>q;

    vector<vector<pii>> graph(n + 1);  // 1-indexed adjacency list representation
    for (int i = 0; i < m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight});
    }

    

    for(int i=0;i<q;i++){
        vector<int> dist(n + 1, numeric_limits<int>::max());
        int start,end;
        cin>>start>>end;
        dijkstra(graph,dist,start);
        cout<<dist[end]<<endl;

    }
    
      // initialize distances to infinity
    


    return 0;
}
