//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : https://www.hackerrank.com/challenges/equal-stacks/problem
// T.C         : O()
// A.S         : O()
//============================================================================
/*
How about this logic:

Step I. get the 3 array and reverse them, create a new array out of an existing array with each element is sum of all the previous elements. eg: [3,2,1,1,1] -> [1,1,1,2,3] -> [1,2,3,5,8]

So the 3 new array formed would be [1,2,3,5,8] [2,5,9] [1,5,6,7]

Step II. Again reverse the array [8,5,3,2,1] [9,5,2] [7,6,5,1]

Step III. Take the smallest array i.e. [9,5,2] traverse the smallest array and search element in the other 2 array - if the element is existing in other 2 array, STOP there and return the number.

Eg. Here I start with elem - 9 : Which is not existing in other 2 array. Next I start with elem - 5 : it is existing in other 2 array.

Wolla! 5 is my NUMBER!
*/
/*
Start by calculating the initial height of each stack, marking the numbers of the topmost cylinders.

If all three heights are equal, then you have your answer (i.e., the current height is the maximal height).
If the heights are not equal, then remove the top cylinder from whichever stack is tallest.
Now that one of the heights has changed, repeat the above steps until you have an answer.
*/
#include<bits/stdc++.h>
using namespace std;
//define
int arr1[100005];
int arr2[100005];
int arr3[100005];
// Fast I/O
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)
#define N 100000+10

int a[N];
int b[N];
int c[N];

// driver code
int main(){
	cout<<"Started\n";
	// I/O
	IOS;
    #ifndef ONLINE_JUDGE 
	    // For getting input from input.txt file 
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\input.txt", "r", stdin); 
	    // Printing the Output to output.txt file 
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\output.txt", "w", stdout); 
    #endif 
    
    int n1;
    int n2;
    int n3;
    cin >> n1 >> n2 >> n3;
    int h1 = 0, h2 = 0, h3 = 0; // heights of the 3 stacks
    vector<int> tower1(n1);
    for(int i = 0; i < n1; i++){
       cin>>tower1[i];
       h1 += tower1[i];
    }
    vector<int> tower2(n2);
    for(int i = 0; i < n2; i++){
       cin>>tower2[i];
       h2 += tower2[i];
    }
    vector<int> tower3(n3);
    for(int i = 0; i < n3; i++){
       cin>>tower3[i];
       h3 += tower3[i];
    }
    // Use a greedy approach, always remove cylinders from the tallest tower until all towers
    // have the same height.
    bool equalHeight = false;
    if(h1 == h2 && h2 == h3) {
        equalHeight = true;
    }
    int r1 = 0, r2 = 0, r3 = 0; // Store the indices of which cylinder to remove
    while(!equalHeight) {
        if(h1 >= h2 && h1 >= h3) {
            h1 -= tower1[r1];
            r1++;
        } else if(h2 >= h1 && h2 >= h3) {
            h2 -= tower2[r2];
            r2++;
        } else if(h3 >= h1 && h3 >= h2) {
            h3 -= tower3[r3];
            r3++;
        }
        if((h1 == h2 && h2 == h3) || (h1 == 0 && h2 == 0 && h3 == 0)) {
            equalHeight = true;
        }
    }
    cout<<h1;
}