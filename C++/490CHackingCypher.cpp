#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int a, b;
    cin >> a >> b;
    long n = s.size();
    int left[n];
    left[0] = (s[0] - '0') % a;
    for (int i = 1; i < n; i++){
        left[i] = ((left[i-1] * 10) + (s[i] - '0')) % a;
    }
    int right = (s[n-1] - '0') % b;
    int lright;
    int p = 1;
    bool found = false;
    for (int i = 2; i < n+1; i++) {
        if (right == 0 & left[n-i] == 0 & s[n-i+1] != '0'){
            cout << "YES" << endl;
            cout << s.substr(0, n - i + 1) << endl;
            cout << s.substr(n - i + 1, n-1) << endl;
            found = true;
            exit(0);
        }
        p *= 10;
        p %= b;
        lright = right;
        right = (lright + (p * (s[n-i] - '0'))) % b;
    }
    cout << "NO";
    return 0;
}
