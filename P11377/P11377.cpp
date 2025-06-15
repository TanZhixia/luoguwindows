#include <iostream>
#include <cstring>
using namespace std;
int t;
int n, P, Q;
int p[105], c[105], dp[105][50005];
int main() {
    cin >> t;
    while (t --) {
        memset(dp, 0, sizeof(dp));
        cin >> n >> P >> Q;
        for (int i = 1; i <= n; i ++)
            cin >> p[i] >> c[i];
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= Q; j ++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= c[i])
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - c[i]] + p[i]);
            }
        }
        bool flag = true;
        for (int i = 1; i <= Q; i ++) {
            if (dp[n][i] >= P) {
                flag = false;
                cout << i << endl;
                break;
            }
        }
        if (flag)
            cout << -1 << endl;
    }
    return 0;
}