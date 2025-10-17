#include <bits/stdc++.h>

using namespace std;

int main() {
    long t;
    unsigned long long x,y;

    cin >> t;

    for(int i = 0; i < t; i++){
        cin >> x >> y; 
        if(x >= y){
            if(x % 2 == 0){
                x = pow(x, 2);
                x = x - y + 1;
                cout << x << endl;
            } else {
                x = (pow(x, 2) - x) - (x - y) + 1;
                cout << x << endl;
            }
        } else {
            if(y % 2 == 0){
                y = (pow(y, 2) - y) - (y - x) + 1;
                cout << y << endl;
            } else {
                y = (pow(y, 2) - 2 * x) + y;
                cout << y << endl;
            }
        }
    }

    // Esse codigo eu errei pq eu tive hyperfoco novamente eu tenho que
    // Treinar esquecer a questão e ir de go next as vezes para evitar
    // Que esse tipo de cenario aconteca em um contexto verdadeiramente 
    // Competitivo

    return 0;
}