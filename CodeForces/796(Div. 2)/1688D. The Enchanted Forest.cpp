// Problem: D. The Enchanted Forest
// Contest: Codeforces - Codeforces Round #796 (Div. 2)
// URL: https://codeforces.com/contest/1688/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-06-03 15:35:12
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
	ll n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	if (k > n){
		ll sum = 0;
		for (int i = 0; i < n; i++){
			sum += a[i];
		}
		ll ans = sum + 1LL * (k - n) * n + 1LL * (n-1) * n / 2;
		cout << ans << "\n";
	}
	else{
		ll sum = 0;
		for (int i = 0; i < k; i++){
			sum += a[i];
		}
		
		ll bst = sum;
		for (int i = k; i < n; i++){
			sum += a[i] - a[i - k];
			bst = max(bst, sum);
		}
		
		cout << bst + 1LL * k * (k-1)/ 2 << "\n";
	}
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
