#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> g(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }

    vector<long long> dist(n + 1, 1e18);
    vector<int> par(n + 1, -1);

    priority_queue<pair<long long, int>> pq;
    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        long long d = -pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, w] : g[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                par[v] = u;
                pq.push({-dist[v], v});
            }
        }
    }

    if (dist[n] == 1e18) {
        cout << -1;
    } else {
        vector<int> path;
        for (int i = n; i != -1; i = par[i]) {
            path.push_back(i);
        }
        reverse(path.begin(), path.end());
        for (int x : path) cout << x << " ";
    }

    return 0;
}
