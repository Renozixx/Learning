#include <bits/stdc++.h>
using namespace std;
 
int main() {
    float a, b, c;
    cin >> a;
    cin >> b;

    a = (a/11)*3.5;
    b = (b/11)*7.5;
    c = a + b;
    printf("MEDIA = %.5f\n", c);
 
    return 0;
}