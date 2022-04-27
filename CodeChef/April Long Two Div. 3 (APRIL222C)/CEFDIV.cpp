// Problem: Chef And Division
// Contest: CodeChef - April Long Two 2022 Division 3 (Rated)
// URL: https://www.codechef.com/APRIL222C/problems/CEFDIV
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-04-22 21:52:57
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
template<class T> using V = vector<T>;
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

const int mod = 998244353;
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}


void solve(){
	int n;
	cin >> n;
	vi a(n);
	each(x, a) cin >> x;
	int dp[4] = {0, 0, 0, 0};
	int odd[4][4] = 
	{{0, 1, 0, 0}, 
	{1, 0, 0, 1}, 
	{0, 1, 0, 1}, 
	{0, 0, 1, 0}}, 
	even[4][4] = 
	{{1, 0, 0, 0}, 
	{0, 1, 1, 0}, 
	{1, 0, 1, 0}, 
	{0, 0, 0, 1}};
	if (a[0]%2){
		dp[1]++;
		dp[3]++;
	}
	else{
		dp[0]++;
		dp[2]++;
	}
	forn(i, 1, n){
		int ndp[4] = {0, 0, 0, 0};
		if (a[i]%2){
			forn(i, 0, 4) forn(j, 0, 4){
				if (odd[j][i]) ndp[i] = add(ndp[i], dp[j]);
			}
		}
		else{
			forn(i, 0, 4) forn(j, 0, 4){
				if (even[j][i]) ndp[i] = add(ndp[i], dp[j]);
			}
		}
		forn(i, 0, 4) dp[i] = ndp[i];
		// each(x, dp) cout << x << " ";
		// cout << "\n";
	}
	cout << add(dp[1], dp[2]) << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
