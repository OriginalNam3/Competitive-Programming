#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--){
        int n;
        long long m = 0;
        cin >> n;
        long long a[n];
        for (int i = 0; i < n; i++){
            cin >> a[i];
            if (a[i] > m) m = a[i];
        }
        if (!m) cout << 0 << endl;
        else{
            sort(a, a+n);
            long long balls = a[n-1];
            for (int i = n - 2; i >= 0; i--){
                balls -= a[i];
            }
            if (balls > 1) cout << balls << endl;
            else cout << 1 << endl;
        }
    }
    return 0;
}
