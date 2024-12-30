#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
            
    int n, m, q;
    cin >> n >> m >> q;

    vector<array<int, 3>> all;

    int x, y, d;
    while (q--)
    {
        cin >> x >> y >> d;
        all.push_back({x, y, d});
    }

    vector<pair<int, int>> apos;

    int sx = all[0][0], sy = all[0][1];
    int df = all[0][2];

    for (int i = 0; i < df; i++) 
    {
        int x = df - i;
        int y = i;

        apos.push_back({sx + x, sy + y});
        apos.push_back({sx + y * -1, sy + x});
        apos.push_back({sx + x * -1, sy + y * -1});
        apos.push_back({sx + y, sy + x * -1});

        //BIG W for complex number :O
    }

    for (auto& p : apos) 
    {
        int sd = abs(all[1][0] - p.first) + abs(all[1][1] - p.second);
        int td = abs(all[2][0] - p.first) + abs(all[2][1] - p.second);
        int fd = abs(all[3][0] - p.first) + abs(all[3][1] - p.second);
        //greedy -> who want binary search?

        if (sd == all[1][2] && td == all[2][2] && fd == all[3][2]) {
            cout << p.first << ' ' << p.second; 
            break;
        }
    }

    return 0;
}

//bad testcase lol
