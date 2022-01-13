#include<iostream>
#include<queue>

using namespace std;
int dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int vis[301][301];
int tt, n, cx, cy, ex, ey;
 
void bfs(int x, int y) {
    queue<pair<int, int>> q;
    vis[x][y] = 1;
    q.push({ x, y });
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (vis[nx][ny]) continue;
            q.push({ nx, ny });
            vis[nx][ny] = vis[x][y] + 1;
        }
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tt;
    while (tt--) {
        cin >> n;
        cin >> cx >> cy;
        cin >> ex >> ey;
        memset(vis, 0, sizeof(vis));
        bfs(cx, cy);
        cout << vis[ex][ey] - 1 << '\n';
    }
}
