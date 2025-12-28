#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> a(n), x(n);
    for (auto& p : a) cin >> p;
    for (auto& p : x) cin >> p;

    for (int i = n - 1; i >= 0; i--) {
        if (a[i]) continue;
        
        if (k >= x[i]) {
            a[i] = 1;
            k -= x[i];
        }
    }

    unsigned long long sum = 0;
    for (int i = 0; i < n; i++) 
        if (a[i]) {
            unsigned long long mul = 1;
            for (int j = 0; j < i; j++) mul *= 2;
            
            sum += mul;
        }

    cout << sum;

    return 0;    
}

//greedy solution -> can be proved
