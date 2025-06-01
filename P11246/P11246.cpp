#include <iostream>
using namespace std;
int main() {
    int n;
    int p[400], dp[100005];
    cin >> n;
    for (int i = 1; i < 400; i ++)
        p[i] = i * i;
    dp[0] = 0;
    for (int i = 1; i <= n; i ++) {
        dp[i] = i;
        for (int j = 1; p[j] <= i; j ++)
            dp[i] = min(dp[i], dp[i - p[j]] + 1);
    }
    cout << dp[n] << endl;
    return 0;
}