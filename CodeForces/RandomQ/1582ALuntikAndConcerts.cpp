#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--){
        int a, b, c;
        cin >> a >> b >> c;
        int ans = 0;
        if (c % 2){
            a -= 1;
            if (b > 1 && b % 2 == 0) b -= 2;
            else b -= 1;
        }
        if (a != 0){
            ans = a % 2;
        }
        else {
            ans = 2 * (b % 2);
        }
        cout << ans << endl;
    }
    return 0;
}
