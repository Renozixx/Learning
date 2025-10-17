#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, num;
    long long total;
    double partial;

    cin >> n;

    partial = (float)(1+n)/2;

    total = partial*n;

    for(int i = 0; i < n-1; i++)
    {
        cin >> num;
        total -= num;
    }

    cout << total << endl;
}