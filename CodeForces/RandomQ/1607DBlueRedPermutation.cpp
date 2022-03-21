// Problem: D. Blue-Red Permutation
// Contest: Codeforces - Codeforces Round #753 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1607/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = long double; // or double if tight TL
using str = string;

using pi = pair<int,int>;
#define mp make_pair
#define f first
#define s second

using pqi = priority_queue<int>;
using pqll = priority_queue<long long>;
using qi = queue<int>;
using qll = queue<long long>;
using vi = vector<int>;
using vb = vector<bool>;
using vpi = vector<pi>;

#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define pb push_back

#define fr(i,a,b) for (int i = (a); i < (b); ++i)
#define rf(i,a,b) for (int i = (b)-1; i >= (a); --i)

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
    	int n;
    	cin >> n;
    	
    	vi a(n);
    	fr(i, 0, n) {
    		cin >> a[i];
    	}
    	
    	str br;
    	cin >> br;
    	
    	vi B;
    	vi R;
    	fr(i, 0, n) {
    		if (br[i] == 'B') B.pb(a[i]);
    		else R.pb(a[i]);
    	}
    	
    	sor(B);
    	sor(R);
    	
    	bool ok = true;
    	fr(i, 0, B.size()){
    		if (i + 1 > B[i]) {
    			ok = false;
    		}
    	}
    	rf(i, 0, R.size()) {
    		if (R[i] < 0) continue;
    		if ((n - R.size() + i + 1) < R[i]) {
    			int x = 1;
    			// cout << (n - R.size() + i + 1) << " " << R[i] << " " << R.size() << " " << R.size() * x << "\n";
    			ok = false;
    		}
    	}
    	
    	cout << (ok ? "YES": "NO") << "\n";
    }
}
