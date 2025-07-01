#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
int n, r;
vector<int> a;
void dfs(int step) {
    if (step > r) {
        for (int i = 0; i < r; i ++)
            cout << setw(3) << a[i];
        cout << endl;
        return;
    }
    for (int i = a.size() == 0 ? 1 : a.back() + 1; i <= n; i ++) {
        a.push_back(i);
        dfs(step + 1);
        a.pop_back();
    }
}
int main() {
    cin >> n >> r;
    dfs(1);
    return 0;
}