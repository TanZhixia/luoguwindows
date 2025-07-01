#include <iostream>
using namespace std;
int n, m, a[10][10], vis[10][10], ans, sum;
int d[][2] = {
    {-1, -1},
    {-1, 0},
    {-1, 1},
    {0, 1},
    {1, 1},
    {1, 0},
    {1, -1},
    {0, -1}
};
void dfs(int x, int y) {
    if (x == n + 1 && y == m)
    {
        ans = max(ans, sum);
        return;
    }
    if (x == n + 1)
        return dfs(1, y + 1);
    dfs(x + 1, y);
    if (vis[x][y])
        return;
    sum += a[x][y];
    for (int i = 0; i < 8; i ++)
        if (x + d[i][0] <= n && y + d[i][1] <= m)
            vis[x + d[i][0]][y + d[i][1]] ++;
    dfs(x + 1, y);
    for (int i = 0; i < 8; i ++)
        if (x + d[i][0] <= n && y + d[i][1] <= m)
            vis[x + d[i][0]][y + d[i][1]] --;
    sum -= a[x][y];
}
int main() {
    int t;
    cin >> t;
    while (t --) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];
        sum = ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                vis[i][j] = 0;
        dfs(1, 1);
        cout << ans << endl;
    }
    return 0;
}