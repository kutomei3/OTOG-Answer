#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    int sum = 0;

    getline(cin, s);

    int s_size = s.size();

    for (int i = 0; i < s_size; i++) {
        char c = s[i];

        if (isalpha(c)) 
            if (islower(c)) sum -= c - 'a';
            else sum += c - 'A';
        else if (isdigit(c)) sum += c - '0';
    }

    cout << sum;

    return 0;
}
