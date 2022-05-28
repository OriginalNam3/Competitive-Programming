// Problem: C. Double Sort
// Contest: Codeforces - Educational Codeforces Round 129 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1681/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-05-23 15:43:48
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
	vector<int> a(n), b(n);
	for (int &x: a) cin >> x;
	for (int &x: b) cin >> x;
	
	
	vector<pair<int, int> > ans;
	for (int i = 0; i < n; i++){
		for (int j = 1; j < n; j++){
			if ((a[j] > a[j-1] && b[j] < b[j-1]) || (a[j] < a[j-1] && b[j] > b[j-1])){
				cout << "-1\n";
				return;
			}
			if (a[j] <= a[j-1] && b[j] <= b[j-1]){
				swap(a[j], a[j-1]);
				swap(b[j], b[j-1]);
				ans.pb(mp(j, j + 1));
			}
		}
	}
	cout << ans.size() << "\n";
	for (auto p: ans) cout << p.f << " " << p.s << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
