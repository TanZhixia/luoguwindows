#include <iostream>
#include <climits>
using namespace std;
int main() {
    int n, w;
    int money[1005], dp[10005];
    cin >> n >> w;
    for (int i = 1; i <= n; i ++)
        cin >> money[i];
    dp[0] = 0;
    for (int i = 1; i <= w; i ++) {
        dp[i] = INT_MAX;
        for (int j = 1; j <= n; j ++)
            if (i - money[j] >= 0 && dp[i - money[j]] != INT_MAX)
                dp[i] = min(dp[i], dp[i - money[j]] + 1);
    }
    cout << dp[w] << endl;
    return 0;
}