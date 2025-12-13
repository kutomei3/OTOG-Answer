#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int dmg_i[n + 1];
    vector<int> hp_range(1000001, 0);
    
    int sum_dmg = 0;
    for (int i = 1; i <= n; i++) {
        int hp_i;
        cin >> hp_i >> dmg_i[i];
        sum_dmg += dmg_i[i];
        hp_range[hp_i] = i; //เลือดเท่านี้เป็นของคนที่ i
    }

    long long all_dmg = 0, last_survivor;
    for (int i = 1000000; i >= 0; i--) {
        if (hp_range[i] != 0) {
            all_dmg += sum_dmg;
            last_survivor = hp_range[i];
            int new_hp = i / 2;
            if (new_hp < 10 || hp_range[new_hp] != 0) {
                sum_dmg -= dmg_i[hp_range[i]];
            }    
            else hp_range[new_hp] = hp_range[i]; //ปรับเลือดคนที่ i
        }
    }

    cout << all_dmg << ' ' << last_survivor;

    return 0;
}

/*
สามารถใช้ set เเก้ได้เเต่จะเมาโค้ดได้ง่าย -.-
วิธีนี้ไล่เลือดจากบนลงล่าง (สังเกตว่าเลือดจะลดลงเสมอ)
ซึ่งจะทำให้เขียนได้ง่ายกว่า :D
*/
