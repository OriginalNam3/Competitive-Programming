// Problem: A. Lex String
// Contest: Codeforces - Codeforces Round #798 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1689/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-06-10 21:07:56
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
	int n, m, k;
	cin >> n >> m >> k;
	str a, b;
	cin >> a >> b;
	sor(a); sor(b);
	int i = 0, j = 0, cnt = 0;
	while (i < n && j < m){
		if (cnt == k){
			cout << b[j];
			j++;
			cnt = -1;
			continue;
		}
		if (cnt == -k){
			cout << a[i];
			i++;
			cnt = 1;
			continue;
		}
		if (a[i] < b[j]){
			cout << a[i];
			i++;
			cnt = max(cnt, 0);
			cnt++;
			continue;
		}
		if (b[j] < a[i]){
			cout << b[j];
			j++;
			cnt = min(cnt, 0);
			cnt--;
			continue;
		}
		if (a[i] == b[j]){
			if (cnt >= 0){
				cout << b[j];
				j++;
				cnt = -1;
			}
			else{
				cout << a[i];
				i++;
				cnt = 1;
			}
		}
	}
	cout << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
