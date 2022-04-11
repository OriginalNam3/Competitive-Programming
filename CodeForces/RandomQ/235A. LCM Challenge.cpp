// Problem: A. LCM Challenge
// Contest: Codeforces - Codeforces Round #146 (Div. 1)
// URL: https://codeforces.com/problemset/problem/235/A
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
    int n;
    cin >> n;
    if (n < 3){
    	cout << n;
    	return 0;
    }
    if (n%2){
    	cout << 1LL * n * (n-1) * (n-2);
    }
    else{
    	ll ans = 0;
    	forn(i, max(1, n - 69), n+1) forn(j, i, n+1) forn(k, j, n+1){
    		ll g = gcd(i, j), tmp = 1LL * (1LL * i/g) * (1LL * j/g) * g;
    		g = gcd(tmp, k);
    		ans = max(ans, 1LL * (1LL * tmp/g) * (1LL * k/g) * g);
    		
    	}
    	cout << ans;
    }
}
