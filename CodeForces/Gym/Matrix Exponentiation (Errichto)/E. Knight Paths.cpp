// Problem: E. Knight Paths
// Contest: Codeforces - Matrix Exponentiation
// URL: https://codeforces.com/gym/102644/problem/E
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

const int mod = 1e9 + 7;
ll add(ll a, ll b) {return (a + b) % mod;}
ll mul(ll a, ll b) {return (a * b) % mod;}

int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int k;
    cin >> k;
    
    vector<unsigned int> res(65);
    vector<vector<unsigned int> > m(65, vector<unsigned int>(65));
    forn(i, 0, 8) forn(j, 0, 8){
		forn(k, 0, 8){
			int ni = i + dx[k], nj = j + dy[k];
			if (0 <= ni && ni < 8 && 0 <= nj && nj < 8){
				m[8*i + j][8*ni + nj] += 1; // mapping all cells to the next
			}
		}
    }
    
    forn(i, 0, 65){
    	m[i][64] = 1; // map all cells to answer cell
    }
    res[0] = 1;
    k++;
    while (k > 0){
    	if (k & 1){
    		vector<unsigned int> product(65);
    		forn(i, 0, 65) forn(j, 0, 65){
    			product[j] += res[i] * m[i][j];
    		}
    		forn(i, 0, 65){
    			res[i] = product[i];
    		}
    	}
    	vector<vector<unsigned int> > product(65, vector<unsigned int>(65));
    	forn(i, 0, 65) forn(j, 0, 65) forn(k, 0, 65){
    		product[i][k] += m[i][j] * m[j][k];
    	}
    	forn(i, 0, 65) forn(j, 0, 65){
    		m[i][j] = product[i][j];
    	}
    	k >>= 1;
    }
    // forn(i, 0, 64){
    	// res[64] += res[i];
    // }
    cout << res[64];
    
    // vector<vector<unsigned int> > dp(8, vector<unsigned int>(8));
    // dp[0][0] = 1;
//     
	// k++;
	// unsigned int ans = 0;
	// while(k--){
		// vector<vector<unsigned int> > ndp(8, vector<unsigned int> (8));
		// forn(i, 0, 8) forn(j, 0, 8){
			// if (!dp[i][j]) continue;
			// forn(k, 0, 8){
				// int ni = i + dx[k], nj = j + dy[k];
				// if (0 <= ni && ni < 8 && 0 <= nj && nj < 8){
					// ndp[ni][nj] += dp[i][j];
				// }
			// }
		// }
		// forn(i, 0, 8) forn(j, 0, 8) {
			// ans += dp[i][j];
			// dp[i][j] = ndp[i][j];
		// }
	// }
	// cout << ans;
}
