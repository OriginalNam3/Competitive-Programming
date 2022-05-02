#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    long long sum = 0;
    for (int &x: a){
    	cin >> x;
    	sum += x;
    }
    
    if (sum < n){
    	cout << -1;
    	return 0;
    }
    
    sort(a.begin(), a.end());
    
    sum = 0;
    int i = m-1;
    while (i >= 0){
    	sum += a[i];
    	if (sum >= n){
    		cout << m - i;
    		return 0;
    	}
    	i--;
    }
    cout << -1;
    return 0;
}
