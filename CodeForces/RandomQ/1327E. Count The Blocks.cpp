// Problem: E. Count The Blocks
// Contest: Codeforces - Educational Codeforces Round 84 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1327/E
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

const int mod = 998244353;
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

void solve(){
	
}

int bpow(int a, int b){
	int res = 0;
	while (b > 0){
		if (b & 1){
			res = mul(res, a);
		}
		a = mul(a, a);
	}
	return res;
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    
    vi dp(n);
    dp[n-1] = 180;
    rofn(i, 0, n-1){
    	dp[i] = mul(dp[i+1], 10);
    }
    
    int p = 810;
    rofn(i, 1, n-1){
    	dp[i] = add(dp[i], mul(n - i - 1, p));
    	p = mul(p, 10);
    }
    forn(i, 1, n){
    	cout << dp[i] << " ";
    }
    cout << "10";
}
