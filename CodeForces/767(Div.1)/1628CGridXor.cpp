#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector <vector<int>> a(n, vector<int> (n));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cin >> a[i][j];
            }
        }

        int ans = 0;
        if (n % 4 == 0){
            for (int i = 0; i < n / 2; i += 2){
                for (int j = i + 1; j < n - i - 1; j += 4){
                    ans ^= a[i][j] ^ a[i][j + 1];
                    ans ^= a[j + 1][i] ^ a[j + 2][i];
                    ans ^= a[j + 1][n - i - 1] ^ a[j + 2][n - i - 1];
                    if (i > 0){
                        ans ^= a[n - i + 1][j] ^ a[n - i + 1][j + 1];
                    }
                }
            }
        }
        else {
            for (int i = 0; i < n / 2; i += 2){
                for (int j = i; j < n - i; j += 4){
                    ans ^= a[i][j];
                    ans ^= a[i][j + 1];
                    if (i > 0){
                        ans ^= a[j + 1][i - 2] ^ a[j + 2][i - 2];
                        ans ^= a[j + 1][n - i + 1] ^ a[j + 2][n - i + 1];
                        ans ^= a[n - i + 1][j] ^ a[n - i + 1][j + 1];
                    }
                }
            }
        }
        
        cout << ans << "\n";
    }
}
