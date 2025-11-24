#include <iostream>
#include <vector>
using namespace std;

const int INF = 1000000000;

int main() {
    int n;
    int testCase = 0;

    while (cin >> n) {
        testCase++;
        vector<int> busy(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> busy[i];
        }

        int r;
        cin >> r;
        vector<pair<int, int>> edges;
        for (int i = 0; i < r; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back(make_pair(u, v));
        }

        vector<int> dist(n + 1, INF);
        dist[1] = 0;

        for (int i = 0; i < n - 1; i++) {
            for (auto edge : edges) {
                int u = edge.first;
                int v = edge.second;
                int diff = busy[v] - busy[u];
                int cost = diff * diff * diff;
                if (dist[u] != INF && dist[u] + cost < dist[v]) {
                    dist[v] = dist[u] + cost;
                }
            }
        }

        vector<bool> negativeCycle(n + 1, false);
        for (int i = 0; i < n - 1; i++) {
            for (auto edge : edges) {
                int u = edge.first;
                int v = edge.second;
                int diff = busy[v] - busy[u];
                int cost = diff * diff * diff;
                if (dist[u] != INF && dist[u] + cost < dist[v]) {
                    dist[v] = dist[u] + cost;
                    negativeCycle[v] = true;
                }
            }
        }

        int q;
        cin >> q;
        cout << "Set #" << testCase << endl;
        while (q--) {
            int node;
            cin >> node;

            if (dist[node] < 3 || dist[node] == INF || negativeCycle[node]) {
                cout << "?" << endl;
            } else {
                cout << dist[node] << endl;
            }
        }
    }

    return 0;
}
