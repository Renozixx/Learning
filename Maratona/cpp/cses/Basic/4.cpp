#include <bits/stdc++.h>
#include <string.h>

using namespace std;

#define MAXN 200020

long long teste[MAXN];

int main() {
    unsigned long long max = 0;
    long long n, sub, prev, next;

    cin >> n;

    cin >> prev;
    for(int i = 0; i < n-1; i++){
        cin >> next;
        sub = prev - next;

        if(sub > 0){
            max += sub;
            prev = sub+next;
        } else {
            prev = next;
        }
    }

    cout << max << endl;
    return 0;
}