#include <iostream>
using namespace std;
int n, k;
int h[100005], w[100005];
bool cmp(int x, int val) {
	int count = 0;
	for (int i = 1; i <= n; i ++)
		count += (h[i] / x) * (w[i] / x);
	return count >= val;
}
template<typename Cmp>
int search(int left, int right, Cmp cmp) {
    while (left <= right) {
        int mid = (left + right) / 2;
        if (cmp(mid, k))
            left = mid + 1;
        else
            right = mid - 1;
    }
    return right;
}
int main() {
	int right = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) {
		cin >> h[i] >> w[i];
		right = max(right, min(h[i], w[i]));
	}
    cout << search(1, right, cmp) << endl;
	return 0;
}