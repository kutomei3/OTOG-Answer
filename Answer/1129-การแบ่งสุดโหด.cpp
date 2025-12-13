#include <stdio.h>
int min(int a, int b) {
    return a < b ? a : b;
}
int main()
{
    int n, mi = 10000002;
    scanf("%d", &n);
    
    int arr[mi];
    for (int i = 0; i < mi; i++) arr[i] = 0;
    for (int i = 0; i < n; i++) {
        int u;
        scanf("%d", &u);
        arr[u]++;
    }

    if (!arr[0]) printf("%d %d", 0, n);
    else {
        int k = n;
        for (int i = 0; i < mi; i++) {
            if (!arr[i]) {
                printf("%d %d", i, k);
                break;
            }
            k = min(k, arr[i]);
        }
    }
    
    return 0;
}

/*
10000001
*/
