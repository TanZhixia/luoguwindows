#include <iostream>
#include <string>
using namespace std;
int v[35000], ans;
void dfs(int s, int x, int y, int &maxs, int &n, int *a) {
    maxs = max(maxs, s);
    for (int i = y; i <= x && i <= n; i ++)
        dfs(s + a[i], x - i, i, maxs, n, a);
}
int main() {
    string s, goal = "abc";
    int n, m;
    int a[25];
    int c = 0, pv = 0, pos = 0;
    int maxc = 0;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    cin >> m >> s;
    while (true) {
        int x = s.find(goal, pos);
        if (x == -1)
            break;
        if (x - pos == 2 || c == 0) {
            c ++;
            pos = x + 1;
            continue;
        }
        maxc = max(maxc, c);
        v[c] ++;
        c = 1;
        pos = x + 1;
    }
    maxc = max(maxc, c);
    v[c] ++;
    for (int i = 1; i <= maxc; i ++) {
        if (!v[i])
            continue;
        int maxs = 0;
        dfs(0, i, 1, maxs, n, a);
        ans += maxs * v[i];
    }
    cout << ans << endl;
    return 0;
}