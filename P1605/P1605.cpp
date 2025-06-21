#include <iostream>
using namespace std;
int n, m, t, ans;
int x1, y1, x2, y2;
int map[10][10], vis[10][10];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };
void dfs(int x, int y) {
    if (map[x][y])
        return;
    vis[x][y] = 1;
    if (x == x2 && y == y2) {
        ans ++;
        return;
    }
    for (int i = 0; i < 4; i ++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (vis[xx][yy])
            continue;
        if (xx < 1 || xx > n || yy < 1 || yy > m)
            continue;
        dfs(xx, yy);
        vis[xx][yy] = 0;
    }
}
int main() {
    cin >> n >> m >> t;
    cin >> x1 >> y1 >> x2 >> y2;
    while (t --) {
        int x, y;
        cin >> x >> y;
        map[x][y] = 1;
    }
    dfs(x1, y1);
    cout << ans << endl;
    return 0;
}