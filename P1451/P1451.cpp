#include <iostream>
#include <map>
using namespace std;
int n, m, count = 0;
map<int, string> a;
int f[][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
void dfs(int x, int y) {
    a[x][y] = '0';
    for (int i = 0; i < 4; i ++) {
        int dx = x, dy = y;
        dx += f[i][0];
        dy += f[i][1];
        if (dx >= 1 && dx <= n && dy >= 0 && dy < m && a[dx][dy] != '0')
            dfs(dx, dy);
    }
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (a[i][j] != '0') {
                count ++;
                dfs(i, j);
            }
        }
    }
    cout << count << endl;
    return 0;
}