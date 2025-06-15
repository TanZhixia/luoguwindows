#include <iostream>
#include <vector>
using namespace std;
vector<int> t[100005];
int n, a[100005], u, v, ans;
void dfs(int fa, int x) {
    int s = 0;
    for (int i = 0; i < t[x].size(); i ++) {
        if (t[x][i] != fa) {
            dfs(x, t[x][i]);
            s += a[t[x][i]];
        }
    }
    if (s && !a[x]) {
        ans ++;
        a[x] = 1;
    }
    
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++) {
        cin >> u >> v;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    for (int i = 1; i <= n; i ++) {
        if (a[i]) {
            dfs(0, i);
            break;
        }
    }
    cout << ans << endl;
    return 0;
}