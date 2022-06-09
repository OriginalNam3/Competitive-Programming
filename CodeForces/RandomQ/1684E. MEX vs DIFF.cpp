// Problem: E. MEX vs DIFF
// Contest: Codeforces - Codeforces Round #792 (Div. 1 + Div. 2)
// URL: https://codeforces.com/problemset/problem/1684/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-06-06 15:37:59
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
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	
	sor(a);
	
	int cur = 0, i = 0;
	for (int cnt = 0; cnt < k; cnt++){
		while (i < n && a[i] == cur){
			while (i < n && a[i] == cur) i++;
			cur++;
		}
		cur++;
	}
	
	while (i < n && a[i] == cur){
		while (i < n && a[i] == cur) i++;
		cur++;
	}
	

	vector<int> lens;
	while (i < n){
		int j = i + 1;
		while (j < n && a[j] == a[i]) {
			j++;
		}
		lens.pb(j - i);
		i = j;
	}
	
	
	int ans = 0;
	i = 0;
	sor(lens);
	for (; i < lens.size(); i++){
		if (lens[i] > k) ans++;
		else k -= lens[i];
	}
	
	cout << ans << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
