#include <iostream>
#include <queue>
using namespace std;
struct node {
    int x, y;
};
int n, m, x1, y1;
int maze[1005][1005], ans[1005][1005];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };
queue<node> q;
bool check(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}
void bfs() {
    while (!q.empty()) {
        for (int i = 0; i < 4; i ++) {
            int xx = q.front().x + dx[i];
            int yy = q.front().y + dy[i];
            if (maze[xx][yy] == 0 && ans[xx][yy] == -1 && check(xx, yy)) {
                ans[xx][yy] = 0;
                q.push({ xx, yy });
                ans[xx][yy] = ans[q.front().x][q.front().y] + 1;
            }
        }
        q.pop();
    }
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            cin >> maze[i][j];
    cin >> x1 >> y1;
    q.push({ x1, y1 });
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            ans[i][j] = -1;
    ans[x1][y1] = 0;
    bfs();
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}