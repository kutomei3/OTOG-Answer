#include <bits/stdc++.h>
using namespace std;

bool fuc(string &s, int s_be, int s_size) {
    if (s_be >= s_size) {
        return true;
    }

    if (s[s_be] != s[s_size]) {
        return false;
    }

    return fuc(s, s_be + 1, s_size - 1);
}

int main() {
    string s;

    cin >> s;

    if (fuc(s, 0, s.size() - 1)) {
        cout << "yes";
    } else {
        cout << "no";
    }

    return 0;
}

//two pointer solution
