// Problem: F. Consecutive Subsequence
// Contest: Codeforces - Codeforces Round #479 (Div. 3)
// URL: https://codeforces.com/problemset/problem/977/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-05-28 23:40:19
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
	vector<int> a(n);
	for (int &x: a) cin >> x;
	
	int mx = 0, cur;
	map<int, int> cnt;
	for (int i = 0; i < n; i++){
		cnt[a[i]] = cnt[a[i] - 1] + 1;
		// debug(a[i]) debug(cnt[a[i]])
		if (cnt[a[i]] > mx){
			mx = cnt[a[i]];
			cur = a[i];
		}
	}
	
	cout << mx << "\n";
	vector<int> ans;
	for (int i = n-1; i >= 0; i--){
		if (a[i] == cur){
			ans.pb(i + 1);
			cur--;
		}
	}
	for (int i = mx - 1; i >= 0; i--){
		cout << ans[i] << " ";
	}
	cout << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
}
