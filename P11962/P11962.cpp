#include <iostream>
#include <vector>
using namespace std;
int vis[200005], number[3];
vector<int> a[200005];
void dfs(int node, int step) {
    if (step == 0) {
        number[2] ++;
        vis[node] = 2;
    } else {
        number[(step - 1) % 2 + 1] ++;
        vis[node] = (step - 1) % 2 + 1;
    }
    for (int i = 0; i < a[node].size(); i ++) {
        if (vis[a[node][i]])
            continue;
        dfs(a[node][i], step + 1);
    }
}
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n - 1; i ++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i ++)
        cout << number[vis[i]] << " ";
    cout << endl;
    return 0;
}