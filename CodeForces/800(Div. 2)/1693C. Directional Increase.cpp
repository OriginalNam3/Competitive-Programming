// Problem: C. Directional Increase
// Contest: Codeforces - Goodbye Exams (TK L)
// URL: https://codeforces.com/contest/1693/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-06-17 20:08:07
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
	vector<int> a(n);
	for (int &x: a) cin >> x;
	dbg(a);
	vector<int> b(n);
    int i;
    ll sum = 0;
    for (i = 0; i < n; i++) {
        sum += a[i];
        if (sum < 0) {
            cout << "No\n";
            return;
        }
        if (sum == 0) break;
    }
    i++;
    for (; i < n; i++) {
        if (a[i] != 0) {
            cout << "No\n";
            return;
        }
    }
	ll cur = -a[0];
	for (i = 1; i < n - 1; i++){
		if (cur > a[i]){
			cout << "No\n";
			return;
		}
		if (cur == a[i]){
			for (int j = i + 1; j < n; j++){
				if (a[j] != 0){
					cout << "No\n";
					return;
				}
			}
			cout << "Yes\n";
			return;
		}
		cur = cur - a[i];
	}
	dbg(cur);
	if (cur != a[n - 1]){
		cout << "No\n";
		return;
	}
	cout << "Yes\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; 
    cin >> t;
    while (t--)
    solve();
}
