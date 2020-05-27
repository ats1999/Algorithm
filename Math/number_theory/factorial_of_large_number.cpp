//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Find factorial of large number, whose value can not be stored on machine.
// T.C         : O()
// A.S         : O()
//============================================================================
#include<bits/stdc++.h>
using namespace std;
//define
#define MAX 500
// Fast I/O
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

/**
 * This function multiply two larger numbber. 
 * @param x first number
 * @param res[] secend number stored in reverse order. 
 * @param res_size size of res[]
 * @return new size of res[] after multiplying. 
 */
int multiply(int x,int res[],int res_size){
    int carry=0;

    // one by one multiply x with every digit of res[]
    for(int i=0;i<res_size;i++){
        int prod=res[i]*x+carry;

        // store last digit of prod in res[]
        res[i]=prod%10;

        // update carry value. 
        carry=prod/10;
    }

    // put carry in res[] and update res_siez if required.
    while(carry){
        res[res_size]=carry%10;
        carry/=carry;
        res_size++;
    }
    return res_size;
}

/**
 * This method finds factorial of large number. 
 * This method internally call multiply() method. 
 * @param n input number. 
 * @return none
 */
void factoral(int n){
    int res[MAX];

    // initialize the result
    res[0]=1;
    int res_size=1;

    // apply simple factorial formula
    for(int i=2;i<=n;i++){
        res_size=multiply(i,res,res_size);
    }

    cout<<"Factorial of given number is : ";
    for(int i=res_size-1;i>=0;i--){
        cout<<res[res_size];
    }
}

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
    int res[20];
    memset(res,1,sizeof res);
     res[0]=9;
      res[1]=8; res[2]=7; res[3]=0;
    int x=45;
    //multiply(x,res,20);
    cout<<"Print: ";
    for(int i=19;i>=0;i--)
        if(res[i]!=1)
            cout<<res[i];
	return 0;
}