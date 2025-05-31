#include <iostream>
#include <vector>
using namespace std;
int vis[10], a[10], b[10];
vector<int> indexs;
int length = 1000000000;
void dfs(int n, int step = 1) {
    if (step == n + 1) {
        int l = 1;
        for (int i = 1; i < n; i ++) {
            int index = indexs[i];
            int ai = a[index];
            int bi = b[indexs[i - 1]];
            l += max(ai, bi) + 1;
        }
        length = min(length, l);
        return;
    }
    for (int i = 1; i <= n; i ++) {
        if (vis[i])
            continue;
        indexs.push_back(i);
        vis[i] = 1;
        dfs(n, step + 1);
        indexs.pop_back();
        vis[i] = 0;
    }
}
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++)
        cin >> b[i];
    dfs(n);
    cout << length << endl;
    return 0;
}