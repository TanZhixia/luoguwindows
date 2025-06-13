#include <stdio.h>
int main() {
    int l, m;
    int trees[10000];
    scanf("%d%d", &l, &m);
    for (int i = 0; i <= l; i ++)
        trees[i] = 1;
    for (int i = 0; i < m; i ++) {
        int a, b;
        scanf("%d%d", &a, &b);
        for (int j = a; j <= b; j ++)
            trees[j] = 0;
    }
    int count = 0;
    for (int i = 0; i <= l; i ++)
        if (trees[i])
            count ++;
    printf("%d", count);
    return 0;
}