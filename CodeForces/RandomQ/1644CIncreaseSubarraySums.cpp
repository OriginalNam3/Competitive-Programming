// Problem: C. Increase Subarray Sums
// Contest: Codeforces - Educational Codeforces Round 123 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1644/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double db;
typedef string str;

#define mp make_pair
#define f first
#define s second

typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<bool> vb;
typedef vector<pi> vpi;
typedef array<int, 3> qq;

#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define pb push_back

#define fr(i,a,b) for (int i = (a); i < (b); ++i)
#define rf(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define each(x, a) for (auto& x: a)

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--){
    	int n, x;
    	cin >> n >> x;
    	vi a(n);
    	each (x, a) cin >> x;
    	vi ans(n);
    	fr(i, 1, n+1){
    		int sum = 0;
    		fr(j, 0, i){
    			sum += a[j];
    		}
    		ans[i-1] = sum;
    		fr(j, i, n){
    			sum += a[j];
    			sum -= a[j-i];
    			ans[i-1] = max(ans[i-1], sum);
    		}
    	}
    	// each(x, ans){
    		// cout << x << " ";
    	// }
    	// cout << "\n";
    	fr(k, 0, n+1){
    		ll m = 0;
    		fr(i, 0, n){
    			m = max(m, 1LL * ans[i] + min(i+1, k) * x);
    		}
    		cout << m << " ";
    	}
    	cout << "\n";
    }
}
