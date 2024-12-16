#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int row, col, q, x, y;

    cin >> row >> col >> q;
    char arr[row][col];

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> arr[i][j];
        }
    }

    while (q--) {
        cin >> x >> y;
        cout << arr[x][y] << '\n';
    }

    return 0;
}
