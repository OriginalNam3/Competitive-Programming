// Problem: D2. Prefix-Suffix Palindrome (Hard version)
// Contest: Codeforces - Codeforces Global Round 7
// URL: https://codeforces.com/problemset/problem/1326/D2
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

string pal(string s){
	int n = s.size(), i = 1, c = 0;
	vi p(n); p[0] = 0;
	while (i < n){
		cout << c << " " << i << " chars: " << s[c] << " " << s[i] << "\n";
		if (s[i] == s[c]){
			c++;
			p[i] = c;
			i++;
		}
		else{
			if (c > 0){
				c = p[c-1];
			}
			else{
				p[i] = 0;
				i++;
			}
		}
	}
	int ans = p[n-1];
	ans = min(ans, n/2);
	return s.substr(0, ans);
}

void solve(){
	str s;
	cin >> s;
	int n = s.size();
	int j = 0;
	while (s[j] == s[n-1-j]) j++;
	if (j > n/2){
		cout << s << "\n";
		return;
	}
	str a = s.substr(j, n - 2 * j), ans = s.substr(0, j), temp = s.substr(0, j);
	reverse(all(temp));
	
	str rev = a;
	reverse(all(rev));
	
	str pre = pal(a + "#" + rev);
	str suf = pal(rev + "#" + a);
	
	if (pre.size() > suf.size()){
		ans += pre + temp;
	}
	else{
		ans += suf + temp;
	}
	cout << ans << "\n";
	return;
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--){
    	solve();
    }
}
