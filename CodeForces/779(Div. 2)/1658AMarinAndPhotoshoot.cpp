// Problem: A. Marin and Photoshoot
// Contest: Codeforces - Codeforces Round #779 (Div. 2)
// URL: https://codeforces.com/contest/1658/problem/A
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

#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define pb push_back

#define fr(i,a,b) for (int i = (a); i < (b); ++i)
#define rf(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define each(x, a) for (auto& x: a)

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
    	int n, i = 0, cnt = 0;
    	cin >> n;
    	str s;
    	cin >> s;
    	while (i < n - 1) {
    		if (s[i] == '0' && s[i] == s[i+1]) {
    			cnt+=2;
    		}
    		if (i > 0)if (s[i] == '1' && s[i-1] == '0' && s[i-1] == s[i+1]) cnt++;
    		i++;
    	}
    	cout << cnt << "\n";
    }
}
