#include <iostream>
#include <string>
using namespace std;
void long_long_to_string(long long l, string& s) {
    s = "";
    while (l != 0) {
        int r = l % 2;
        l /= 2;
        s += r + '0';
    }
    for (int i = 0, j = s.size() - 1; i < j; i ++, j --)
        swap(s[i], s[j]);
}
void string_to_long_long(string s, long long& l) {
    l = 0;
    long long k = 1;
    for (int i = s.size() - 1; i >= 0; i --) {
        l += (s[i] - '0') * k;
        k *= 2;
    }
}
int main() {
    int n;
    long long start;
    string s;
    cin >> n >> start;
    long_long_to_string(start, s);
    while (n --) {
        char c;
        cin >> c;
        switch (c) {
            case 'U':
                if (s != "1")
                    s.pop_back();
                break;
            case 'L':
                s += '0';
                break;
            case 'R':
                s += '1';
                break;
        }
    }
    long long ans;
    string_to_long_long(s, ans);
    cout << ans << endl;
    return 0;
}