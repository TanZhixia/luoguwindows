#include <iostream>
#include <vector>
using namespace std;
int n, vis[105], sign[105];
vector<int> a[105];
void dfs(int node)
{
    vis[node] = 1;
    for (int i = 0; i < a[node].size(); i++)
    {
        if (vis[a[node][i]])
            continue;
        dfs(a[node][i]);
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int ai, bi;
        cin >> ai >> bi;
        a[ai].push_back(bi);
    }
    for (int i = 1; i <= n; i++)
        sign[i] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int i = 0; i < 105; i++)
            vis[i] = 0;
        dfs(i);
        for (int i = 1; i <= n; i++)
            sign[i] &= vis[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (sign[i])
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}