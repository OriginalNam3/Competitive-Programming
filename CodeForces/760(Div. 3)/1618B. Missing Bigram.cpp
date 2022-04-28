// Problem: B. Missing Bigram
// Contest: Codeforces - Brogrammer Contest #2
// URL: https://codeforces.com/problemset/problem/1618/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-04-28 20:08:13
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

const int mod = 1e9+7;
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

void solve(){
	int n;
	cin >> n;
	str s;
	cin >> s;
	cout << s;
	char l = s[1];
	bool ok = false;
	// debug(n);
	rep(n-3){
		cin >> s;
		if (s[0] == l){
			cout << s[1];
		}
		else{
			cout << s;
			ok = true;
		}
		// debug(s);
		l = s[1];
		// debug(l);
	}
	if (!ok){
		cout << 'a';
	}
	cout << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    // debug(t);
    while (t--) solve();
}
