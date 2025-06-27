#include <iostream>
using namespace std;
int N, M;
int s[25], t[25], c[25];
int a[15], b[15], p[15], m[15];
int map[105], ans = 1e9;
bool check()
{
    for (int i = 1; i <= N; i++)
        for (int j = s[i]; j <= t[i]; j++)
            if (map[j] > 0)
                return false;
    return true;
}
void dfs(int num, int sum)
{
    if (check())
        ans = min(ans, sum);
    if (num > M)
        return;
    dfs(num + 1, sum);
    for (int i = a[num]; i <= b[num]; i++)
        map[i] -= p[num];
    dfs(num + 1, sum + m[num]);
    for (int i = a[num]; i <= b[num]; i++)
        map[i] += p[num];
}
int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> s[i] >> t[i] >> c[i];
        for (int j = s[i]; j <= t[i]; j++)
            map[j] += c[i];
    }
    for (int i = 1; i <= M; i++)
        cin >> a[i] >> b[i] >> p[i] >> m[i];
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}