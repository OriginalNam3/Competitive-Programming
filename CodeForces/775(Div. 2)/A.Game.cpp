#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        int i = 0;
        while (a[i]) i++;
        int j = n - 1;
        while (a[j]) j--;
        if (j >= i) cout << j - i + 2 << endl;
        else cout << 0 << endl;
    }
    return 0;
}
