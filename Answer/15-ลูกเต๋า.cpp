#include <bits/stdc++.h>
using namespace std;

vector<int> rot(char c, vector<int> &dice)
{
    vector<int> dt = dice;
    if (c == 'F') dice = {dt[3], dt[0], dt[2], dt[5], dt[4], dt[1]};
    if (c == 'B') dice = {dt[1], dt[5], dt[2], dt[0], dt[4], dt[3]};
    if (c == 'L') dice = {dt[4], dt[1], dt[0], dt[3], dt[5], dt[2]};
    if (c == 'R') dice = {dt[2], dt[1], dt[5], dt[3], dt[0], dt[4]};
    if (c == 'C') dice = {dt[0], dt[4], dt[1], dt[2], dt[3], dt[5]};
    if (c == 'D') dice = {dt[0], dt[2], dt[3], dt[4], dt[1], dt[5]};

    return dice;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(0);

    int n_dice;
    string ro_way;

    cin >> n_dice;
    int ans[n_dice];

    for (int i = 0; i < n_dice; i++)
    {
        vector<int> dice = {1, 2, 3, 5, 4, 6};

        cin >> ro_way;

        for (const char &c : ro_way)
        {
            dice = rot(c, dice);
        }

        ans[i] = dice[1];
    }

    for (int i = 0; i < n_dice; i++)
    {
        cout << ans[i] << ' ';
    }

    return 0;
}
