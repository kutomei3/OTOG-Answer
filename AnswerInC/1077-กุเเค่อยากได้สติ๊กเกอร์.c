#include<stdio.h>
#include<stdlib.h>
int n, q;
int max(int a, int b) {
    return a > b ? a : b;
}
int comp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}
int lwb(int arr[], int m) {
    int l = 0;
    int r = n;
    while (r > l) {
        int mid = (r + l) >> 1;
        if (arr[mid] >= m) r = mid;
        else l = mid + 1;
    }
    return l;
}
int upb(int arr[], int m) {
    int l = 0;
    int r = n;
    while (r > l) {
        int mid = (r + l) >> 1;
        if (arr[mid] > m) r = mid;
        else l = mid + 1;
    }
    return l;
}
int main()
{
    scanf("%d %d", &n, &q);
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), comp);
    
    while (q--) {
        int l, r, d;
        scanf("%d %d %d", &l, &r, &d);
        printf("%d\n", max(0, upb(arr, r - d) - lwb(arr, l - d)));
    }
    
    return 0;
}
