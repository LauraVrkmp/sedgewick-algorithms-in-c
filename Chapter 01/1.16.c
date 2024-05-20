// incorrect

#include <stdio.h>
#define N 10
#define MAXN 1000

int id[MAXN];
int sz[MAXN];

int findRoot(int x);

int main(void)
{ 
    int i, j, k, p, q;
    for (i = 0; i < N; i++) {
        id[i] = i;
        sz[i] = 1;
        printf("%d ", id[i]);
    }
    printf("\n");
    while (scanf("%d %d\n", &p, &q) == 2) {
        int rootP = findRoot(p);
        int rootQ = findRoot(q);
        if (rootP != rootQ) {
            if (sz[rootP] < sz[rootQ]) {
                id[rootP] = rootQ;
                sz[rootQ] += sz[rootP];
            }
            else {
                id[rootQ] = rootP;
                sz[rootP] += sz[rootQ];
            }
        }
        for (k = 0; k < N; k++)
            printf("%d ", k);
        printf("\n");
        for (k = 0; k < N; k++)
            printf("%d ", findRoot(id[k]));
        printf("\n");
        for (k = 0; k < N; k++)
            printf("%d ", sz[k]);
        printf("\n");
        printf("%d-%d\n" , p, q);
    }
    return 0;
}

int findRoot(int x) {
    if (x != id[x]) {
        id[x] = findRoot(id[x]);
    }
    return id[x];
}