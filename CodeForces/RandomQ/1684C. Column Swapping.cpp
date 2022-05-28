// Problem: C. Column Swapping
// Contest: Codeforces - Codeforces Round #792 (Div. 1 + Div. 2)
// URL: https://codeforces.com/problemset/problem/1684/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-05-22 23:10:38
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
	int n, m;
	cin >> n >> m;
	vector<vector<int> > a(n, vector<int> (m)), b(n, vector<int> (m));
	
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		cin >> a[i][j];
		b[i][j] = a[i][j];
	}
	
	int j = -1, k = -1;
	for (int i = 0; i < n && j == -1; i++){
		sor(b[i]);
		for (int x = 0; x < m; x++){
			if (a[i][x] != b[i][x]){
				j = x;
				for (k = j + 1; k < m; k++){
					if (a[i][k] != b[i][k]) break;
				}
				break;
			}
		}
	}
	if (j == -1){
		cout << "1 1\n";
		return;
	}
	
	for (int i = 0; i < n; i++){
		swap(a[i][j], a[i][k]);
		for (int x = 1; x < m; x++){
			if (a[i][x] < a[i][x-1]){
				cout << "-1\n";
				return;
			}
		}
	}
	
	cout << j + 1 << " " << k + 1 << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
