// Problem: A. Going Home
// Contest: Codeforces - Codeforces Round #707 (Div. 1, based on Moscow Open Olympiad in Informatics)
// URL: https://codeforces.com/problemset/problem/1500/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-05-29 20:56:19
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
	
	if (n <= 5000){
		map<int, pair<int, int> > cnt;
		for (int i = 1; i < n; i++){
			for (int j = 0; j < i; j++){
				if (cnt[a[i] + a[j]].f != cnt[a[i] + a[j]].s && cnt[a[i] + a[j]].f != j && cnt[a[i] + a[j]].s != j && cnt[a[i] + a[j]].f != i && cnt[a[i] + a[j]].s != i){
					cout << "YES\n" << cnt[a[i] + a[j]].f + 1 << " " << cnt[a[i] + a[j]].s + 1 << " " << i + 1 << " " << j + 1 << " ";
					return;
				}
				cnt[a[i] + a[j]].f = j;
				cnt[a[i] + a[j]].s = i;
			}
		}
		cout << "NO\n";
	}
	
	else{
		vector<pair<int, int> > b(n);
		for (int i = 0; i < n; i++){
			b[i].f = a[i];
			b[i].s = i + 1;
		}
		sor(b);
		map<int, pair<int, int> > cnt;
		
		for (int i = 0; i < n - 1; i++){
			if (cnt[b[i + 1].f - b[i].f].f == cnt[b[i + 1].f - b[i].f].s){
				cnt[b[i + 1].f - b[i].f].f = b[i].s;
				cnt[b[i + 1].f - b[i].f].s = b[i + 1].s;
				continue;
			}
			if (cnt[b[i + 1].f - b[i].f].s == b[i].s) continue;
			cout << "YES\n" << cnt[b[i + 1].f - b[i].f].f << " " << b[i + 1].s << " " << b[i].s << " " << cnt[b[i + 1].f - b[i].f].s;
			return;
		}
		cout << "NO\n";
	}
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
}
