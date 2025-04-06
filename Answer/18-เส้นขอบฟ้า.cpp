#include<bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(0);

    int n_tower, str, H, ed, re_ed = 0;
    
    cin >> n_tower;
    unordered_map<int, int> all_tower;
    
    for (int i = 0; i < n_tower; i++)
    {
        cin >> str >> H >> ed;
        for (int j = str + 1; j <= ed; j++) all_tower[j] = max(all_tower[j], H);
        re_ed = max(re_ed, ed);
    }
    
    for (int i = 1; i <= re_ed + 1; i++)
    {
        if (all_tower[i] != all_tower[i - 1]) cout << i - 1 << ' ' << all_tower[i] << ' ';
    }
    
    return 0;
}
