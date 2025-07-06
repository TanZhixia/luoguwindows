#include <iostream>
#include <iomanip>
using namespace std;
int n;
int x[200005], y[200005], z[200005];
bool check(double mid) {
    long double last = 0;
    for (int i = 1; i <= n; i ++) {
        double time = z[i] / mid;
        last += time;
        if (last > y[i])
            return false;
        if (x[i] > last)
            last = x[i];
    }
    return true;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> x[i] >> y[i] >> z[i];
    double left = 0.000001;
    double right = 1e9;
    while (right - left >= 0.000001) {
        double mid = (left + right) / 2;
        if (check(mid))
            right = mid;
        else
            left = mid;
    }
    cout << fixed << setprecision(2);
    cout << right << endl;
    return 0;
}