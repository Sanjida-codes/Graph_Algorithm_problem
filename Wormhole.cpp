#include <iostream>
#include <vector>

using namespace std;

struct Wormhole {
    int x, y, t;
};

bool hasNegativeCycle(int n, vector<Wormhole>& wormholes) {
    vector<int> dist(n, 0);

    for (int i = 0; i < n; i++) {
        for (const Wormhole& w : wormholes) {
            if (dist[w.y] > dist[w.x] + w.t) {
                dist[w.y] = dist[w.x] + w.t;
                if (i == n - 1) return true;
            }
        }
    }
    return false;
}

int main() {
    int c;
    cin >> c;

    while (c--) {
        int n, m;
        cin >> n >> m;

        vector<Wormhole> wormholes(m);
        for (int i = 0; i < m; i++) {
            cin >> wormholes[i].x >> wormholes[i].y >> wormholes[i].t;
        }

        if (hasNegativeCycle(n, wormholes)) {
            cout << "possible" << endl;
        } else {
            cout << "not possible" << endl;
        }
    }

    return 0;
}
