#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
int main() {
    int N, L, sum = 0;
    long long c[500], l[500], dp[20001];
    cin >> N >> L;
    for (int i = 0; i < N; i ++) {
        cin >> c[i] >> l[i];
        sum += l[i];
    }
    if (sum < L) {
        cout << "no solution" << endl;
        return 0;
    }
    fill(dp, dp + 20001, INT_MIN);
    dp[0] = 0;
    for (int i = 0; i < N; i ++)
        for (int j = 20000; j >= c[i]; j --)
            if (dp[j - c[i]] != INT_MIN)
                dp[j] = max(dp[j], dp[j - c[i]] + l[i]);
    for (int i = 0; i <= 20000; i ++)
        if (dp[i] >= L) {
            cout << i << endl;
            return 0;
        }
    cout << "no solution" << endl;
    return 0;
}