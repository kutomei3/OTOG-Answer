#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int row, col, q;
    long long sum = 0;
    int bug = 0;

    cin >> row >> col >> q;

    int arr[row][col];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> arr[i][j];
        }
    }

    while (q--) {
        int rowc, colc;
        char c;

        cin >> rowc >> colc >> c;

        if (c == 'U') rowc--;
        else if (c == 'D') rowc++;
        else if (c == 'L') colc--;
        else if (c == 'R') colc++;

        if (rowc >= 0 && rowc < row && colc >= 0 && colc < col) 
            sum += arr[rowc][colc];
        else bug++;
    }

    cout << sum << ' ' << bug;

    return 0;
}
