// Problem: B. Permutation Value
// Contest: Codeforces - CP
// URL: https://codeforces.com/contest/1743/problem/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// Date & Time: 2022-11-02 14:30:10
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
#define pb emplace_back

#ifdef ORIGINAL_LOCAL
#include <bits/debug.h>
#else
#define dbg(...) 42
#endif

const int mod = 1e9+7;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

void solve(){
	int n;
	cin >> n;
	if (n % 2){
		for (int i = 1; i <= n / 2; i++){
		
		cout << i << " ";
		cout << n / 2 + i + n % 2 << " ";
		}
		cout << n/2 + 1;
	}
	else for (int i = 1; i <= n / 2; i++){
		cout << n / 2 + i + n % 2 << " ";
		cout << i << " ";
		
	}
	
	cout << "\n";
}

int main () {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; 
	cin >> t;
	while (t--)
	solve();
}
