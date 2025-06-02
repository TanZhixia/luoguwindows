#include <iostream>
#include <vector>
using namespace std;
class Node {
    public:
        bool val;
        bool biaoji = false;
        vector<Node*> chi;
        void fanzhuan() {
            biaoji = !biaoji;
        }
        void zhengli(bool bi = false) {
            if (this->biaoji != bi) {
                val = !val;
                this->biaoji = false;
                for (int i = 0; i < chi.size(); i ++)
                    chi[i]->zhengli(true);
            } else {
                this->biaoji = false;
                for (int i = 0; i < chi.size(); i ++)
                    chi[i]->zhengli();
            }
        }
};
Node tree[100005];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 2; i <= n; i ++) {
        int x;
        cin >> x;
        tree[x].chi.push_back(&tree[i]);
    }
    for (int i = 1; i <= n; i ++) {
        char c;
        cin >> c;
        if (c == '1')
            tree[i].val = true;
        else
            tree[i].val = false;
    }
    int q;
    cin >> q;
    while (q --) {
        int a;
        cin >> a;
        tree[a].fanzhuan();
    }
    tree[1].zhengli();
    for (int i = 1; i <= n; i ++)
        cout << tree[i].val;
    cout << endl;
    return 0;
}