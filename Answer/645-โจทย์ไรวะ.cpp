#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    char x;

    cin >> n >> x;

    cout << static_cast<char>(x + n);

    return 0;
}

//who use static_cast?
