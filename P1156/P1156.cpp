#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
struct node {
    int t, f, h;
} a[105];
int d, n, ans1 = 1e9, ans2 = 0;
map<int, map<int, map<int, bool>>> dp;
void dfs(int t, int h, int pos) {
    if (h >= d) {
        ans1 = min(ans1, a[pos - 1].t);
        return;
    }
    if (pos > n || t < a[pos].t) {
        ans2 = max(ans2, t);
        return;
    }
    if (dp[t][h][pos])
        return;
    dp[t][h][pos] = true;
    dfs(t, h + a[pos].h, pos + 1);
    dfs(t + a[pos].f, h, pos + 1);
}
int main() {
    cin >> d >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].t >> a[i].f >> a[i].h;
    sort(a + 1, a + 1 + n, [](node a, node b) {
        return a.t < b.t;
    });
    dfs(10, 0, 1);
    if (ans1 == 1e9) {
        cout << ans2 << endl;
        return 0;
    }
    cout << ans1 << endl;
    return 0;
}