// Problem: Distinct Palindrome
// Contest: CodeChef - START43
// URL: https://www.codechef.com/submit-v2/DISPAL
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-06-15 20:34:37
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
	int n, x;
	cin >> n >> x;
	if (x > 26 || x > n/2 + n % 2){
		cout << "-1\n";
		return;
	}
	vector<char> ans(n);
	char cur = 'a';
	for (int i = 0; i < x; i++){
		ans[i] = ans[n - 1 - i] = cur;
		cur++;
	}
	for (int i = x; i < n - x; i++){
		ans[i] = ans[i-1];
	}
	for (char c: ans) cout << c;
	cout << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; 
    cin >> t;
    while (t--)
    solve();
}
