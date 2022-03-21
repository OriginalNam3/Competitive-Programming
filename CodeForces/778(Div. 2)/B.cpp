// Problem: B. Prefix Removals
// Contest: Codeforces - Codeforces Round #778 (Div. 1 + Div. 2, based on Technocup 2022 Final Round)
// URL: https://codeforces.com/contest/1654/problem/B
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
        string s;
        cin >> s;
        vector<int> r(s.size());
        map<char, int> m;
        for (int i = s.size() - 1; i >= 0; i--){
            r[i] = m[s[i]];
            m[s[i]] += 1;
        }
        for (int i = 0; i < s.size(); i++){
            if (r[i] == 0) {
                for (int j = i; j < s.size(); j++){
                    cout << s[j];
                }
                cout << "\n";
                break;
            }
        }
    }
    return 0;
}