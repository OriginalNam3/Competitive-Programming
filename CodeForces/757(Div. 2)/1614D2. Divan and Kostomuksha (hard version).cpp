// Problem: D1. Divan and Kostomuksha (easy version)
// Contest: Codeforces - Brogrammer contest #something (I forgor)
// URL: https://codeforces.com/contest/1614/problem/D2
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
// Date & Time: 2022-05-23 18:55:32
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



int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    int mx = 0;
    for (int &x: a) {
    	cin >> x;
    	mx = max(mx, x);
    }
    
    vector<int> cnt(mx + 1);
    for (int x: a) cnt[x] ++;
    vector<bool> not_prime(mx + 1);
    vector<int> primes;
    for (int i = 2; i <= mx; i++){
    	if (!not_prime[i]){
    		primes.pb(i);
    		for (int j = i * 2; j <= mx; j += i){
    			not_prime[j] = 1;
    		}
    	}
    }
    
    for (int p: primes){
    	for (int x = mx / p; x >= 1; x--){
    		cnt[x] += cnt[x * p];
    	}
    }
    
    
    vector<ll> dp(mx + 1);
    for (int x = mx; x >= 1; x--){
    	dp[x] = 1LL * x * cnt[x];
    	for (int p: primes){
    		int nx = x * p;
    		if (nx > mx) break;
			dp[x] = max(dp[x], dp[nx] + 1LL * x * (cnt[x] - cnt[nx]));
    	}
    }
    
    cout << dp[1];
}
