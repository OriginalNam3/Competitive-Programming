#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int i = 1;
        if (n % 3 == 1){
            i = 0;
        }
        while (n){
            cout << i + 1;
            n -= i + 1;
            i += 1;
            i %= 2;
        }
        cout << endl;
    }
    return 0;
}
