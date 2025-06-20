#include <iostream>
#include <vector>
using namespace std;
struct road {
    int x, l;
};
int n, m, ans;
vector<road> map[25];
bool vis[25];
void dfs(int node, int dis = 0) {
    ans = max(ans, dis);
    vis[node] = true;
    for (int i = 0; i < map[node].size(); i ++)
        if (!vis[map[node][i].x]) {
            vis[map[node][i].x] = true;
            dfs(map[node][i].x, dis + map[node][i].l);
            vis[map[node][i].x] = false;
        }
}
int main() {
    cin >> n >> m;
    while (m --) {
        int a, b, l;
        cin >> a >> b >> l;
        map[a].push_back( {b, l} );
        map[b].push_back( {a, l} );
    }
    for (int i = 1; i <= n; i ++) {
        dfs(i);
        for (int i = 1; i <= n; i ++)
            vis[i] = false;
    }
    cout << ans << endl;
    return 0;
}