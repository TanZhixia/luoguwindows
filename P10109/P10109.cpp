#include <iostream>
using namespace std;
bool find(int pos, int x, int* f) {
    if (pos != 0 && x == 0) return false;
    if (f[x] == pos) return true;
    return find(pos, f[x], f);
}
bool check(int* f, int* m, int len, int x) {
    for (int i = 0; i < len; i ++)
        if(!find(x, m[i], f) && m[i] != x)
            return false;
    return true;
}
int main() {
    int n, f[300], m[300], len, q;
    cin >> n;
    for (int i = 1; i < n; i ++)
        cin >> f[i];
    cin >> q;
    while (q --) {
        cin >> len;
        for (int i = 0; i < len; i ++)
            cin >> m[i];
        for (int i = n - 1; i >= 0; i --) {
            if (i == 0)
                cout << 0 << endl;
            else if (check(f, m, len, i)) {
                cout << i << endl;
                break;
            }
        }
    }
    return 0; 
}