// Problem: A. Maximum Cake Tastiness
// Contest: Codeforces - Codeforces Round #778 (Div. 1 + Div. 2, based on Technocup 2022 Final Round)
// URL: https://codeforces.com/contest/1654/problem/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--){
        int n, fmax = 0, smax = 0;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] >= fmax) {
                smax = fmax;
                fmax = a[i];
            }
            else if (a[i] >= smax){
                smax = a[i];
            }
        }
        cout << fmax + smax << "\n";
    }
    return 0;
}
