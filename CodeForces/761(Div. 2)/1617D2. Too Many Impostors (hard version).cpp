// Problem: D2. Too Many Impostors (hard version)
// Contest: Codeforces - Codeforces Round #761 (Div. 2)
// URL: https://codeforces.com/contest/1617/problem/D2
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// Date & Time: 2022-05-26 08:45:23
// 
// Powered by CP Editor (https://cpeditor.org)

// https://codeforces.com/profile/Intellegent husbando <3

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

bool q(int a, int b, int c){
	cout << "? " << a + 1 << " " << b + 1 << " " << c + 1 << "\n";
	cout.flush();
	bool res;
	cin >> res;
	return res;
}

void solve(){
	int n;
    cin >> n;
    vector<bool> a(n);
    
    
    for (int i = 0; i < n; i += 3){
    	a[i] = q(i, i + 1, i + 2);
    }
    
    vector<bool> ans(n);
    
    int o, z;
    for (int i = 0; i < n - 3; i+= 3){
    	if (a[i] ^ a[i + 3]){
    		bool b = q(i + 1, i + 2, i + 3);
    		if (b ^ a[i]){
    			if (b) {
    				o = i + 3;
    				z = i;
    			}
    			else{
    				o = i;
    				z = i + 3;
    			}
    		}
    		else{
    			bool c = q(i + 2, i + 3, i + 4);
    			if (c ^ b){
    				if (b) {
	    				o = i + 1;
	    				z = i + 4;
	    			}
	    			else{
	    				o = i + 4;
	    				z = i + 1;
	    			}
    			}
    			else{
    				if (c){
    					o = i + 2;
    					z = i + 5;
    				}
    				else{
    					o = i + 5;
    					z = i + 2;
    				}
    			}
    		}
    		ans[o] = 1; ans[z] = 0;
    		for (int j = 0; j < 6; j++){
    			if (j + i == o || j + i == z){
    				continue;
    			}
    			ans[j + i] = q(j + i, o, z);
    		}
    		break;
    	}
    }
    
    // debug(o) debug(z)
    for (int i = 0; i < n; i+= 3){
    	if ((i <= o && o < i + 3) || (i <= z && z < i + 3)) continue;
    	if (a[i]){
    		if (!q(i, i + 1, z)){
    			ans[i + 2] = 1;
    			if (q(i, o, z)){
    				ans[i] = 1;
    				ans[i + 1] = 0;
    			}
    			else{
    				ans[i] = 0;
    				ans[i + 1] = 1;
    			}
    		}
    		else{
    			ans[i] = 1;
    			ans[i + 1] = 1;
    			if (q(i + 2, o, z)){
    				ans[i + 2] = 1;
    			}
    			else{
    				ans[i + 2] = 0;
    			}
    		}
    	}
    	else{
    		if (q(i, i + 1, o)){
    			ans[i + 2] = 0;
    			if (q(i, o, z)){
    				ans[i] = 1;
    				ans[i + 1] = 0;
    			}
    			else{
    				ans[i + 1] = 1;
    				ans[i] = 0;
    			}
    		}
    		else{
    			ans[i] = 0; ans[i + 1] = 0;
    			if (q(i + 2, o, z)){
    				ans[i + 2] = 1;
    			}
    			else{
    				ans[i + 2] = 0;
    			}
    		}
    	}
    }
    
    vector<int> impostors;
    for (int i = 0; i < n; i++){
    	if (!ans[i]) impostors.pb(i + 1);
    }
    
    cout << "! " << impostors.size() << " ";
    for (int i: impostors) cout << i << " ";
    cout << "\n";
    cout.flush();
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
