#include <iostream>
using namespace std;
int n;
int x1, y1, x2, y2, ans = 2e9;
int maze[105][105], vis[105][105];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int road[11025][5], ansR[11025][5];
void dfs(int x, int y, int step) {
    vis[x][y] = 1;
    road[step][0] = x;
    road[step][1] = y;
    if (x == x2 && y == y2) {
        if (step < ans) {
            ans = step;
            for (int i = 1; i <= ans; i ++) {
                ansR[i][0] = road[i][0];
                ansR[i][1] = road[i][1];
            }
        }
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
    for (int i = 1; i <= ans; i ++) {
        cout << "(" << ansR[i][0] << "," << ansR[i][1] << ")";
        if (i < ans)
            cout << "->";
    }
    cout << endl;
    return 0;
}