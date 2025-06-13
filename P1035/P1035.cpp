#include <stdio.h>
int main() {
    int k;
    double sum = 0;
    int cc = 0;
    scanf("%d", &k);
    do
        sum += 1.0 / ++ cc;
    while (sum <= k);
    printf("%d", cc);
    return 0;
}