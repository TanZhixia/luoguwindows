#include <iostream>
using namespace std;
int n;
int x1, y1, x2, y2, ans = 1e9;
int maze[105][105], vis[105][105];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
void dfs(int x, int y, int step) {
    vis[x][y] = 1;
    if (x == x2 && y == y2) {
        ans = min(ans, step);
        return;
    }
    for (int i = 0; i < 4; i ++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && !maze[nx][ny] && !vis[nx][ny]) {
            dfs(nx, ny, step + 1);
            vis[nx][ny] = 0;
        }
    }
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            cin >> maze[i][j];
    cin >> x1 >> y1 >> x2 >> y2;
    dfs(x1, y1, 1);
    cout << ans << endl;
    return 0;
}