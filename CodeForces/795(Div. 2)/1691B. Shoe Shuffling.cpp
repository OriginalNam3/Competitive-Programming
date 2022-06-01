// Problem: B. Shoe Shuffling
// Contest: Codeforces - CodeCraft-22 and Codeforces Round #795 (Div. 2)
// URL: https://codeforces.com/contest/1691/problem/B
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
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	map<int, vector<int> > ind;
	set<int> sizs;
	for (int i = 0; i < n; i++){
		ind[a[i]].pb(i);
		sizs.insert(a[i]);
	}
	
	vector<int> ans(n);
	for (int siz: sizs){
		if (ind[siz].size() == 1){
			cout << "-1\n";
			return;
		}
		ans[ind[siz][0]] = ind[siz][ind[siz].size() - 1] + 1;
		for (int i = ind[siz].size() - 1; i >= 1; i--){
			ans[ind[siz][i]] = ind[siz][i-1] + 1;
		}
	}
	
	for (int x: ans) cout << x << " ";
	cout << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
