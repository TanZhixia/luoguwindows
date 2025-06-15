#include <iostream>
#include <algorithm>
using namespace std;
struct node {
    int p, c;
} a[100005];
struct car {
    int a, b;
} b[100005];
int n, m, x;
long long ans;
int main() {
    cin >> n >> m >> x;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].p >> a[i].c;
    for (int i = 1; i <= m; i ++)
        cin >> b[i].a >> b[i].b;
    sort(a + 1, a + 1 + n, [] (node a, node b) {
        return a.p < b.p;
    });
    sort(b + 1, b + 1 + m, [] (car a, car b) {
        return a.a - a.b > b.a - b.b;
    });
    int i = 1, j = 1;
    for (; b[i].a >= b[i].b; i ++) {
        if (!a[j].c)
            j ++;
        ans += 2ll * b[i].a * a[j].p + 2ll * b[i].b * (x - a[j].p);
        a[j].c --;
    }
    int p = m, q = n;
    for (; p >= i; p --) {
        if (!a[q].c)
            q --;
        ans += 2ll * b[p].a * a[q].p + 2ll * b[p].b * (x - a[q].p);
        a[q].c --;
    }
    cout << ans << endl;
    return 0;
}