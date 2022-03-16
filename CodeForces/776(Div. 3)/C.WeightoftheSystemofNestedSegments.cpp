#include<bits/stdc++.h>
using namespace std;

struct p{
    int x, w, ind;
};

bool weightsort (p a, p b){
    return a.w < b.w;
}

bool coordsort (p a, p b){
    return a.x < b.x;
}

int main() {
    int t;
    cin >> t;
    while (t--){
        int n, m;
        cin >> n >> m;
        vector<p> a(m);
        for (int i = 0; i < m; i++){
            cin >> a[i].x >> a[i].w;
            a[i].ind = i + 1;
        }
        
        sort(a.begin(), a.end(), weightsort);
        
        int ans = 0;
        for (int i = 0; i < n * 2; i++) ans += a[i].w;
        cout << ans << endl;
        
        sort(a.begin(), a.begin() + (2 * n), coordsort);
        for (int i = 0; i < n; i++){
            cout << a[i].ind << " " << a[2 * n - 1 - i].ind << endl;
        }
    }
    return 0;
}
