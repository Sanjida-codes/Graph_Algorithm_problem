#include <bits/stdc++.h>
using namespace std;

int bfs(pair<int,int> start, pair<int,int> end) {
    if(start == end) return 0;
    vector<vector<int>> moves = {{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
    vector<vector<int>> dist(8, vector<int>(8, -1));
    queue<pair<int,int>> q;
    q.push(start);
    dist[start.first][start.second] = 0;
    while(!q.empty()) {
        auto u = q.front(); q.pop();
        for(auto m: moves) {
            int x = u.first + m[0], y = u.second + m[1];
            if(x>=0 && x<8 && y>=0 && y<8 && dist[x][y]==-1) {
                dist[x][y] = dist[u.first][u.second] + 1;
                if(make_pair(x,y) == end) return dist[x][y];
                q.push({x,y});
            }
        }
    }
    return -1;
}

pair<int,int> toIndex(string s) {
    return {s[0]-'a', s[1]-'1'};
}

int main() {
    string a, b;
    while(cin >> a >> b) {
        auto start = toIndex(a);
        auto end = toIndex(b);
        int moves = bfs(start, end);
        cout << "To get from " << a << " to " << b << " takes " << moves << " knight moves." << endl;
    }
}
