#include <iostream>
using namespace std;
 
int main() {
 
    /**
     * Escreva a sua solução aqui
     * Code your solution here
     * Escriba su solución aquí
     */
    int T = 1, A = 1, B = 2, C = 3, D = 2, E = 1, R = 0;
    cin >> T;
    cin >> A >> B >> C >> D >> E;
    if(A == T) R++;
    if(B == T) R++;
    if(C == T) R++;
    if(D == T) R++;
    if(E == T) R++;
    cout << R;
    return 0;
}