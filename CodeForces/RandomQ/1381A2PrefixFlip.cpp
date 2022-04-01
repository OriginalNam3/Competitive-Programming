// Problem: A2. Prefix Flip (Hard Version)
// Contest: Codeforces - Codeforces Round #658 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1381/A2
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
typedef array<int, 3> qq;

#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define pb push_back

#define fr(i,a,b) for (int i = (a); i < (b); ++i)
#define rf(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define each(x, a) for (auto& x: a)

void solve(){
	int n;
	cin >> n;
	str a;
	cin >> a;
	str b;
	cin >> b;
	vi ans;
	char c;
	fr(i, 0, n){
		if (i % 2 == 0) c = a[i/2];
		else {
			c = a[n - 1 - i/2];
			if (c == '1') c = '0';
			else c = '1';
		}
		if (c == b[n - 1 - i]){
			ans.pb(1);
		}
		ans.pb(n-i);
	}
	int s = ans.size();
	cout << s << " ";
	fr(i, 0, s){
		cout << ans[i] << " ";
	}
	cout << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--){
    	solve();
    }
}
