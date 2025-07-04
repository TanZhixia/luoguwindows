#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    for (double i = -100; i <= 100; i += 0.001) {
        double j = i + 0.001;
        double y1 = a * i * i * i + b * i * i + c * i + d;
        double y2 = a * j * j * j + b * j * j + c * j + d;
        if (y1 <= 0 && y2 >= 0 || y1 >= 0 && y2 <= 0)
            cout << fixed << setprecision(2) << (i + j) / 2 << " ";
    }
    cout << endl;
    return 0;
}