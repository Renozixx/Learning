#include <bits/stdc++.h>

using namespace std;

#define MAXN 1001000

unsigned int set1[MAXN];
unsigned int set2[MAXN];

int main(){
    unsigned int n, num, n1 = 0, n2 = 0;
    long long sum1 = 0, sum2 = 0;

    cin >> n;

    for(int i = n; i > 0; i--){
        if(sum1 < sum2){
            set1[n1] = i;
            sum1 += i;
            n1++;
        } else {
            set2[n2] = i;
            sum2 += i;
            n2++;
        }
    }
    if(sum1 == sum2){
        cout << "YES" << endl;
        cout << n1 << endl;
        n1-=1;
        for(int i = n1; i >= 0; i--){
            cout << set1[i] << " ";
        }
        cout << endl;
        cout << n2 << endl;
        n2-=1;
        for(int i = n2; i >= 0; i--){
            cout << set2[i] << " ";
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}