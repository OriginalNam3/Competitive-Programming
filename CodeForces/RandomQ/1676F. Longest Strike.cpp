// Problem: F. Longest Strike
// Contest: Codeforces - Codeforces Round #790 (Div. 4)
// URL: https://codeforces.com/problemset/problem/1676/F
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-05-16 22:05:05
// 
// Powered by CP Editor (https://cpeditor.org)

// History - deleted
// Holy water - needed
// Meat - beated
// Phone - yeeted
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
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	
	map<int, int> cnt;
	set<int> ok;
	
	for (int i = 0; i < n; i++){
		cnt[a[i]]++;
		if (cnt[a[i]] == k) ok.insert(a[i]);
	}
	
	if (ok.empty()){
		cout << "-1\n";
		return;
	}
	
	int l = 0, r = -1, i, j;
	while (!ok.empty()){
		 i = *ok.begin();
		 ok.erase(ok.begin());
		 j = i;
		 while (!ok.empty() && *ok.begin() == j + 1){
		 	j++;
		 	ok.erase(ok.begin());
		 }
		 if (j - i > r - l){
		 	l = i; r = j;
		 }
	}
	cout << l << " " << r << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
