#include <bits/stdc++.h>
using namespace std;

#define int long long

bool can(int arr[], int mid, int k, int n)
{
    int ct = 0;
    priority_queue<int> d;
    priority_queue<int, vector<int>, greater<int>> u;
    int sd = 0, su = 0;
    for (int i = 0; i < n; i++) {
        if (!d.size() || !u.size()) {
            if (!u.size()) u.push(arr[i]), su += arr[i];
            else {
                if (u.top() >= arr[i]) d.push(arr[i]), sd += arr[i];
                else {
                    su -= u.top();
                    sd += u.top();
                    d.push(u.top());
                    u.pop();
                    su += arr[i];
                    u.push(arr[i]);
                } 
            }
        }
        else if (d.size() == u.size()) {
            if (d.top() >= arr[i]) {
                d.push(arr[i]);
                sd += arr[i];
                sd -= d.top();
                su += d.top();
                u.push(d.top());
                d.pop();
            } else {
                u.push(arr[i]);
                su += arr[i];
            }
        } else {
            if (u.top() <= arr[i]) {
                u.push(arr[i]);
                su += arr[i];
                su -= u.top();
                sd += u.top();
                d.push(u.top());
                u.pop();
            } else {
                d.push(arr[i]);
                sd += arr[i];
            }
        }
        if (d.size()) {
            int c = false;
            if ((d.size() + u.size()) & 1) {if (su - sd - u.top() >= mid) c = true;}
            else if (su - sd >= mid) c = true;
            if (c) {
                ct++;
                while (d.size()) d.pop();
                while (u.size()) u.pop();
                su = sd = 0;
            }
        }
    }

    return ct < k;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int arr[n];
    for (auto& p : arr) cin >> p;

    int l = 1;
    int r = 1e16;
    while (r > l) {
        int mid = (r + l) >> 1;
        if (can(arr, mid, k, n)) r = mid;
        else l = mid + 1;
    }

    cout << l - 1;

    return 0;
}

/*
5 2
1 2 3 4 5

*/
