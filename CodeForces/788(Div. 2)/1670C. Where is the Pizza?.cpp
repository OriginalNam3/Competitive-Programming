// Problem: C. Where is the Pizza?
// Contest: Codeforces - Codeforces Round #788 (Div. 2)
// URL: https://codeforces.com/contest/1670/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-05-16 15:54:26
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

const int N = 1e5 + 4;

int n;
map<int, int> ind;
vector<int> a(N), b(N), c(N);
vector<bool> searched(N);

void search(int i){
	if (searched[i]) return;
	searched[i] = 1;
	search(ind[b[i]]);
}

void solve(){
	cin >> n;
	vector<bool> cnt(n + 1);
	for (int i = 0; i < n; i++){
		cin >> a[i];
		ind[a[i]] = i;
	}
	for (int i = 0; i < n; i++){
		cin >> b[i];
		searched[i] = 0;
	}
	for (int i = 0; i < n; i++){
		cin >> c[i];
	}
	
	for (int i = 0; i < n; i++){
		if (c[i] > 0) search(i);
	}
	
	int ans = 1;
	for (int i = 0; i < n; i++){
		if (!searched[i]){
			if (a[i] == b[i]){
				continue;
			}
			search(i);
			ans = mul(ans, 2);
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
