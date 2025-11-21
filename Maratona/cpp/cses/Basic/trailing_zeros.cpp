#include <bits/stdc++.h>
using namespace std;

// Percebi que minha base matematica ta muito fraca, falta muito arroz com feijao...

int main() {
    long n, current = 5, answer = 0;
    cin >> n;
    while (current <= n) {
        answer += n / current;
        current *= 5;
    }
    cout << answer << endl;
    return 0;
}