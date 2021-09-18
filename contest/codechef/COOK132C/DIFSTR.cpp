//============================================================================
// Name        :
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use, contribute and distribute it.
// Description : https://www.codechef.com/COOK132C/problems/DIFSTR
//             : https://discuss.codechef.com/t/difstr-editorial/93707/5
// T.C         : O()
// A.S         : O()
//============================================================================

#include <bits/stdc++.h>
using namespace std;
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr)

void file_io()
{
#ifndef ONLINE_JUDGE
    freopen("/home/rahul/Desktop/Algorithm/input.txt", "r", stdin);
    freopen("/home/rahul/Desktop/Algorithm/output.txt", "w", stdout);
#endif
}

int main()
{
    IOS;
    file_io();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        unordered_map<string, int> ump;

        for (int i = 0; i < n; i++)
        {
            string temp;
            cin >> temp;
            ump[temp]++;
        }

        string temp(n, '1');

        /*
        https://en.wikipedia.org/wiki/Pigeonhole_principle#:~:text=If%20there%20are%20n%20people,the%20same%20number%20of%20people.&text=Since%20each%20person%20shakes%20hands,there%20are%20n%20possible%20holes.
        
        There are n string of length n. If we generate n+1 different strings on lenght n, 
        then atleast one of n+1 strings will be unique, according to Pigeonhole_principle. 

        Here, initialy we'll take a string of only 1's and length n.
        temp = 111
               011
               101
               110
         
        Here, we have generate n+1 unique  strings of lenght n.
        */
        if (ump.find(temp) == ump.end())
        {
            cout << temp << endl;
            continue;
        }
        for (int i = 1; i < n; i++)
        {
            temp[i] = '0';
            if (ump.find(temp) == ump.end())
            {
                cout << temp << endl;
                break;
            }

            temp[i] = '1';
        }
    }
    return 0;
}