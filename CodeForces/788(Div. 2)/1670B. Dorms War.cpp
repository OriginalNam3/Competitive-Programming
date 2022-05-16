// Problem: B. Dorms War
// Contest: Codeforces - Codeforces Round #788 (Div. 2)
// URL: https://codeforces.com/contest/1670/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-05-16 15:48:40
// 
// Powered by CP Editor (https://cpeditor.org)

// History - deleted
// Holy water - needed
// Meat - beated
// Phone - yeeted
//  - https://codeforces.com/profile/Intellegent <3

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
	str s;
	cin >> s;
	
	int k;
	cin >> k;
	map<char, bool> alpha;
	for (int i = 0; i < k; i++){
		char c; cin >> c;
		alpha[c] = 1;
	}
	
	int j = 0, mx = 0;
	for (int i = 0; i < n; i++){
		if (alpha[s[i]]){
			mx = max(mx, i - j);
			j = i;
		}
	}
	cout << mx << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
