// Problem: C. Sereja and Brackets
// Contest: Codeforces - Codeforces Round #223 (Div. 1)
// URL: https://codeforces.com/problemset/problem/380/C
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
#define pb push_back

#define forn(i,a,b) for (int i = (a); i < (b); ++i)
#define rofn(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define rep(n) for (int _ = 0; _ < n; _++)
#define each(x, a) for (auto& x: a)

const int MAXN = 1e6 + 4;

struct seg{
	int maxseq, open, close;
};

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    str s;
    cin >> s;
    int n = s.size();
    int blog[n+1];
    blog[1] = 0;
	forn(i, 2, n+1){
		blog[i] = blog[i/2] + 1;
	}
    int mlog = blog[n]+1;
    vector<vector<seg> > st(mlog, vector<seg>(n));
	forn(i, 0, n){
		if (s[i] == '(') st[0][i].open = 1;
		else st[0][i].close = 1;
	}
	forn(j, 1, mlog) forn(i, 0, n - (1<<j) + 1){
		int mn = min(st[j-1][i].open,st[j-1][i+(1<<(j-1))].close);
		st[j][i].maxseq = st[j-1][i].maxseq + st[j-1][i+(1<<(j-1))].maxseq + mn;
		st[j][i].open = st[j-1][i].open + st[j-1][i+(1<<(j-1))].open - mn;
		st[j][i].close = st[j-1][i].close + st[j-1][i+(1<<(j-1))].close - mn;
	}
    int m;
    cin >> m;
    rep(m){
    	int l, r;
    	cin >> l >> r;
    	l--; r--;
    	seg ans = st[0][l];
    	int len = r - l, lg = blog[len]+1, i = l + 1;
    	forn(j, 0, lg){
    		if (len & 1){
    			int mn = min(ans.open, st[j][i].close);
    			ans.maxseq += st[j][i].maxseq + mn;
    			ans.open += st[j][i].open - mn;
    			ans.close += st[j][i].close - mn;
    			i += (1 << j);
    		}
    		len >>= 1;
    	}
    	cout << 2 * ans.maxseq << "\n";
    }
}
