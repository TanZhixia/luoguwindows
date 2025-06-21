#include <iostream>
using namespace std;
int n;
int map[35][35], vis[35][35];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };
void dfs(int x, int y) {
    if (map[x][y] == 1)
        return;
    vis[x][y] = 1;
    map[x][y] = 2;
    for (int i = 0; i < 4; i ++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx < 1 || xx > n || yy < 1 || yy > n)
            continue;
        if (!vis[xx][yy])
            dfs(xx, yy);
    }
}
int convert(int x) {
    if (x == 0)
        return 2;
    if (x == 2)
        return 0;
    return 1;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            cin >> map[i][j];
    for (int i = 1; i <= n; i ++) {
        dfs(i, 1);
        dfs(i, n);
        dfs(1, i);
        dfs(n, i);
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++)
            cout << convert(map[i][j]) << " ";
        cout << endl;
    }
    return 0;
}