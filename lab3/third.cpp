#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

typedef pair<int, int> pii; 

void dijkstra(vector<vector<pii>>& graph, vector<vector<int>>& dist, int start) {
    int n = graph.size();
    dist[start][start] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int node = pq.top().second;
        int distance = pq.top().first;
        pq.pop();

        if (distance > dist[start][node]) {
            continue;
        }

        for (const auto& neighbor : graph[node]) {
            int nextNode = neighbor.first;
            int nextDist = neighbor.second;

            if (dist[start][node] + nextDist < dist[start][nextNode]) {
                dist[start][nextNode] = dist[start][node] + nextDist;
                pq.push({dist[start][nextNode], nextNode});
            }
        }
    }
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<pii>> graph(n + 1);  
    for (int i = 0; i < m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight});
    }

    vector<vector<int>> dist(n + 1, vector<int>(n + 1, numeric_limits<int>::max()));
    for (int i = 1; i <= n; i++) {
        dijkstra(graph, dist, i);
    }

    for (int i = 0; i < q; i++) {
        int start, end;
        cin >> start >> end;

        if (dist[start][end] == numeric_limits<int>::max()) {
            cout << -1 << endl;
        } else {
            cout << dist[start][end] << endl;
        }
    }

    return 0;
}
