#include <bits/stdc++.h>

using namespace std;

#define MOD     1000000007

int main(){
    unsigned long long ans = 1; 
    long n = 0;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        ans *= 2;
        ans = ans % MOD;
    }
    
    cout << ans % MOD << endl;
    return 0;
}