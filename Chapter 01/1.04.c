#include <stdio.h>
#define N 10

int main(void)
{
    int i, j, p, q, t, id[N], count;
    for (i = 0; i < N; i++) {
        id[i] = i;
        printf("%d ", id[i]);
    }
    printf("\n");
    while (scanf("%d %d\n", &p, &q) == 2) {
        count = 0;
        if (id[p] == id[q]) {
            count += 2;
            continue;
        }
        for (t = id[p], i = 0; i < N; i++) {
            count++;
            if (id[i] == t) {
                count += 3;
                id[i] = id[q];
                for (j = 0; j < N; j++)
                    printf("%d ", id[j]);
                printf("\n");
            }
        }
        printf("%d-%d, count is %d\n", p, q, count);
    }
    return 0;
}