// Problem: D. Infinite Set
// Contest: Codeforces - Codeforces Round #772 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1635/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-06-13 21:31:14
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

// #ifdef ORIGINAL_LOCAL
// #include <bits/debug.h>
// #else
#define dbg(...) 42
// #endif

const int mod = 1e9+7;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

void solve(){
	int n, p;
	cin >> n >> p;
	vector<int> a(n), cnt(p + 1);
	map<int, bool> in;
	for (int &x: a) {
		cin >> x;
		in[x] = 1;
	}
	
	sor(a);
	for (int i = 0, pow = 2; i < n && __lg(pow) <= p; i++){
		int cur = a[i];
		bool ok = true;
		while (cur > 1){
			dbg(cur);
			if (cur % 4 == 0){
				cur /= 4;
				if (in[cur]){
					ok = false;
					break;
				}
			}
			else{
				if (cur % 2){
					cur -= 1;
					cur /= 2;
					if (in[cur]){
						ok = false;
						break;
					}
				}
				else{
					break;
				}
			}
		}
		if (!ok) continue;
		dbg(a[i]);
		while (pow <= a[i]) pow <<= 1;
		dbg(pow);
		if (__lg(pow) <= p) cnt[__lg(pow)]++;
	}
	dbg(cnt);
	for (int i = 2; i <= p; i++){
		cnt[i] = add(cnt[i], add(cnt[i-1], cnt[i-2]));
	}
	dbg(cnt);
	
	ll ans = 0;
	for (int i = 1; i <= p; i++){
		ans = add(ans, cnt[i]);
	}
	
	cout << ans;
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
}
