#include <stdio.h>
#define N 10

int main(void)
{
    int i, j, k, p, q, t, id[N], count;
    for (i = 0; i < N; i++) {
        id[i] = i;
        printf("%d ", id[i]);
    }
    printf("\n");
    while (scanf("%d %d\n", &p, &q) == 2) {
        count = 0;
        for (i = p; i != id[i]; i = id[i])
            count += 2;
        for (j = q; j != id[j]; j = id[j])
            count += 2;
        if (i == j) continue;
        id[i] = j;
        count++;
        for (k = 0; k < N; k++)
            printf("%d ", id[k]);
        printf("\n");
        printf("%d-%d, count is %d\n", p, q, count);
    }
    return 0;
}