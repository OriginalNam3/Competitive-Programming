// Problem: B. The least round way
// Contest: Codeforces - Codeforces Beta Round #2
// URL: https://codeforces.com/problemset/problem/2/B
// Memory Limit: 64 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = long double; // or double if tight TL
using str = string;

using pi = pair<int,int>;
#define mp make_pair
#define f first
#define s second

using pqi = priority_queue<int>;
using pqll = priority_queue<long long>;
using qi = queue<int>;
using qll = queue<long long>;
using vi = vector<int>;
using vb = vector<bool>;
using vpi = vector<pi>;

#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define pb push_back

#define fr(i,a,b) for (int i = (a); i < (b); ++i)
#define rf(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define each(x, a) for (auto& x: a)

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int m2[n][n];
	int m5[n][n];
    fr(i, 0, n){
    	fr(j, 0, n){
    		int x;
    		cin >> x;
    		m2[i][j] = 0;
    		m5[i][j] = 0;
    		while (x % 2 == 0){
    			x /= 2;
    			m2[i][j]++;
    		}
    		while (x % 5 == 0) {
    			x /= 5;
    			m5[i][j]++;
    		}
    	}
    }
	
	int dp[n][2];
	str dpp[n][2];
	dp[0][0] = m2[0][0];
	dpp[0][0] = "";
	dp[0][1] = m5[0][0];
	dpp[0][1] = "";
	fr(i, 1, n){
		dp[i][0] = dp[i-1][0] + m2[i][0];
		dpp[i][0] = dpp[i-1][0] + "D";
		dp[i][1] = dp[i-1][1] + m5[i][0];
		dpp[i][1] = dpp[i-1][1] + "D";
	}
    fr(i, 1, n){
		dp[0][0] += m2[0][i];
		dpp[0][0] += "R";
		dp[0][1] += m5[0][i];
		dpp[0][1] += "R";
    	fr(j, 1, n){
    		if (dp[j-1][0] > dp[j][0]) {
    			dp[j][0] += m2[j][i];
    			dpp[j][0] += "R";
    		}
    		else {
    			dp[j][0] = dp[j-1][0] + m2[j][i];
    			dpp[j][0] = dpp[j-1][0] + "D";
    		}
    		if (dp[j-1][1] > dp[j][1]) {
    			dp[j][1] += m5[j][i];
    			dpp[j][1] += "R";
    		}
    		else {
    			dp[j][1] = dp[j-1][1] + m5[j][i];
    			dpp[j][1] = dpp[j-1][1] + "D";
    		}
    	}
    }
    
    if (dp[n-1][0] < dp[n-1][1]) {
    	cout << dp[n-1][0] << "\n";
    	cout << dpp[n-1][0] << "\n";
    }
    else {
    	cout << dp[n-1][1] << "\n";
    	cout << dpp[n-1][1] << "\n";
    }
}
