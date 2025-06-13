#include <iostream>
using namespace std;
int main() {
    int n, w;
    int money[1005], dp[10005];
    cin >> n >> w;
    for (int i = 1; i <= n; i ++)
        cin >> money[i];
    dp[0] = 1;
    for (int i = 1; i <= w; i ++) {
        dp[i] = 0;
        for (int j = 1; j <= n; j ++)
            if (i - money[j] >= 0) {
                dp[i] += dp[i - money[j]];
                dp[i] %= 1000000007;
            }
    }
    cout << dp[w] << endl;
    return 0;
}