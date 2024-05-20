// initialization requires 2cN instructions
// the main loop requires m + 4cN + 4c instructions
// (m for scanf, 4cN for loops, 4c for if/else statements)
// for 1,000,000 iterations this simplefies to O(4,000,000cN)

#include <stdio.h>
#define N 10
int main(void)
{ 
    int i, j, p, q, id[N], sz[N];
    for (i = 0; i < N; i++) {
        id[i] = i;
        sz[i] = 1;
    }
    while (scanf("%d %d\n", &p, &q) == 2) {
        for (i = p; i != id[i] ; i = id[i]);
        for (j = q; j != id[j] ; j = id[j]);
        if (i == j) continue;
        if (sz[i] < sz[j]) {
            id[i] = j;
            sz[j] += sz[i];
        } else { 
            id[j] = i;
            sz[i] += sz[j];
        }
    }
    return 0;
}