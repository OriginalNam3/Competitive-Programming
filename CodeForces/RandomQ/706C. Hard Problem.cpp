// Problem: C. Hard problem
// Contest: Codeforces - Codeforces Round #367 (Div. 2)
// URL: https://codeforces.com/problemset/problem/706/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

bool cmp(str a, str b){
	int n = min(a.size(), b.size());
	forn(i, 0, n){
		if (a[i] != b[i]){
			return a[i] < b[i];
		}
	}
	return a.size() <= b.size();
}

void solve(){
	
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<pair<str, int> > a(n);
    forn(i, 0, n){
    	cin >> a[i].s;
    }
    forn(i, 0, n){
    	cin >> a[i].f;
    }
    vector<vll> dp(n, vll(2, LLONG_MAX >> 1));
    dp[0][0] = 0; dp[0][1] = a[0].s;
    forn(i, 1, n){
    	str cur = a[i].f, last = a[i-1].f, revcur = cur, revlast = last;
    	reverse(all(revcur)); reverse(all(revlast));
    	if (cmp(last, cur)){
    		dp[i][0] = min(dp[i][0], dp[i-1][0]);
    	}
    	if (cmp(revlast, cur)){
    		dp[i][0] = min(dp[i][0], dp[i-1][1]);
    	}
    	if (cmp(last, revcur)){
    		dp[i][1] = min(dp[i][1], dp[i-1][0] + a[i].s);
    	}
    	if (cmp(revlast, revcur)){
    		dp[i][1] = min(dp[i][1], dp[i-1][1] + a[i].s);
    	}
    }
    ll ans = min(dp[n-1][0], dp[n-1][1]);
    cout << ((ans == LLONG_MAX >> 1) ? -1: ans);
}
