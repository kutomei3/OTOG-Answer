#include <bits/stdc++.h>
#include "council.h"
using namespace std;

int giveAnswer(int n, int m, int q) {
    int ans = 1;
    int ct = 1;
    for (int i = 2; i <= n; ++i) {
        if (ct == 0) {
            ans = i;
            ct = 1;
        } else {
            if (sameVote(ans, i)) ct++;
            else ct--;
        }
    }
    return ans;
}
