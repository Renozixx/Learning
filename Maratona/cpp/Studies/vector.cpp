#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v1, v2;

    v1.push_back(10);
    v2 = v1;
    v2[0] = 5;

    cout << "v1: " << v1[0] << endl;
    cout << "v2: " << v2[0] << endl;

    // Com base no teste acima se percebe que vetores quando utilizados dessa forma não referenciam a outro vetor, eles copiam mesmo.

    return 0;
}