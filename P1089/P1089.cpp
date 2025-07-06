#include <iostream>
using namespace std;
int main() {
    int n = 0, t = 0;
    for (int i = 1; i <= 12; i ++) {
        n += 300;
        int x;
        cin >> x;
        if (n >= x) {
            n -= x;
            t += n / 100 * 100;
            n -= n / 100 * 100;
            continue;
        }
        cout << -i << endl;
        return 0;
    }
    cout << n + t * 1.2 << endl;
}