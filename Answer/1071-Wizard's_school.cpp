/**
 * Author: Ohmusan
 * lang: C
**/

#include <stdio.h>
int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    int pfs[101][500002] = {};
    for (int i = 1; i <= n; i++) {
        int u;
        scanf("%d", &u);
        pfs[u][i]++;
        for (int j = 0; j < 101; j++) {
            pfs[j][i] += pfs[j][i - 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < 101; j++) {
            pfs[j][i] += pfs[j - 1][i];
        }
    }
    while (q--) {
        int l, r, x;
        scanf("%d %d %d", &l, &r, &x);
        if (x != 0) printf("%d\n", pfs[x - 1][r + 1] - pfs[x - 1][l]);
        else printf("%d\n", 0);
    }
    return 0;
}
