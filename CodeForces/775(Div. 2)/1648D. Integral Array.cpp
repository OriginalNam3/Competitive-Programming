#include <bits/stdc++.h>
using namespace std;

int main () {
    int t;
    cin >> t;
    while (t--){
        int n, c;
        cin >> n >> c;
        vector <int> a(c+1);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a[x] = 1;
        }
        bool ok = true;
        int i = 1;
        while (ok && i <= c) {
            if (a[i]) {
                int j = 1;
                while (ok && i * j <= c){
                    if (!a[j]) {
                        for (int k = i * j; k < min(c + 1, i * (j+1)); k++) {
                            if (a[k]) {
//                                cout << i << " " << j << " " << k << "\n";
                                ok = false;
                                break;
                            }
                        }
                    }
                    j++;
                }
            }
            i++;
        }
        if (ok) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}
