#include <iostream>
using namespace std;
int n, k, sum, count;
int a[25];
bool isPrime(int x) {
    for (int i = 2; i * i <= x; i ++)
        if (x % i == 0)
            return false;
    return true;
}
void dfs(int step, int last) {
    if (step > k) {
        if (isPrime(sum))
            count ++;
        return;
    }
    for (int i = last + 1; i <= n; i ++) {
        sum += a[i];
        dfs(step + 1, i);
        sum -= a[i];
    }
}
int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    dfs(1, 0);
    cout << count << endl;
    return 0;
}