// Problem: Average Gift
// Contest: CodeChef - CodeChef Starters 38 Division 2 (Rated)
// URL: https://www.codechef.com/START38B/problems/AVGGIFT
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-05-11 15:36:32
// 
// Powered by CP Editor (https://cpeditor.org)

// You either sink in the coom, or coom in the sink.

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
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for (int &e: a) cin >> e;
	bool larger = false, less = false;
	
	for (int i = 0; i < n; i++){
		if (a[i] == x){
			cout << "YES\n"; return;
		}
		if (a[i] < x) less = true;
		if (a[i] > x) larger = true;
	}
	
	cout << (larger && less ? "YES\n" : "NO\n");
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
