// Problem: Labyrinth
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1193
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Date & Time: 2022-05-20 20:05:59
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

char moves[4] = {'D', 'U', 'R', 'L'};


int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int> > a(n, vector<int> (m)), b(n, vector<int> (m));
    
    int si, sj, ei, ej;
    for (int i = 0; i < n; i++){
    	string row; cin >> row;
    	for (int j = 0; j < m; j++){
    		if (row[j] == 'A'){
    			si = i; sj = j;
    			a[i][j] = 1;
    		}
    		if (row[j] == 'B'){
    			ei = i; ej = j;
    			a[i][j] = 1;
    		}
    		if (row[j] == '.'){
    			a[i][j] = 1;
    		}
    	}
    }
    
    queue<pair<int, int> > q;
    q.push(mp(si, sj));
    while (!q.empty()){
    	int x = q.front().f, y = q.front().s;
    	q.pop();
    	if (x == ei && y == ej){
    		str ans = ""; 
    		while (x != si || y != sj){
    			ans += moves[b[x][y]];
    			int nx = x - dx[b[x][y]], ny = y - dy[b[x][y]];
    			x = nx, y = ny;
    		}
    		cout << "YES\n" << ans.size() << "\n";
    		for (int i = ans.size()-1; i >= 0; i--){
    			cout << ans[i];
    		}
    		return 0;
    	}
    	for (int i = 0; i < 4; i++){
    		int nx = x + dx[i], ny = y + dy[i];
    		if (0 <= nx && nx < n && 0 <= ny && ny < m && a[nx][ny]){
    			b[nx][ny] = i;
    			a[nx][ny] = 0;
    			q.push(mp(nx, ny));
    		}
    	}
    }
    cout << "NO";
}
