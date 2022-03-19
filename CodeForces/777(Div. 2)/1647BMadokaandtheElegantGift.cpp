#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--){
        int n, m;
        cin >> n >> m;
        int a[n][m];
        bool ok = true;
        for (int i = 0; i < n; i++) {
            string row;
            cin >> row;
            for (int j = 0; j < m; j++) {
                if (row[j] == '1') a[i][j] = 1;
                else a[i][j] = 0;
            }
        }
        if (n == 1 || m == 1){
            cout << "YES" << endl;
            continue;
        }
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m - 1; j++){
                if (a[i][j] + a[i+1][j] + a[i][j+1] + a[i+1][j+1] == 3) ok = false;
            }
        }
        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
