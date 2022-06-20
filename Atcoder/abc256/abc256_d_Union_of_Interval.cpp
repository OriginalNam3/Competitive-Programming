// Problem: D - Union of Interval
// Contest: AtCoder - Tokio Marine & Nichido Fire Insurance Programming Contest 2022（AtCoder Beginner Contest 256)
// URL: https://atcoder.jp/contests/abc256/tasks/abc256_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Date & Time: 2022-06-18 13:32:14
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
	set<pair<int, int> > q;
	for (int i = 0; i < n; i++){
		int l, r;
		cin >> l >> r;
		q.insert(mp(l, r));
	}
	vector<pair<int, int> > ans;
	int l = q.begin()->f, r = q.begin()->s;
	q.erase(q.begin());
	while (!q.empty()){
		int curl = q.begin()->f, curr = q.begin()->s;
		if (curl <= r){
			r = max(r, curr);
		}
		else{
			ans.pb(mp(l, r));
			l = curl, r = curr;
		}
		q.erase(q.begin());
	}
	ans.pb(mp(l, r));
	
	for (auto p: ans) cout << p.f << " " << p.s << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
}
