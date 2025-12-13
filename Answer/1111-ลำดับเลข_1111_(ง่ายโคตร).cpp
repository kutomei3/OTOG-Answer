#include <bits/stdc++.h>
using namespace std;

int lp, la;
vector<int> vis(10002, 0);
vector<int> anu = {0};
void rec(int cl) {
    int s = 0, ind = 0;
    for (int i = 4; i > 0; i--) {
        s += anu[cl - i];
        ind += anu[cl - i];
        if (i != 1) ind *= 10;
    }

    s %= 10;
    anu.push_back(s);

    if (vis[ind]) {
        lp = cl - vis[ind];
        la = vis[ind];
        return;
    }
    else vis[ind] = cl;
    rec(cl + 1);
}

// int ff(string s) {
//     int md = 0;
//     if (s.size() < 6 && stoi(s) < anu.size()) {
//         return anu[stoi(s)];
//     } else {
//         for (int i = 0; i < s.size(); i++) {
//             md = (md * 10 + (s[i] - '0')) % lp;
//         }
//         md -= la;
//     }
//     return anu[(md < 0 ? md + lp : md) + la];
// }

// int n;
// vector<int> ans = {0};
// void findsol(int a, int b, int c, int d, int cl) {
//     int s = a + b + c + d;
//     ans.push_back(s % 10);
//     if (cl != n) findsol(b, c, d, s % 10, cl + 1); 
// }

int main() {
    for (int i = 0; i < 4; i++) {
        int u;
        scanf("%d", &u);
        u %= 10;
        anu.push_back(u);
        // ans.push_back(u);
    }

    string s;
    cin >> s;

    rec(5);
    int md = 0;
    for (int i = 0; i < s.size(); i++) {
        md = (md * 10 + (s[i] - '0')) % lp;
    }
    md -= la;
    printf("%d", anu[(md < 0 ? md + lp : md) + la]);

    // n = 22223;

    // findsol(ans[1], ans[2], ans[3], ans[4], 5);
    // for (int i = 1; i < 22222; i++) {
    //     int a = ans[i];
    //     int b = ff(to_string(i));
    //     if (a != b) {
    //         printf("fuck bro, %d, %d\n", ans[i], ff(to_string(i)));
    //     }
    // }

    // printf("yeah fuck finish");

    return 0;
}

/*
100


*/
