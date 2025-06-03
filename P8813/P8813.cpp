#include <iostream>
using namespace std;
const long long MAX = 1000000000;
void pd(long long x) {
    if (x > MAX) {
        cout << -1 << endl;
        exit(0);
    }
}
long long pow(long long a, long long b) {
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    long long ans = pow(a, b / 2);
    pd(ans);
    ans *= ans;
    pd(ans);
    if (b & 1) {
        ans *= a;
        pd(ans);
    }
    pd(ans);
    return ans;
}
int main() {
    int a, b;
    cin >> a >> b;
    cout << pow(a, b) << endl;
    return 0;
}