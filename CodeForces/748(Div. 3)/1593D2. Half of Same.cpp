// Problem: D2. Half of Same
// Contest: Codeforces - Brogrammer Contest #3
// URL: https://codeforces.com/contest/1593/problem/D2
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-04-29 19:30:58
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
	int n; cin >> n;
	vi a(n);
	each(x, a) cin >> x;
	sor(a);
	map<int, int> acnt;
	set<int> ans;
	forn(i, 0, n){
		acnt[a[i]]++;
		if (acnt[a[i]] >= n/2){
			cout << "-1\n"; return;
		}
		set<int> factors;
		map<int, int> cnt;
		forn(j, i+1, n){
			int d = a[j] - a[i];
			// debug(d); debug(a[i]); debug(a[j]);
			for (int f = 1; f * f <= d; f++){
				if (d % f == 0){
					// debug(f);
					factors.insert(f);
					cnt[f]++;
					if (d/f != f) {
						factors.insert(d/f);
						cnt[d/f]++;
					}
				}
			}
		}
		while (!factors.empty()){
			int f = *factors.rbegin();
			// debug(f); debug(cnt[f]);
			if (cnt[f] >= n/2 - acnt[a[i]]){
				ans.insert(f);
				break;
			}
			factors.erase(f);
		}
	}
	cout << *ans.rbegin() << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
