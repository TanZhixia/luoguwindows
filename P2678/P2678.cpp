#include <iostream>
using namespace std;
int l, n, m;
int d[50005];
int check(int x) {
    int pre = 0;
    int count = 0;
    for (int i = 1; i <= n + 1; i ++) {
        if (d[i] - d[pre] < x)
            count ++;
        else
            pre = i;
    }
    return count;
}
int main() {
    cin >> l >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> d[i];
    d[n + 1] = l;
    int left = 1, right = l;
    while (left < right) {
        int mid = (left + right) / 2;
        if (check(mid) <= m)
            left = mid + 1;
        else
            right = mid - 1;
    }
    if (!(check(left) <= m)) left --;
    cout << left << endl;
    return 0;
}