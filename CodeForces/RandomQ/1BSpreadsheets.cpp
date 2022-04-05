// Problem: B. Spreadsheets
// Contest: Codeforces - Codeforces Beta Round #1
// URL: https://codeforces.com/problemset/problem/1/B
// Memory Limit: 64 MB
// Time Limit: 10000 ms
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

const int mod = 1e9+7;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

void solve(){
	str s;
	cin >> s;
	bool C = false, num = false;
	int m = s.size();
	forn(i, 1, m){
		if (!C && s[i]-'0' < 10) num = true;
		if (s[i] == 'C') C = true;
	}
	if (s[0] == 'R' && C && num){
		int r = 0, c = -1;
		forn(i, 1, m){
			if (s[i] - '0' < 10){
    			if (c == -1){
    				r *= 10;
    				r += s[i]-'0';
    			}
    			if (c >= 0){
    				c *= 10;
    				c += s[i]-'0';
    			}
    		}
    		if (s[i] == 'C') c = 0;
		}
		str o = "";
		while (c > 0){
			c--;
			o = char(('A'+(c % 26))) + o;
			c /= 26;
		}
		cout << o << r << "\n";
		return;
	}
	int r = 0, c = 0;
	forn(i, 0, m){
		if (s[i]-'0' > 9){
			c *= 26;
			c += s[i] - 'A' + 1;
		}
		else{
			r *= 10;
			r += s[i] - '0';
		}
	}
	cout << "R" << r << "C" << c << "\n";
	return;
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    forn(i, 0, n){
    	solve();
    }
}
