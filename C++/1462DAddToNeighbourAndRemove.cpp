#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> a(n, 0);
        vector<int> b(n, 0);
        cin >> a[0];
        b[0] = a[0];
        for (int i = 1; i < n; i++) {
            cin >> a[i];
            b[i] = b[i-1] + a[i];
        }
        
        for (int i = 0; i < n; i++) {
            int x = i;
            int c = n-1;
            bool ok = true;
            while (ok & (x < n-1)) {
                ok = false;
                for (int j = x+1; j < n; j++){
                    if (b[j]-b[x] == b[i]){
                        x = j;
                        c -= 1;
                        ok = true;
                        break;
                    }
                    if (b[j]-b[x] > b[i]) break;
                }
            }
            if (ok){
                cout << c << endl;
                break;
            }
        }
    }
    return 0;
}
