// Problem: C. Circular Local MiniMax
// Contest: Codeforces - Codeforces Round #794 (Div. 2)
// URL: https://codeforces.com/contest/1686/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-05-25 18:35:31
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
	for (int &x: a) cin >> x;
	
	sor(a);
	bool ok = true;
	
	if (n % 2){
		ok = false;
	}
	else{
		for (int i = 0; i < n/2; i++){
			if (a[i] == a[i + n/2]) ok = false;
			if (i < n/2 - 1 && a[i+1] == a[i+n/2]) ok = false;
		}
	}
	
	if (ok){
		cout << "YES\n";
		for (int i = 0; i < n/2; i++){
			cout << a[i] << " " << a[i + n/2 + n % 2] << " ";
		}
		cout << "\n";
	}
	else{
		cout << "NO\n";
	}
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
