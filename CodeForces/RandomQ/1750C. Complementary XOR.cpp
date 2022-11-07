// Problem: C. Complementary XOR
// Contest: Codeforces - CodeTON Round 3 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1750/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-11-07 14:10:27
// 
// Powered by CP Editor (https://cpeditor.org)

// https://codeforces.com/profile/Intellegent husbando <3

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double db;
typedef string str;

#define mp make_pair
#define f first
#define s second

#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsor(x) sort(x.rbegin(), x.rend())
#define pb emplace_back

#ifdef ORIGINAL_LOCAL
#include <bits/debug.h>
#else
#define dbg(...) 42
#endif

const int mod = 1e9+7;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

void solve(){
	int n;
	cin >> n;
	str a, b;
	cin >> a >> b;
	
	bool s = 1, o = 1;
	for (int i = 0; i < n; i++){
		if (a[i] == b[i]) o = 0;
		else s = 0;
	}
	dbg(o, s);
	if (!o & !s){
		cout << "NO\n"; return;
	}
	
	cout << "YES\n";
	vector<pair<int, int> > ans;
	if (s){
		ans.pb(mp(1, n));
	}
	int cnt = 0;
	for (int i = 0; i < n; i++){
		if ((a[i] == '1') ^ s){
			ans.pb(mp(i + 1, i + 1));
			cnt++;
		}
	}
	if (cnt % 2 == 0){
		ans.pb(mp(1, 1));
		ans.pb(mp(2, n));
		ans.pb(mp(1, n));
	}
	
	cout << ans.size() << "\n";
	for (auto p: ans){
		cout << p.f << " " << p.s << "\n";
	}
}

int main () {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; 
	cin >> t;
	while (t--)
	solve();
}
