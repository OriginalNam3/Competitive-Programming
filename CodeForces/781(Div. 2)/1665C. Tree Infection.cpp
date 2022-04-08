// Problem: C. Tree Infection
// Contest: Codeforces - Codeforces Round #781 (Div. 2)
// URL: https://codeforces.com/contest/1665/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double db;
typedef string str;

#define mp make_pair
#define f first
#define s second

typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<bool> vb;
typedef vector<pi> vpi;
typedef array<int, 3> qq;

#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsor(x) sort(x.rbegin(), x.rend())
#define pb push_back

#define forn(i,a,b) for (int i = (a); i < (b); ++i)
#define fors(i,a,b,s) for (int i = (a); i < (b); i+=s)
#define rofn(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define rep(n) for (int _ = 0; _ < n; _++)
#define each(x, a) for (auto& x: a)

const int mod = 1e9+7;
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

void solve(){
	int n;
	cin >> n;
	vi p(n), deg(n);
	forn(i, 1, n){
		cin >> p[i];
		p[i]--;
		deg[p[i]]++;
	}
	rsor(deg);
	// forn(i, 0, n){
		// cout << deg[i];
	// }
	int t = 0;
	priority_queue<int> q;
	forn(i, 0, n){
		if (!deg[i]) break;
		t++;
		q.push(i + deg[i]-1);
		while (!q.empty() && q.top() <= i){
			q.pop();
		}
	}
	// cout << t << ": t\n";
	q.push(1);
	while (!q.empty()){
		t++;
		while (!q.empty() && q.top() < t){
			q.pop();
		}
		if (q.empty()) break;
		if (q.top() > 1){
			q.push(q.top()-1);
		}
		q.pop();
	}
	cout << t << "\n";
	
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--){
    	solve();
    }
}
