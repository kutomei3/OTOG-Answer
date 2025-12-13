#include <stdio.h>
#include <ctype.h>
#define int long long
int min(int a, int b) {
    return a < b ? a : b;
}
char s[27000002], *t = "GOLD";
signed main()
{
    int ind = 0, cur = 0;
    scanf("%s", s);
    int ct[26] = {0};
    int n = strlen(s), ans = 0, m = 0;
    for (int i = 0; i < n; i++) {
        if (!isalpha(s[i])) break;
        ct[s[i] - 'A']++;
        if (s[i] == t[ind]) {
            ind += (ind == 3 ? -3 : 1);
            if (!ind) cur++, m++, ans += 4 - (m - 1) * (m - 2) + m * (m - 1);
        }    
        else {
            for (int j = 0; j < 4; j++)
                if (s[i] == t[j]) ind = 0, m = 0;
            if (s[i] == 'G') ind = 1;    
        }
    }
    int ext = 1e9;
    for (int i = 0; i < 4; i++) {
        ext = min(ct[t[i] - 'A'] - cur, ext);
    }
    printf("%lld", ans + ext);
    return 0;
}
