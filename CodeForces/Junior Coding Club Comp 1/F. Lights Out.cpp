// Problem: F. Lights Out
// Contest: Codeforces - Junior Coding Club - Comp 1
// URL: https://codeforces.com/gym/382346/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-05-20 15:47:42
// 
// Powered by CP Editor (https://cpeditor.org)

// https://codeforces.com/profile/Intellegent <3

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double db;
typedef string str;

#define mp make_pair
#define f first
#define s second

#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsor(x) sort(x.rbegin(), x.rend())
#define pb push_back

#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

const int mod = 1e9+7;
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    vector<vector<int> > a(3, vector<int> (3));
    for (int i = 0; i < 3; i++){
    	for (int j = 0; j < 3; j++){
    		cin >> a[i][j];
    		a[i][j] %= 2;
    	}
    }
    vector<vector<int> > res(3, vector<int> (3));
    for (int i = 0; i < 3; i++){
    	for (int j = 0; j < 3; j++){
    		for (int k = 0; k < 4; k++){
    			int ni = i + dx[k], nj = j + dy[k];
    			if (0 <= ni && ni < 3 && 0 <= nj && nj < 3){
    				res[ni][nj] += a[i][j];
    			}
    		}
    		res[i][j] += a[i][j];
    	}
    }
    for (int i = 0; i < 3; i++){
    	for (int j = 0; j < 3; j++){
    		cout << !(res[i][j] % 2);
    	}
    	cout << "\n";
    }
}
