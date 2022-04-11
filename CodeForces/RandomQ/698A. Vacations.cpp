// Problem: A. Vacations
// Contest: Codeforces - Codeforces Round #363 (Div. 1)
// URL: https://codeforces.com/problemset/problem/698/A
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
    vi a(n);
    each(x, a) cin >> x;
    vector<vi> dp(n+1, vi(3));
    forn(i, 1, n+1){
    	dp[i][0] = min(dp[i-1][0], min(dp[i-1][1], dp[i-1][2])) + 1;
    	dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
    	if (a[i-1] != 1 && a[i-1] != 3) dp[i][1]++;
    	dp[i][2] = min(dp[i-1][0], dp[i-1][1]);
    	if (a[i-1] != 2 && a[i-1] != 3) dp[i][2]++;
    }
    cout << min(dp[n][0], min(dp[n][1], dp[n][2]));
}
