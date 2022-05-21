// Problem: A. Young Physicist
// Contest: Codeforces - Junior Coding Club - Comp 1
// URL: https://codeforces.com/gym/382346/problem/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-05-20 15:47:41
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
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < n; i++){
    	int x, y, z;
    	cin >> x >> y >> z;
    	a += x; b += y; c += z;
    }
    if (a == 0 && b == 0 && c == 0){
    	cout << "YES\n";
    }
    else{
    	cout << "NO\n";
    }
}
