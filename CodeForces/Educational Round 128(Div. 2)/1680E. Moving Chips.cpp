// Problem: E. Moving Chips
// Contest: Codeforces - Educational Codeforces Round 128 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1680/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-05-20 19:26:27
// 
// Powered by CP Editor (https://cpeditor.org)

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
	int n;
	cin >> n;
	vector<vector<bool> > a(n, vector<bool> (2));
	
	for (int i = 0; i < 2; i++){
		string row;
		cin >> row;
		for (int j = 0; j < n; j++){
			if (row[j] == '*'){
				a[j][i] = 1;
			}
		}
	}
	
	int ans = 0, cur = 0, j = -1;
	bool ok = false;
	for (int i = 0; i < n; i++){
		if (a[i][0] && a[i][1]){
			if (j != -1) {
				ans += i - j + 1;
			}
			else{
				ans++;
			}
			j = i;
			cur = 2;
			continue;
		}
		if (a[i][0]){
			if (j != -1){
				ans += i - j;
				if (cur == 1){
					ans++;
					cur = 2;
				}
				else if (cur == 2){
					cur = 0;
				}
			}
			else{
				cur = 0;
			}
			j = i;
		}
		if (a[i][1]){
			if (j != -1){
				ans += i - j;
				j = i;
				if (cur == 0){
					ans++;
					cur = 2;
				}
				else if (cur == 2){
					cur = 1;
				}
			}
			else{
				j = i;
				cur = 1;
			}
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
