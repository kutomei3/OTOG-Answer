#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    stack<int> st;

    int num;
    string com;

    for (int i = 0; i < n; i++) {
        cin >> com;

        if (com == "push") {
            cin >> num;
            st.push(num);
        }
        else {
            if (!st.empty()) {
                cout << st.top() << '\n';
                st.pop();
            }
            else cout << "null" << '\n';
        }
    }

    return 0;
}
