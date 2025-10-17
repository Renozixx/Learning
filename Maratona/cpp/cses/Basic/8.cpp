#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

int main(){
    unsigned long long ans = 1; 
    long n = 0;

    cin >> n;

    cout << n << endl;

    for(int i = 1; i < n; i++){ 
        cout << ans << endl;
        ans *= 2;
        ans %= MOD;
    }

    cout << ans << endl;

    cout << ans % MOD << endl;
    return 0;
}