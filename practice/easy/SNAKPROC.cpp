//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 17
// Copyright   : Everyone can freely use and distribute it.
// Description : https://www.codechef.com/problems/SNAKPROC
// T.C         : O()
// A.S         : O()
//============================================================================

#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

void file_io(){
#ifndef ONLINE_JUDGE
    freopen("/home/rahul/Desktop/Algorithm/input.txt", "r", stdin);
    freopen("/home/rahul/Desktop/Algorithm/output.txt", "w", stdout);
#endif
}

int main(){
    IOS; file_io(); int t; cin>>t;
    while(t--){
        int l; cin>>l;
        string str; cin>>str;
        
        char prev = '0';
        bool invalid = false;

        for(char ch:str){
            if(ch == '.')
                continue;

            // two snakes entering at the same time
            if(ch  == 'H' && prev == 'H'){
                invalid =true;
                break;
            }

            if(ch == 'H'){
                prev = 'H';
                continue;
            }

            if(prev != 'H'){
                invalid = true;
                break;
            }

            prev = '0';
        }

        if(invalid || prev != '0'){
            cout<<"Invalid"<<endl;
        }else{
            cout<<"Valid"<<endl;
        }
    }
    return 0;
}