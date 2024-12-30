#include <bits/stdc++.h>
using namespace std;

int n;

void pl(int t, char c)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < t; j++) {
            cout << c;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        pl(25, '.');
        cout << '\n';
    }

    for (int i = 0; i < n; i++) {
        pl(2, '.');
        pl(3, '#');
        pl(2, '.');
        pl(5, '#');
        pl(2, '.');
        pl(3, '#');
        pl(3, '.');
        pl(4, '#');
        pl(1, '.');
        cout << '\n';
    }

    for (int i = 0; i < n; i++) {
        pl(1, '.');
        pl(1, '#');
        pl(3, '.');
        pl(1, '#');
        pl(3, '.');
        pl(1, '#');
        pl(3, '.');
        pl(1, '#');
        pl(3, '.');
        pl(1, '#');
        pl(1, '.');
        pl(1, '#');
        pl(5, '.');
        cout << '\n';
    }

    for (int i = 0; i < n; i++) {
        pl(1, '.');
        pl(1, '#');
        pl(3, '.');
        pl(1, '#');
        pl(3, '.');
        pl(1, '#');
        pl(3, '.');
        pl(1, '#');
        pl(3, '.');
        pl(1, '#');
        pl(1, '.');
        pl(1, '#');
        pl(1, '.');
        pl(3, '#');
        pl(1, '.');
        cout << '\n';
    }

    for (int i = 0; i < n; i++) {
        pl(1, '.');
        pl(1, '#');
        pl(3, '.');
        pl(1, '#');
        pl(3, '.');
        pl(1, '#');
        pl(3, '.');
        pl(1, '#');
        pl(3, '.');
        pl(1, '#');
        pl(1, '.');
        pl(1, '#');
        pl(3, '.');
        pl(1, '#');
        pl(1, '.');
        cout << '\n';
    }

    for (int i = 0; i < n; i++) {
        pl(2, '.');
        pl(3, '#');
        pl(4, '.');
        pl(1, '#');
        pl(4, '.');
        pl(3, '#');
        pl(3, '.');
        pl(3, '#');
        pl(2, '.');
        cout << '\n';
    }

    for (int i = 0; i < n; i++) {
        pl(25, '.');
        cout << '\n';
    }

    return 0;
}
