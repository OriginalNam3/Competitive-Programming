#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--){
        int n, k;
        cin >> n >> k;
        vector <int> x(n);
        for (int &i: x) cin >> i;
        for (int i = 0; i < n; i++){
            int y;
            cin >> y;
        }
        sort(x.begin(), x.end());
        
        vector <int> r(n), l(n);
        int j = n - 1;
        for (int i = n-1; i >= 0; i--){
            while (x[j] - x[i] > k) j--;
            r[i] = j - i + 1;
            if (i < n - 1) {
                r[i] = max(r[i], r[i+1]);
            }
        }
        
        j = 0;
        for (int i = 0; i < n; i++){
            while (x[i] - x[j] > k) j++;
            l[i] = i - j + 1;
            if (i > 0) {
                l[i] = max(l[i], l[i - 1]);
            }
        }
        
        int ans = 1;
        for (int i = 0; i < n-1; i++){
            ans = max(ans, r[i+1] + l[i]);
        }
        
        cout << ans << "\n";
    }
    return 0;
}
