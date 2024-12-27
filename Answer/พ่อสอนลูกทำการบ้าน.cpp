#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n1, n2;
    char o;

    cin >> n1 >> o >> n2;

    if (o == '+') cout << n1 + n2;
    else if (o == '-') cout << n1 - n2;
    else if (o == '*') cout << n1 * n2;
    else if (o == '/') cout << n1 / n2;

    return 0;
}

//if you cant do this your cooked bro 💀
