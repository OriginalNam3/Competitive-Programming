// Problem: 3D Printing
// Contest: Google Coding Competitions - Qualification Round 2022 - Code Jam 2022
// URL: https://codingcompetitions.withgoogle.com/codejam/round/0000000000876ff1/0000000000a4672b
// Memory Limit: 1024 MB
// Time Limit: 5000 ms
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
#define pb push_back

#define forn(i,a,b) for (int i = (a); i < (b); ++i)
#define rofn(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define rep(n) for (int _ = 0; _ < n; _++)
#define each(x, a) for (auto& x: a)

const int INF = INT_MAX >> 1;
const int N = 1000000;

void solve(){
	int C = INF, M = INF, Y = INF, K = INF, c, m, y, k;
	forn(i, 0, 3){
		cin >> c >> m >> y >> k;
		C = min(C, c); M = min(M, m); Y = min(Y, y); K = min(K, k);
	}
	if (C + M + Y + K < N){
		cout << "IMPOSSIBLE\n";
		return;
	}
	K = max(0, N - C - M - Y);
	Y = max(0, N - C - M - K);
	M = max(0, N - C - Y - K);
	C = max(0, N - M - Y - K);
	cout << C << " " << M << " " << Y << " " << K << "\n";
	return;
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    forn(t, 1, T+1){
    	cout << "Case #" << t << ": ";
    	solve();
    }
}
