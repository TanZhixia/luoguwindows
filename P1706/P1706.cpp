#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n, a[10], j = 1;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        a[i] = i, j *= i;
    while (j --) {
        for (int i = 1; i <= n; i ++)
            cout << "    " << a[i];
        cout << endl;
        next_permutation(a + 1, a + 1 + n);
    }
    return 0;
}