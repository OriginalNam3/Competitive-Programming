// Problem: E - Prefix Equality
// Contest: AtCoder - AtCoder Beginner Contest 250
// URL: https://atcoder.jp/contests/abc250/tasks/abc250_e
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
// Date & Time: 2022-06-17 15:15:55
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
	vector<int> a(n), b(n);
	for (int &x: a) cin >> x;
	for (int &x: b) cin >> x;
	
	vector<vector<int> > siz(n, vector<int>(2));
	set<int> cnta, cntb;
	for (int i = 0; i < n; i++){
		cnta.insert(a[i]);
		cntb.insert(b[i]);
		siz[i][0] = cnta.size();
		siz[i][1] = cntb.size();
	}
	
	set<int> cnt;
	vector<bool> ok(n);
	dbg(ok);
	if (a[0] == b[0]) ok[1] = 1;
	else cnt.insert(a[0]), cnt.insert(b[0]);
	int i = 1, j = 1;
	while (i < n && siz[i - 1][0] == siz[i][0]) i++;
	while (j < n && siz[j - 1][1] == siz[j][1]) j++;
	int cur = 2;
	while (i < n && j < n){
		dbg(i, j);
		if (cnt.count(a[i])) cnt.erase(a[i]);
		else cnt.insert(a[i]);
		if (cnt.count(b[j])) cnt.erase(b[j]);
		else cnt.insert(b[j]);
		if (cnt.size() == 0) ok[cur] = 1;
		i++;
		j++;
		while (i < n && siz[i - 1][0] == siz[i][0]) i++;
		while (j < n && siz[j - 1][1] == siz[j][1]) j++;
		cur++;
	}
	dbg(ok);
	int q;
	cin >> q;
	for (int i = 0; i < q; i++){
		int x, y;
		cin >> x >> y;
		x--; y--;
		dbg(x, y);
		if (siz[x][0] != siz[y][1]){
			cout << "No\n";
			continue;
		}
		cout << (ok[siz[x][0]] ? "Yes\n": "No\n");
	}
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
}
