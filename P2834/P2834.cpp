#include <iostream>
using namespace std;
long long n, w, a[1005], dp[1005][10005];
long long dfs(int _n, int _w) {
	if (_w == 0) return 1;
	if (_n == 0) return 0;
	if (dp[_n][_w] != -1) return dp[_n][_w];
	if (a[_n] > _w)
		return dfs(_n - 1, _w);
	return dp[_n][_w] = (dfs(_n, _w - a[_n]) + dfs(_n - 1, _w)) % 1000000007;
}
int main() {
	cin >> n >> w;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	for (int i = 0; i <= n; i ++)
		for (int j = 0; j <= w; j ++)
			 dp[i][j] = -1;
	cout << dfs(n, w) << endl;
	return 0;
}