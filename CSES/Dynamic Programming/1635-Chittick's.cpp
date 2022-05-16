// Problem: Coin Combinations I
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1635
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// https://codeforces.com/profile/original_name153 - my waifu

#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int add(int a, int b){
    return (1LL * a + b) % MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
      
    int n, x;
    cin >> n >> x;
    
    int a[n];
    for (int i = 0; i < n; i++){
    	cin >> a[i];
    }
    
    int dp[x+1];
    memset(dp, 0, sizeof dp);
    
    dp[0] = 1;
    for (int i = 0; i < x; i++){
        for (int j = 0; j < n; j++){
            if (i + a[j] > x) continue;
            dp[i + a[j]] = add(dp[i + a[j]], dp[i]);
        }
    }
    
    cout << dp[x];
}