#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    string a, p;

    priority_queue<pair<int, string>> all;

    do {
        cin >> a;
        
        if (a == "New") {
            cin >> p >> n;
            all.emplace(n, p);
        } else if (a == "Call") {
            cout << all.top().second << '\n';
            all.pop();
        }
    } while (a != "Exit");

    return 0;
}
