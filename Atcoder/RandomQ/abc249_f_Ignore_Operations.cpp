// Problem: F - Ignore Operations
// Contest: AtCoder - Monoxer Programming Contest 2022（AtCoder Beginner Contest 249）
// URL: https://atcoder.jp/contests/abc249/tasks/abc249_f
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Date & Time: 2022-06-13 19:30:50
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
	int n, k;
	cin >> n >> k;
	vector<pair<int, int> > a(n + 1);
	a[0].f = 1;
	for (int i = 1; i <= n; i++) cin >> a[i].f >> a[i].s;
	
	priority_queue<int> q;
	ll ans = LLONG_MIN, sum = 0;
	for (int i = n; i >= 0 && k >= 0; i--){
		dbg(i, k, ans, sum);
		if (a[i].f == 1){
			ans = max(ans, sum + a[i].s);
			k--;
		}
		else{
			if (a[i].s >= 0){
				sum += a[i].s;
			}
			else{
				if (q.size() < k){
					q.push(a[i].s);
				}
				else {
					if (!q.empty() && a[i].s < q.top()){
						sum += q.top();
						q.pop();
						q.push(a[i].s);
					}
					else{
						sum += a[i].s;
					}
				}
			}
		}
		if (q.size() > k && !q.empty()){
			sum += q.top();
			q.pop();
		}
	}
	
	cout << ans;
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
}
