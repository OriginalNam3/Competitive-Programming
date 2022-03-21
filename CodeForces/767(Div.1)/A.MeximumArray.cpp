// Problem: A. Meximum Array
// Contest: Codeforces - Codeforces Round #767 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1628/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = long double; // or double if tight TL

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

#define f(i,a,b) for (int i = (a); i < (b); ++i)
#define r(i,a,b) for (int i = (b)-1; i >= (a); --i)

int main () {
	ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
    	int n;
    	cin >> n;
    	vi a(n);
    	vi c(n+1, 0);
    	vi o;
    	f(i, 0, n) {
    		cin >> a[i];
    		c[a[i]]++;
    	}
    	
    	int mex = 0;
    	vb b(n+1, 0);
    	f(i, 0, n){
    		b[a[i]] = 1;
    		c[a[i]]--;
    		while (b[mex]) mex++;
    		if (!c[mex]) {
    			o.pb(mex);
    			mex = 0;
    			b.assign(n+1, 0);
    		}
    	}
    	cout << o.size() << "\n";
    	f(i, 0, o.size()) cout << o[i] << " ";
    	cout << "\n";
    }
}
