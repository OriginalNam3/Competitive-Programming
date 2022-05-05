// Problem: A - Jogging
// Contest: AtCoder - Monoxer Programming Contest 2022（AtCoder Beginner Contest 249）
// URL: https://atcoder.jp/contests/abc249/tasks/abc249_a
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Date & Time: 2022-05-04 21:48:36
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
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

const int mod = 1e9+7;
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

void solve(){
	
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int a, b, c, d, e, f, x;
    cin >> a >> b >> c >> d >> e >> f >> x;
    int d1 = ((x / (a + c)) * a + min(a, x % (a + c))) * b, d2 = ((x / (d + f)) * d + min(d, x % (d + f))) * e;
	// debug(d1) debug(d2)
	cout << (d1 > d2 ? "Takahashi" : d2 > d1 ? "Aoki" : "Draw");
}
