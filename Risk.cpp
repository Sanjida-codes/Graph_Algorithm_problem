#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int bfs(int start, int end, vector<vector<int>>& graph) {
    vector<int> dist(21, INT_MAX);
    queue<int> q;
    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : graph[current]) {
            if (dist[neighbor] == INT_MAX) {
                dist[neighbor] = dist[current] + 1;
                q.push(neighbor);
            }
        }
    }
    return dist[end];
}

int main() {
    int testSet = 1;
    int x, country;

    while (cin >> x) {
        vector<vector<int>> graph(21);

        for (int i = 0; i < x; i++) {
            cin >> country;
            graph[1].push_back(country);
            graph[country].push_back(1);
        }

        for (int i = 2; i <= 19; i++) {
            cin >> x;
            for (int j = 0; j < x; j++) {
                cin >> country;
                graph[i].push_back(country);
                graph[country].push_back(i);
            }
        }

        int n;
        cin >> n;
        cout << "Test Set #" << testSet++ << endl;

        for (int i = 0; i < n; i++) {
            int start, end;
            cin >> start >> end;
            int result = bfs(start, end, graph);
            printf("%2d to %2d: %d\n", start, end, result);
        }
        cout << endl;
    }

    return 0;
}
