// Problem: A. Orac and LCM
// Contest: Codeforces - Codeforces Round #641 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1349/A
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
    forn(i, 0, n){
    	cin >> a[i];
    }
    vi l(n), r(n);
    l[0] = a[0], r[n-1] = a[n-1];
    forn(i, 1, n){
    	l[i] = gcd(l[i-1], a[i]);
    	r[n - 1 - i] = gcd(r[n - i], a[n - i - 1]);
    }
    ll ans = gcd(r[1], l[n-2]);
    ans = (r[1]/ans) * (l[n-2]/ans) * ans;
    forn(i, 1, n-1){
    	ll d = gcd(l[i-1], r[i+1]), g = gcd(ans, d);
    	ans = ((ans/g) * (d/g)) * g;
    }
    cout << ans;
}
