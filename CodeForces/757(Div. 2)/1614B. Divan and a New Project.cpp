// Problem: B. Divan and a New Project
// Contest: Codeforces - Brogrammer contest #something (I forgor)
// URL: https://codeforces.com/contest/1614/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-05-23 18:55:32
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
#define pb push_back

#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

const int mod = 1e9+7;
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

void solve(){
	int n;
	cin >> n;
	vector<pair<int, int> > a(n);
	for (int i = 0; i < n; i++){
		cin >> a[i].f;
		a[i].s = i;
	}
	
	sort(a.rbegin(), a.rend());
	ll cnt = 0, cur = 1;
	vector<int> ans(n);
	for (int i = 0; i < n; i++){
		cnt += 1LL * 2 * a[i].f * abs(cur);
		ans[a[i].s] = cur;
		cur = -cur;
		if (cur > 0) cur++;
	}
	
	cout << cnt << "\n0 ";
	for (int x: ans) cout << x << " ";
	cout << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
