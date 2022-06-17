// Problem: H. Gambling
// Contest: Codeforces - Codeforces Round #799 (Div. 4)
// URL: https://codeforces.com/contest/1692/problem/H
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-06-14 17:26:24
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
	vector<int> a(n);
	for (int &x: a) cin >> x;
	
	map<int, pair<int, pair<int, int> > > cnt;
	int mx = 0, ans = a[0], l = 0, r = 0;
	for (int i = 0; i < n; i++){
		if (cnt[a[i]].f == 0) cnt[a[i]].s.f = i; 
		if (cnt[a[i]].s.s != 0){
			cnt[a[i]].f -= i - cnt[a[i]].s.s;
			if (cnt[a[i]].f < 0){
				cnt[a[i]].f = 0;
				cnt[a[i]].s.f = i;
			}
		}
		cnt[a[i]].s.s = i + 1;
		cnt[a[i]].f = cnt[a[i]].f + 1;
		if (cnt[a[i]].f > mx){
			mx = cnt[a[i]].f;
			ans = a[i];
			l = cnt[a[i]].s.f;
			r = i;
		}
	}
	dbg(cnt);
	
	cout << ans << " " << l + 1 << " " << r + 1 << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; 
    cin >> t;
    while (t--)
    solve();
}
