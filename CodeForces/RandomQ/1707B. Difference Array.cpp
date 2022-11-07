// Problem: B. Difference Array
// Contest: Codeforces - Codeforces Round #808 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1707/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-07-21 23:59:30
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
	
	vector<int> b;
	int cnt = 0;
	while (a.size() > 1){
		b.clear();
		if (cnt > 0){
			cnt--;
			b.pb(a[0]);
		}
		for (int j = 0; j < a.size() - 1; j++){
			int diff = a[j + 1] - a[j];
			if (diff == 0){
				cnt++;
			}
			else{
				b.pb(diff);
			}
		}
		dbg(a, b);
		sor(b);
		swap(a, b);
	}
	if (a.empty()){
		cout << "0\n"; return;
	}
	cout << a[0] << "\n";
}

int main () {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; 
	cin >> t;
	while (t--)
	solve();
}
