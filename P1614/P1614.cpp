#include <iostream>
using namespace std;
int main() {
    int n, m, a[3005];
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    int minx = 1e9;
    for (int i = 1; i <= n - m + 1; i ++) {
        int sum = 0;
        for (int j = 0; j < m; j ++)
            sum += a[i + j];
        minx = min(minx, sum);
    }
    cout << minx << endl;
    return 0;
}