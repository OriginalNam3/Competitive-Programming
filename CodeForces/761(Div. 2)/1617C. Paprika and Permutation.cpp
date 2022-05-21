// Problem: C. Paprika and Permutation
// Contest: Codeforces - TCP
// URL: https://codeforces.com/contest/1617/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-05-18 18:41:19
// 
// Powered by CP Editor (https://cpeditor.org)

// https://codeforces.com/profile/Intellegent <3

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
	
	sor(a);

	int ans = 0;
	map<int, bool> ok; // keeps track of stuff alr in the array?
	map<int, bool> cnt;
	int j = 0;
	for (int i = 0; i < n; i++){ // this thing :D
		if (1 <= a[i] && a[i] <= n) ok[a[i]] = 1;
	}
	for (int i = 1; i <= n; i++){ 
		while (ok[a[j]] && !cnt[a[j]] && j < n){ // so when u iterate, u skip all j that a[j] hasnt appeared before and ok[a[j]]
			cnt[a[j]] = 1;
			j++;
		}
		if (ok[i]){ 
			continue;
		}
		if (a[j] > 2 * i){ 
			ans++;
			j++;
		}
		else{
			cout << "-1\n";
			return;
		}
	}
	
	cout << ans << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
