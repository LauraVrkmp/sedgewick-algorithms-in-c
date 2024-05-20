#include <stdio.h>
#define N 10
int main(void)
{ 
    int i, j, k, p, q, id[N], sz[N], count;
    for (i = 0; i < N; i++) {
        id[i] = i;
        sz[i] = 1;
        printf("%d ", id[i]);
    }
    printf("\n");
    while (scanf("%d %d\n", &p, &q) == 2) {
        count = 0;
        for (i = p; i != id[i] ; i = id[i])
            count += 2;
        for (j = q; j != id[j] ; j = id[j])
            count += 2;
        if (i == j) continue;
        if (sz[i] < sz[j]) {
            id[i] = j;
            sz[j] += sz[i]; 
            count += 4;
            for (k = 0; k < N; k++)
                printf("%d ", id[k]);
        } else { 
            id[j] = i;
            sz[i] += sz[j];
            count += 4;
            for (k = 0; k < N; k++)
                printf("%d ", id[k]);
        }
        printf("\n");
        printf("%d-%d, count: %d\n" , p, q, count);
    }
    return 0;
}