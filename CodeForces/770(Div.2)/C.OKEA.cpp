#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--){
        int n, k;
        cin >> n >> k;
        if (n % 2 && k != 1) cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            for (int i = 1; i <= n; i ++){
                for (int j = i; j <= n * k; j += n) cout << j << " ";
                cout << endl;
            }
        }
    }
    return 0;
}
