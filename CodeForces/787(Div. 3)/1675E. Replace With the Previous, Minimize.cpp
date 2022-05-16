// Problem: E. Replace With the Previous, Minimize
// Contest: Codeforces - Codeforces Round #787 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1675/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-05-11 10:58:57
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double db;
typedef string str;

#define mp make_pair
#define f first
#define s second

typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<bool> vb;
typedef vector<pi> vpi;

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
	
	int i = 0;
	vi cnt(26);
	
	for (int i = 0; i < 26; i++) cnt[i] = i;
	for (int i = 0; i < n; i++){
		int mn = s[i] - 'a', mni = mn;
		for (int j = s[i] - 'a'; j >= max(0, (s[i] - 'a') - k); j--){
			if (cnt[j] < mn){
				mn = cnt[j];
				mni = j;
				// cout << cnt[j] << " " << j<< " FOUND\n";
			}
		}
		// debug(mn) debug(mni)
		k -= (s[i] - 'a') - mni;
		for (int j = mni; j <= s[i] - 'a'; j++){
			cnt[j] = mn;
		}
	}
	// vdebug(cnt)
	for (int i = 0; i < n; i++){
		char x = 'a' + cnt[s[i] - 'a'];
		cout << x; 
	}
	cout << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
