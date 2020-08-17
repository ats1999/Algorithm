#include<bits/stdc++.h>
using namespace std;

int main(){
    // adjacent difference
    vector<int>v{1,2,2,3,4,4,5};
    auto res = adjacent_find(v.begin(),v.end());
    if(res!=v.end())
    cout<<*res;
    else cout<<"End";
}
