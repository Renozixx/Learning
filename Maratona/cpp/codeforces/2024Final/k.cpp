#include <bits/stdc++.h>
using namespace std;

int main()
{
    char s[100010];
    char m;
    int k, counter = 1, op = 0, len = 1;

    cin >> k >> s;

    m = s[0];

    for(int i = 1; i < 100010; i++){
        if(s[i] != '0' && s[i] != '1')
        {
            break;
        }
        len++;
        if(s[i] != m)
        {
            counter = 1;
            m = s[i];
        } 
        else 
        {
            counter++;
            if(counter == k)
            {
                op++;
                s[i] = m == '1' ? '0' : '1';
                m = s[i];
                counter = 1;        
            }
        }
    }

    cout << op << " ";

    for(int i = 0; i < len; i++){
        cout << s[i];
    }

    cout << '\n';
    
    return 0;
}