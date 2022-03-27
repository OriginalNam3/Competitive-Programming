// Problem: B. Marin and Anti-coprime Permutation
// Contest: Codeforces - Codeforces Round #779 (Div. 2)
// URL: https://codeforces.com/contest/1658/problem/B
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

ll fact[501];
const int mod = 998244353;

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    fact[1] = 1;
    fr(i, 2, 501) {
    	fact[i] = (fact[i-1] * i) % mod;
    }
    fr(i, 2, 501) {
    	fact[i] = fact[i] * fact[i] % mod;
    }
    while (t--) {
    	int n;
    	cin >> n;
    	if (n %2 == 1) {
    		cout << "0\n";
    		continue;
    	}
    	cout << fact[n/2] << "\n";
    }
}
