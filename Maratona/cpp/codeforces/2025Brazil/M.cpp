#include <bits/stdc++.h>
using namespace std;

#define MAXN 100300

vector<long long> v1, v2;

vector<int> indexes;

int main(){
    int n, k;
    long long min, tempMin, o = MAXN, tempk, arrMin;

    cin >> n >> k;

    for(int i = 0; i < n; i++){
        cin >> o;
        v1.push_back(o);
        if(min > o){
            indexes.clear();
            indexes.push_back(i);
            min = o;
        } else if (min == o){
            indexes.push_back(i);
        }
    }
    
    int qnt = indexes.size();

    for(qnt; qnt > 0; qnt--)
    {
        v2 = v1;
        for(int i = indexes[qnt-1]; i >= 0 || tempk != 0; i--)
        {
            v2[i] = v2[i]+k;
            k--;
        }
    }

    return 0;
}