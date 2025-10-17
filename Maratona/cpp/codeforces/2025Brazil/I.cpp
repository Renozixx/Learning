#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

long long stars[MAXN][2];

long long euclidian(long long x[2], long long y[2]){
    return sqrt(pow(x[0] - y[0], 2) + pow(x[1] - y[1], 2));
}

int main(){
    int n, i;
    long long cord1[2], rad, temp, ans;
    cin >> n;

    for(i = 0; i < n; i++){
        cin >> stars[i][0] >> stars[i][1];
    }

    i=0;
    
    temp = euclidian(stars[i], stars[i+1]);
    ans = temp--;


    while (ans != 0)
    {
        rad = ans;
        for(i = 0; i < n-1; i++){
            temp = euclidian(stars[i], stars[i+1]);
            if(rad >= temp){
                i--;
                break; 
            }
            rad = temp - rad;
        }


        if(i == n-1){
            break;
        }
        ans--;
    }
    
    if(ans == 0){
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }
}