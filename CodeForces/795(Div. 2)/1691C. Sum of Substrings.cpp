// Problem: C. Sum of Substrings
// Contest: Codeforces - CodeCraft-22 and Codeforces Round #795 (Div. 2)
// URL: https://codeforces.com/contest/1691/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-05-31 15:35:05
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
	int n, k;
	cin >> n >> k;
	str s;
	cin >> s;
	int ans = 0;
	for (int i = 0; i < n; i++){
		ans += (s[i] - '0');
	}
	ans *= 11;
	
	int i = 0;
	for (; i < n; i++){
		if (s[i] - '0') break;
	}
	int j = n - 1;
	for (; j >= 0; j--){
		if (s[j] - '0') break;
	}
	if (j == -1){
		cout << "0\n";
		return;
	}
	
	bool used = 0;
	if (n - 1 - j <= k){
		k -= n - 1 - j;
		ans -= 10;
		used = 1;
	}
	
	if (i <= k && !(i == j && used)){
		ans -= 1;
	}
	cout << ans << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
