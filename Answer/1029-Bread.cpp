#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    
    int a[n], b[n];
    for (auto& p : a) scanf("%d", &p);
    for (auto& p : b) scanf("%d", &p);
    
    vector<int> lef, vis(n, 0);
    int p = 0;
    for (int i = 0; i < n; i++) {
        if (p == n) break;
        if (a[i] == b[p]) printf("%d\n", a[i]);
        else lef.push_back(a[i]);
        vis[a[i]] = 1;
        while (p != n && vis[b[p]]) p++;
    }
    
    for (int i = lef.size() - 1; i >= 0; i--) printf("%d\n", lef[i]);
    
    return 0;
}

/*
5 
0 2 4 1 3 
4 0 3 1 2

0 2 4 1 3 3 1 4 2 0

*/
