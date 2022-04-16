// Problem: Binary Mismatch
// Contest: CodeChef - Practice
// URL: https://www.codechef.com/problems/BINMIS
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
	str s;
	cin >> s;
	if (n%2){
		cout << "NO\n";
		return;
	}
	int cnt = 0;
	forn(i, 0, n){
		if (s[i]-'0') cnt++;
		else cnt--;
	}
	if (cnt == 0){
		cout << "YES\n";
		cout << "1 " << n << "\n";
		return;
	}
	bool flipped = false;
	if (cnt < 0) {
		flipped = true;
		cnt = -cnt;
	}
	cnt /= 2;
	int bst = 0, sum = -INF, j = 0, l = 0;
	// cout << cnt << " " << flipped <<  "\n";
	forn(i, 0, n){
		int cur = 0;
		if ((s[i] - '0') ^ flipped) cur++;
		else cur--;
		
		if (cur > sum + cur){
			j = i;
			sum = cur;
		}
		else{
			sum += cur;
		}
		if (sum > bst){
			l = j;
			bst = sum;
		}
		// cout << cur << " " << sum << " " << bst << "\n";
		if (bst == cnt){
			cout << "YES\n";
			cout << l + 1 << " " << i + 1 << "\n";
			return;
		}
	}
	cout << "NO\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--){
    	solve();
    }
}
