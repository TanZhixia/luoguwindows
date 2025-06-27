#include <iostream>
#include <vector>
using namespace std;
int n, maxn;
int a[25];
vector<int> map[25];
vector<int> road, ans;
void dfs(int node, int num) {
    if (num + a[node] > maxn) {
        maxn = num + a[node];
        ans = road;
        ans.push_back(node);
    }
    for (int i = 0; i < map[node].size(); i ++) {
        if (map[node][i] <= node)
            continue;
        road.push_back(node);
        dfs(map[node][i], num + a[node]);
        road.pop_back();
    }
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++) {
        for (int j = i + 1; j <= n; j ++) {
            int x;
            cin >> x;
            if (x) {
                map[i].push_back(j);
                map[j].push_back(i);
            }
        }
    }
    for (int i = 1; i <= n; i ++)
        dfs(i, 0);
    for (int i = 0; i < ans.size(); i ++)
        cout << ans[i] << " ";
    cout << endl;
    cout << maxn << endl;
    return 0;
}