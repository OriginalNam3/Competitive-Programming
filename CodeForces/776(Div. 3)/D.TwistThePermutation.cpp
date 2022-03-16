#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector <int> a(n);
        vector <int> p(n+1);
        for (int i = 0; i < n; i++){
            cin >> a[i];
            p[a[i]] = i;
        }
        vector <int> b(n);
        vector <int> d(n);
        int shift;
        for (int i = n-1; i > 0; i--){
            shift = i - p[i+1];
            for (int j = 0; j < i + 1; j++){
                p[j] += shift;
                p[j] %= i + 1;
            }
            d[i] = (i - shift + 1) % (i + 1);
        }
        for (int i = 0; i < n; i++){
            cout << d[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
