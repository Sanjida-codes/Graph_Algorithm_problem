#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int case_num = 1; case_num <= T; case_num++) {
        int n, m;
        cin >> n >> m;

        vector<vector<pair<int, int>>> graph(n + 1);

        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        vector<int> dist1(n + 1, INF);
        vector<int> dist2(n + 1, INF);

        dist1[1] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 1});

        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            if (d > dist2[u]) continue;

            for (auto &edge : graph[u]) {
                int v = edge.first;
                int w = edge.second;
                int new_dist = d + w;

                if (new_dist < dist1[v]) {
                    dist2[v] = dist1[v];
                    dist1[v] = new_dist;
                    pq.push({new_dist, v});
                }
                else if (new_dist > dist1[v] && new_dist < dist2[v]) {
                    dist2[v] = new_dist;
                    pq.push({new_dist, v});
                }
            }
        }

        cout << "Case " << case_num << ": " << dist2[n] << "\n";
    }

    return 0;
}
