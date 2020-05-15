//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description :==============================================================
//             : Sort input side in decending order. Pic max three sides which form a valid traingle.  
// Link        : https://www.hackerrank.com/challenges/maximum-perimeter-triangle/problem
// T.C         : O(n(lonN)) if merge sort
// A.S         : O(n) if merge  sort
// Note        : Is this algorithm greedy??
//============================================================================
#include<bits/stdc++.h>
using namespace std;
//define
// Fast I/O
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

bool comp(int a,int b){
    return a>b;
}

// math valid trangle by side. google it....
bool isValid(int a,int b,int c){
    return a+b>c&&a+c>b&&b+c>a;
}

vector<int> maximumPerimeterTriangle(vector<int> &sticks) {
    sort(sticks.rbegin(), sticks.rend());
    for(int i = 2; i < sticks.size(); i++)
        if(sticks[i] + sticks[i - 1] > sticks[i - 2])
            return {sticks[i], sticks[i - 1], sticks[i - 2]};
    return {-1};
}

int main() {
    cout<<"Started\n";
	// I/O
	IOS;
    #ifndef ONLINE_JUDGE 
	    // For getting input from input.txt file 
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\input.txt", "r", stdin); 
	    // Printing the Output to output.txt file 
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\output.txt", "w", stdout); 
    #endif 
    
    int n;
    cin >> n;
    vector<int> sticks(n);
    for(auto &stick : sticks)
        cin >> stick;
    for(auto &side : maximumPerimeterTriangle(sticks))
        cout << side << " ";
    cout << endl;
}