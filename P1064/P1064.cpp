#include <iostream>
#include <algorithm>
using namespace std;
struct node { int id, v, s, f; } a[32005];
int b[32005], dp[32005];
int main() {
    int n, m, v, p, q;
    cin >> n >> m;
    for (int i = 1; i <= m; i ++) {
        cin >> v >> p >> q;
        if (q == 0) {
            a[i].id = i;
            a[i].f = 0;
        } else {
            a[i].id = q;
            a[i].f = ++ b[q];
        }
        a[i].v = v;
        a[i].s = v * p;
    }
    sort(a + 1, a + 1 + m, [](node a, node b) {
        if (a.id == b.id)
            return a.f < b.f;
        return a.id < b.id;
    });
    for (int i = 1; i <= m; i ++) {
        if (a[i].f)
            continue;
        for (int j = n; j >= a[i].v; j --) {
            dp[j] = max(dp[j], dp[j - a[i].v] + a[i].s);
            if (a[i + 1].id == a[i].id && j >= a[i].v + a[i + 1].v)
                dp[j] = max(dp[j], dp[j - a[i].v - a[i + 1].v] + a[i].s + a[i + 1].s);
            if (a[i + 2].id == a[i].id && j >= a[i].v + a[i + 2].v)
                dp[j] = max(dp[j], dp[j - a[i].v - a[i + 2].v] + a[i].s + a[i + 2].s);
            if (a[i + 2].id == a[i].id && j >= a[i].v + a[i + 1].v + a[i + 2].v)
                dp[j] = max(dp[j], dp[j - a[i].v - a[i + 1].v - a[i + 2].v] + a[i].s + a[i + 1].s + a[i + 2].s);  
        }
    }
    cout << dp[n] << endl;
    return 0;
}