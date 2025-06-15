#include <iostream>
using namespace std;
int t, m;
int a[10005], b[10005];
long long dp[10000005];
int main() {
    cin >> t >> m;
    for (int i = 1; i <= m; i ++)
        cin >> a[i] >> b[i];
    for (int i = 1; i <= t; i ++)
        for (int j = 1; j <= m; j ++)
            if (i >= a[j])
                dp[i] = max(dp[i], dp[i - a[j]] + b[j]);
    cout << dp[t] << endl;
    return 0;
}