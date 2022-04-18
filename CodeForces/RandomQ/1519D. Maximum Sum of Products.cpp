// Problem: D. Maximum Sum of Products
// Contest: Codeforces - Educational Codeforces Round 108 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1519/D
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
#define rsor(x) sort(x.rbegin(), x.rend())
#define pb push_back

#define forn(i,a,b) for (int i = (a); i < (b); ++i)
#define fors(i,a,b,s) for (int i = (a); i < (b); i+=s)
#define rofn(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define rep(n) for (int _ = 0; _ < n; _++)
#define each(x, a) for (auto& x: a)
#define debug(x) cout << #x << " = " << x << "\n";

const int mod = 1e9+7;
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

void solve(){
	
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vi a(n), b(n);
    each(x, a) cin >> x;
    each(x, b) cin >> x;
    
    vll sum(n);
    sum[0] = 1LL * a[0] * b[0];
    forn(i, 1, n){
    	sum[i] = sum[i-1] + 1LL * a[i] * b[i];
    }
    
    ll ans = sum[n-1];
    forn(i, 0, n-1){
    	ll cnt = 1LL * a[i] * b[i];
    	forn(j, 1, min(i+1, n-i)){
    		// debug(i); debug(j); debug(ans);
    		cnt += 1LL * a[i + j] * b[i - j] + 1LL * a[i - j] * b[i + j];
    		if (i - j == 0){
    			ans = max(ans, cnt + sum[n-1]-sum[i + j]);
    			continue;
    		}
    		ans = max(ans, cnt + sum[i - j - 1] + sum[n-1] - sum[i + j]);
    		
    	}
    	cnt = 0;
    	forn(j, 0, min(i+1, n-i-1)){
    		// debug(i); debug(j); debug(ans); debug(cnt);
    		cnt += 1LL * a[i + j + 1] * b[i - j] + 1LL * a[i - j] * b[i + j + 1];
    		if (i - j == 0){
    			ans = max(ans, cnt + sum[n-1] - sum[i + j + 1]);
    			continue;
    		}
    		ans = max(ans, cnt + sum[i-j-1] + sum[n-1] - sum[i + j + 1]);
    	}
    }
    cout << ans;
}
