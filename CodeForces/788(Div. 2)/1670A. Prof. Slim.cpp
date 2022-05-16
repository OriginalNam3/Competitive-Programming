// Problem: A. Prof. Slim
// Contest: Codeforces - Codeforces Round #788 (Div. 2)
// URL: https://codeforces.com/contest/1670/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-05-16 15:44:02
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
	vector<int> a(n);
	int cnt = 0;
	for (int &x: a) {
		cin >> x;
		if (x < 0) cnt++;
	}
	for (int i = 0; i < cnt; i++){
		a[i] = -abs(a[i]);
	}
	for (int i = cnt; i < n; i++){
		a[i] = abs(a[i]);
	}
	for (int i = 1; i < n; i++){
		if (a[i-1] > a[i]){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
