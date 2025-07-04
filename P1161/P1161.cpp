#include <iostream>
#include <cmath>
using namespace std;
bool f[2000005];
int main() {
    int n;
    cin >> n;
    while (n --) {
        double a;
        int t;
        cin >> a >> t;
        for (int i = 1; i <= t; i ++)
            f[(int)floor(i * a)] = !f[(int)floor(i * a)];
    }
    for (int i = 1; ; i ++) {
        if (f[i]) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}