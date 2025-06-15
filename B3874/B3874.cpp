#include <iostream>
using namespace std;
int n, x, a[300005];
long long ans;
void myAdd(int x) {
    while (x <= n) {
        a[x] ++;
        x += -x&x;
    }
}
int myQuery(int x) {
    int s = 0;
    while (x > 0) {
        s += a[x];
        x -= -x&x;
    }
    return s;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> x;
        myAdd(x + 1);
        ans += myQuery(x);
    }
    cout << ans << endl;
    return 0;
}