// Problem: D. Progressions Covering
// Contest: Codeforces - Educational Codeforces Round 126 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1661/problem/D
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

const int mod = 1e9+7;
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

void solve(){
	
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    vll b(n);
    forn(i, 0, n){
    	cin >> b[i];
    }
    ll cur = 0, ans = 0, s = 0;
    vll c(n);
    rofn(i, 0, n){
    	s -= c[i];
    	// cout << b[i] << " " << i << " " << cur << " " << s << "\n";
    	if (b[i] > cur){
    		ll a = (b[i]-cur) / min(i + 1, k);
    		if ((b[i]-cur) % min(i+1, k) > 0) a++;
    		// cout << a << " " << i << "\n";
    		cur += a * min(i+1, k);
    		// cout << i << " pushed\n";
    		if (i-k >= 0) c[i-k] += a;
    		s += a;
    		ans += a;
    	}
    	cur -= s;
    }
    cout << ans << "\n";
}
