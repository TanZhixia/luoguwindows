#include <iostream>
#define int long long
using namespace std;
signed main() {
    int n, m;
    cin >> n >> m;
    int a[100005], d[100005];
    for (int i = 1; i <= 100000; i ++)
        d[i] = 0;
    int last;
    cin >> last;
    m --;
    while (m --) {
        int to;
        cin >> to;
        if (to < last) {
            d[to] ++;
            if (last <= n)
                d[last] --;
            last = to;
            continue;
        }
        d[last] ++;
        if (to <= n)
            d[to] --;
        last = to;
    }
    a[0] = 0;
    for (int i = 1; i <= n; i ++)
        a[i] = a[i - 1] + d[i];
    int ans = 0;
    for (int i = 1; i <= n - 1; i ++) {
        int _a, b, c;
        cin >> _a >> b >> c;
        ans += min(_a * a[i], b * a[i] + c);
    }
    cout << ans << endl;
    return 0;
}