// Problem: D. River Locks
// Contest: Codeforces - Codeforces Round #802 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1700/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-06-22 15:15:36
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
	
	vector<ll> suff(n);
	suff[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--){
		suff[i] += suff[i + 1] + a[i];
	}
	
	int l = a[0], r = 1e9;
	while (l < r){
		ll mx = (l + r)/2, last = mx - a[0];
		bool ok = true;
		for (int i = 1; i < n; i++){
			if (a[i] <= mx + last){
				last = mx + last - a[i];
			}
			else{
				ok = false;
				dbg(i, mx, last);
				break;
			}
		}
		if (ok){
			r = mx;
		}
		else{
			l = mx + 1;
		}
	}
	int mx = l;
	dbg(mx);
	int q;
	cin >> q;
	
	for (int rep = 0; rep < q; rep++){
		int x;
		cin >> x;
		if (x < mx){
			cout << "-1\n";
		}
		else cout << (suff[0] + x - 1)/x << "\n";
	}
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
}
