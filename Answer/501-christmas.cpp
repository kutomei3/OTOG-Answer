#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n + 4; i++) cout << ' ';
    cout << "|\n";
    
    for (int i = 0; i < n + 2; i++) cout << ' ';
    cout << "__*__\n";

    for (int i = 0; i < n + 3; i++) cout << ' ';
    cout << "/|\\\n";

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < n + 2 - i; j++) cout << ' ';
        cout << "/*";
        for (int j = 0; j <= i; j++) cout << " *";
        cout << "\\\n";
    } 

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < 3; j++) {
            for (int p = 0; p < n - i - j; p++) cout << ' ';
            cout << "/*";
            for (int p = 0; p < i + 3 + j; p++) cout << " *";
            cout << "\\\n";
        }
    }

    for (int i = 0; i < n + 3; i++) cout << ' ';
    cout << "|||\n";
    for (int i = 0; i < n + 3; i++) cout << '_';
    cout << "|||";
    for (int i = 0; i < n + 3; i++) cout << '_';

    return 0;    
}

//Happy christmas day yay :)
