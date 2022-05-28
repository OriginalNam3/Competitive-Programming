// Problem: B. Color the Fence
// Contest: Codeforces - Codeforces Round #202 (Div. 2)
// URL: https://codeforces.com/problemset/problem/349/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-05-21 21:38:03
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

void solve(){
	
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(9);
    for (int &x: a) cin >> x;
    int p = 0;
    for (int i = 8; i >= 0; i--){
    	p = max(p, n / a[i]);
    }
    if (p == 0){
    	cout << -1;
    	return 0;
    }
    vector<int> b;
    for (int i = 0; i < 9; i++){
    	if (n / a[i] == p){
    		b.pb(i);
    	}
    }
    vector<int> num(p, -1);
    for (int x: b){
    	vector<int> temp(p, x);

    	int r = n % a[x];
    	for (int i = 0; i < p && r > 0; i++){
			for (int j = 8; j > x; j--){
				if (a[j] - a[x] <= r){
					r -= a[j] - a[x];
					temp[i] = j;
					break;
				}
			}
		}
		
		for (int i = 0; i < p; i++){
			if (temp[i] == num[i]) continue;
			if (temp[i] > num[i]){
				for (int j = i; j < p; j++){
					num[j] = temp[j];
				}
			}
			break;
		}
		
    }
    for (int i = 0; i < p; i++){
    	cout << num[i] + 1;
    }
}
