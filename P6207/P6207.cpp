#include <iostream>
using namespace std;
int n, m;
int x1, y1, x2, y2;
char maze[200][200];
int vis[200][200];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int road[41025][5];
bool flag = false;
void dfs(int x, int y, int step) {
    if (flag)
        return;
    vis[x][y] = 1;
    road[step][0] = x;
    road[step][1] = y;
    if (x == x2 && y == y2) {
        flag = true;
        for (int i = 1; i <= step; i ++)
            cout << road[i][0] << " " << road[i][1] << endl;
        return;
    }
    for (int i = 0; i < 4; i ++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && maze[nx][ny] == '.' && !vis[nx][ny])
            dfs(nx, ny, step + 1);
    }
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            cin >> maze[i][j];
    x1 = 1, y1 = 1, x2 = n, y2 = m;
    dfs(x1, y1, 1);
    return 0;
}