// the initialization takes N instuctions
// the while loop takes 10N instructions
// sum is 11N instructions, gives total instructions
// at 10^9 x 11N. (10^9 * 11 * 10^6) / 10^9 =
// 11 * 10^6 seconds, which is x / (60 * 60 * 24) =
// just over 127 days.

#include <stdio.h>
#define N 10

int main(void)
{
    int i, p, q, t, id[N];
    for (i = 0; i < N; i++) {
        id[i] = i;
    }
    while (scanf("%d %d\n", &p, &q) == 2) {
        if (id[p] == id[q]) {
            continue;
        }
        for (t = id[p], i = 0; i < N; i++) {
            if (id[i] == t) {
                id[i] = id[q];
            }
        }
    }
    return 0;
}