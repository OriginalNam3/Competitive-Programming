// Problem: C. Alice and the Cake
// Contest: Codeforces - Codeforces Round #778 (Div. 1 + Div. 2, based on Technocup 2022 Final Round)
// URL: https://codeforces.com/contest/1654/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

bool cmp (int a, int b) {
	return a > b;
}

int main() {
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> a(n);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
        	cin >> a[i];
        	sum += a[i];
        }
        sort(a.begin(), a.end(), cmp);
        priority_queue<long long> q;
        q.push(sum);
        
        bool ok = true;
        int i = 0;
        while (ok && !q.empty()) {
        	long long b = q.top();
        	q.pop();
        	if (b < a[i]) ok = false;
        	if (b == a[i]) {
        		i++; continue;
        	}
        	q.push((b/2) + (b%2));
        	q.push(b/2);
        }
        cout << (ok ? "YES": "NO") << "\n";
    }
    return 0;
}