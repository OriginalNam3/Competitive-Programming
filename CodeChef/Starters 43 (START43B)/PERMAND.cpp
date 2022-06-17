// Problem: Permutation AND
// Contest: CodeChef - START43
// URL: https://www.codechef.com/submit-v2/PERMAND
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-06-15 22:03:31
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
	if (n == 1){
		cout << "1\n1\n";
		return;
	}
	
	if (n % 2){
		cout << "-1\n";
		return;
	}
	
	for (int i = n; i >= 1; i--){
		cout << i << " ";
	}
	cout << "\n";
	int x = (1 << 30);
	vector<int> mp(n + 1);
	for (int i = n; i >= 1; i--){
		if (mp[i] != 0){
			cout << mp[i] << " ";
			continue;
		}
		while (x > 2 * i){
			x/= 2;
		}
		mp[x - 1 - i] = i;
		cout << x - 1 - i << " ";
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
