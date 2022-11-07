// Problem: D. Problem with Random Tests
// Contest: Codeforces - CP
// URL: https://codeforces.com/contest/1743/problem/D
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// Date & Time: 2022-11-02 14:30:10
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
	str s;
	cin >> s;
	int m = 60;
	vector<int> a(m, -1);
	int start = 0;
	while (start < n && s[start] == '0') start++;
	while (start < n && s[start] == '1') start++;
	int i = start;
	for (int cnt = 0; cnt < m && i < n; cnt++){
		while (i < n && s[i] == '1'){
			i++;
		}
		if (i < n) a[cnt] = i - start;
		i++;
	}
	dbg(a);
	ll mx = 0, mxi = 0;
	i = 0;
	while (s[i] == '0') i++;
	for (; i < start; i++){
		int j = 0;
		ll cnt = 0;
		for (; j < m; j++){
			if (i + a[j] >= n || a[j] == -1) break;
			if (s[i + a[j]] == '1') cnt += (1LL << (m - j));
		}
		if (cnt > mx){
			mx = cnt;
			mxi = i;
		}
	}
	dbg(mx, mxi);
	dbg(start);
	i = 0;
	while (s[i] == '0' && i < n - 1) i++;
	for (; i < n; i++){
		if (s[i] == '1' || (i - start + mxi < n && s[i - start + mxi] == '1')) cout << "1";
		else cout << "0"; 
	}
	cout << "\n";
}

int main () {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
}
