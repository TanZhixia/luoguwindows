#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int m, n, k;
int a[100005], b[100005], r[100005], sum = 0;
vector<int> items[100005];
int getNumber(vector<int> &v, int maxn) {
    sort(v.begin(), v.end(), [](int a, int b) {
        return a > b;
    });
    int count = 0, index = 0;
    do {
        count += v[index ++];
    } while (count < maxn && index < v.size());
    if (count < maxn) {
        cout << -1 << endl;
        exit(0);
    }
    return index;
}
int main() {
    cin >> m >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++)
        cin >> b[i];
    for (int i = 1; i <= n; i ++)
        items[a[i]].push_back(b[i]);
    for (int i = 1; i <= m; i ++)
        r[i] = 0;
    for (int i = 1; i <= m; i ++) {
        int x = getNumber(items[i], k);
        sum += x;
        r[i] = x;
    }
    for (int i = 1; i <= m; i ++) {
        if (sum - r[i] < r[i] - 1) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << sum << endl;
    return 0;
}