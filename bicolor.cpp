#include <bits/stdc++.h>
using namespace std;

bool isBicolorable(int n, vector<vector<int>> &adj) {
    vector<int> color(n, -1);
    queue<int> q;

    for(int start = 0; start < n; start++) {
        if(color[start] != -1) continue;

        color[start] = 0;
        q.push(start);

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            for(int v : adj[u]) {
                if(color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                } else if(color[v] == color[u]) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    while(true) {
        int n;
        cin >> n;
        if(n == 0) break;

        int e;
        cin >> e;

        vector<vector<int>> adj(n);
        for(int i = 0; i < e; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        if(isBicolorable(n, adj)) {
            cout << "BICOLORABLE." << endl;
        } else {
            cout << "NOT BICOLORABLE." << endl;
        }
    }
    return 0;
}
