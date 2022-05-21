// Problem: C. Queue at the School
// Contest: Codeforces - Junior Coding Club - Comp 1
// URL: https://codeforces.com/gym/382346/problem/C
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

void solve(){
	
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, t;
    cin >> n >> t;
    vector<char> a(n), b(n);
    for (char &x: a) cin >> x;
    for (int i = 0; i < t; i++){
    	for (int j = 0; j < n; j++){
    		if (j < n - 1 && a[j] == 'B' && a[j + 1] == 'G'){
    			b[j] = 'G'; 
    			b[j+1] = 'B';
    			j++;
    		}
    		else{
    			b[j] = a[j];
    		}
    	}
    	for (int j = 0; j < n; j++){
    		a[j] = b[j];
    	}
    }
    for (char x: b) cout << x;
}
