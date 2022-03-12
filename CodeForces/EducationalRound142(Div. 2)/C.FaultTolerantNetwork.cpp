#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        long long a[n], b[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        long long la = INT_MAX, lb = INT_MAX, ra = INT_MAX, rb = INT_MAX;
        for (int j = 1; j < n-1; j++){
            if (abs(a[0]-b[j]) < la) la = abs(a[0]-b[j]);
            if (abs(b[0]-a[j]) < lb) lb = abs(b[0]-a[j]);
            if (abs(a[n-1]-b[j]) < ra) ra = abs(a[n-1]-b[j]);
            if (abs(b[n-1]-a[j]) < rb) rb = abs(b[n-1]-a[j]);
        }
        long long ans = min(min(abs(a[0] - b[0]), la + lb) + min(abs(a[n-1] - b[n-1]), ra + rb), min(abs(a[0] - b[n-1]), la + rb) + min(abs(a[n-1] - b[0]), ra + lb));
        ans = min(ans, abs(a[0] - b[0]) + abs(a[0] - b[n-1]) + ra);
        ans = min(ans, abs(a[n-1] - b[0]) + abs(a[n-1] - b[n-1]) + la);
        ans = min(ans, abs(a[0] - b[0]) + abs(a[n-1] - b[0]) + rb);
        ans = min(ans, abs(a[0] - b[n-1]) + abs(a[n-1] - b[n-1]) + lb);
        cout << ans << endl;
    }
}
