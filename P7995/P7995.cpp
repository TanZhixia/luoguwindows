#include <iostream>
using namespace std;
int n, k, cnt;
bool a[55][55];
int dx[] = { 0, 1 };
int dy[] = { 1, 0 };
void dfs(int x, int y, int w, int s) {
    if (s > k)
        return;
    if (x == n && y == n) {
        cnt ++;
        return;
    }
    if (s == k && x != n && y != n)
        return;
    for (int i = 0; i < 2; i ++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (a[xx][yy]) {
            if (i == w || (x == 1 && y == 1))
                dfs(xx, yy, i, s);
            else
                dfs(xx, yy, i, s + 1);
        }
    }
}
int main() {
    int t;
    cin >> t;
    while (t --) {
        cnt = 0;
        cin >> n >> k;
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= n; j ++) {
                char c;
                cin >> c;
                a[i][j] = false;
                if (c == '.')
                    a[i][j] = true;
            }
        }
        dfs(1, 1, 1, 0);
        cout << cnt << endl;
    }
}