// Problem: D. Finding Zero
// Contest: Codeforces - Codeforces Round #770 (Div. 2)
// URL: https://codeforces.com/contest/1634/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-06-05 21:28:07
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
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

int q(int a, int b, int c){
	cout << "? " << a << " " << b << " " << c << "\n";
	cout.flush();
	int res;
	cin >> res;
	return res;
}

void solve(){
	int n;
	cin >> n;
	vector<int> cur;
	for (int i = 1; i <= 4; i++){
		cur.pb(i);
	}
	
	int next = 5;
	while (next < n + 2){
		int res[4];
		for (int i = 0; i < 4; i++){
			res[i] = q(cur[(i + 1) % 4], cur[(i + 2) % 4], cur[(i + 3) % 4]);
		}
		
		int mx = max(max(res[0], res[1]), max(res[2], res[3]));
		int fi = -1, si = -1;
		for (int i = 0; i < 4; i++){
			if (res[i] == mx){
				if (fi == -1) fi = i;
				else si = i;
			}
		}
		
		if (n % 2 && next == 5){
			cur[fi] = next;
			next++;
			continue;
		}
		cur[fi] = next; 
		next++;
		cur[si] = next;
		next++;
	}
	
	cout << "! ";
	for (int i = 0; i < 4; i++){
		if (cur[i] <= n) cout << cur[i] << " ";
	}
	cout << "\n";
	cout.flush();
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
