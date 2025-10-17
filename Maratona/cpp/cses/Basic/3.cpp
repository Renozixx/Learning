#include <bits/stdc++.h>
#include <string.h>

using namespace std;

#define MAXN 1001000

char teste[MAXN];

int main() {
    char t = 'D';
    long long counter = 0;
    long long tempCounter = 1;

    cin >> teste;

    for(int i = 0; i < MAXN; i++){
        if(teste[i] == t){
            tempCounter++;
        } else {
            if(tempCounter > counter){
                counter = tempCounter;
            }
            tempCounter = 1;
            t = teste[i];
        }
    }

    cout << counter << endl;
}