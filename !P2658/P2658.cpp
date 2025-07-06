#include <iostream>
#include <cstring>
using namespace std;
int m, n, ans = 0;
int map[505][505];
int dibiao[505][505];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };
int yes[505][505];
int vis[505][505];
void dfs(int x, int y, int mid) {
    for (int i = 0; i < 4; i ++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx <= 0 || xx > m || yy <= 0 || yy > n)
            continue;
        if (vis[xx][yy])
            continue;
        if (abs(map[xx][yy] - map[x][y]) > mid)
            continue;
        vis[xx][yy] = 1;
        dfs(xx, yy, mid);
    }
}
bool check(int mid) {
    memset(yes, 0, sizeof(yes));
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= n; j ++)
            if (dibiao[i][j]) {
                dfs(i, j, mid);
                goto run;
            }
    run:
    for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= n; j ++)
            if (dibiao[i][j] && !yes[i][j])
                return false;
    return true;
}
int main() {
    cin >> m >> n;
    for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= n; j ++)
            cin >> map[i][j];
    for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= n; j ++)
            cin >> dibiao[i][j];
    int left = -1, right = 1e5;
    while (left <= right) {
        int mid = (right - left) / 2;
        if (check(mid)) {
            right = mid - 1;
            ans = mid;
        }
        else
            left = mid + 1;
        cout << mid << endl;
    }
    cout << ans << endl;
    return 0;
}