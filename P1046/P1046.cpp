#include <stdio.h>
int main() {
    int a[10], h;
    for (int i = 0; i < 10; i ++)
        scanf("%d", &a[i]);
    scanf("%d", &h);
    h += 30;
    int count = 0;
    for (int i = 0; i < 10; i ++)
        if (a[i] <= h)
            count ++;
    printf("%d", count);
    return 0;
}