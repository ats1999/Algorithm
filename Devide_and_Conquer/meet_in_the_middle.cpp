//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
//============================================================================
// Description : Use meet in the middle technique to reduce the time complexity of algorithm from O(2^n) to O((2^n)^1/2).
// 			   : Problem is, you have given an array and an integer X. Is there any subset in array,
//			   : whose sum is equal to X.
//			   : Naive approach is to generate all the subsets and check their sum. 
// 			   : efficient approach is to devide the array in two equal parts. 
// 				 generte all subsets of both array and their sub set sum in two list namely A and B
//               Now, iterate both the list and then check if sum is persent.   
//============================================================================
// T.C         : O(2^n)^1/2)
// A.S         : O()
//============================================================================
#include<bits/stdc++.h>
using namespace std;
#include "../print.h"
//define
/**
 * This function generates all subset in the given range.
 * @param n number of elements in the set. 
 * @param sumSets it stores all sum of all subsets of perticular array.
 * @param curSet it stores curSet.
 */
void sumOfSet(int ar[],vector<int>&sum,vector<int> cur,int index,int n){
	if(index>=n)
		return;
	
	// do not include current element in this subset
	sumOfSet(ar,sum,cur,index+1,n);
	
	// include current item in this subset
	cur.push_back(ar[index]);
	sumOfSet(ar,sum,cur,index+1,n);

	// store sum of subsets
	int suBsum=0;
	for(int i:cur)
		suBsum=suBsum+i;
	
	sum.push_back(suBsum);
}

bool MIM(int ar[],int n,int val){
	// create two list to store all sum of the subsets of both arrays
	vector<int>listA,listB;

	// temporary vector. 
	vector<int>cur;
	// divide ar[] into two array, appromexitely half in size. 
	int mid=n/2;
	int A[n],B[n-n/2];
	int i=0;
	A[0]=2,A[1]=4;
	for(;i<n/2;i++)
		A[i]=ar[i];

	int j=0;
	for(;i<n;i++){
		B[j]=ar[i];
		j++;
	}

	// get sum of subsets in listA
	sumOfSet(A,listA,cur,0,n/2);
	cur.clear();
	// get sum of subsets in listB
	sumOfSet(B,listB,cur,0,n-n/2);

	// sort listA in non-decreasing order
	sort(listA.begin(),listA.end());
	//sort ListB in non-increasing order
	sort(listB.begin(),listB.end(),greater<int>());

	/*
	set piinter b to the last element from listB and a to the first element of listA
	*a+*b equal to the desired sum then sum is found.
	if sum of both elemets is greter than desired sum the move b to the left side
	if sum of both elemets is less than desired sum the move a to the right side

	idea is, if sum if minimum element of list A and maximum element of list B is greter than the desireed sum then, 
	maximum element of list B will never give result.
	similarlay if sum of minimum element of listA and maximum element of list B is less than desired sum then,
	this combination also not give result.

	Note: We can avoid sorting if we use heap data structure. 
	It can be further optimized.	
	*/
	
	cout<<"Returning\n";
	for(auto a=listA.rbegin();a!=listA.rend();){
		for(auto b=listB.begin();b!=listB.end();){
			if((*a+*b)==val)
				return true;
			else if((*a+*b)>val)
				b++;
				else a++;
		}
	}
	return false;
}
// Fast I/O
#define IOS ios::sync_with_stdio(true);cin.tie(nullptr)
// driver code
int main(){
	cout<<"Started\n";
	// I/O
	IOS;/*
    #ifndef ONLINE_JUDGE 
	    // For getting input from input.txt file 
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\input.txt", "r", stdin); 
	    // Printing the Output to output.txt file 
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\output.txt", "w", stdout); 
    #endif */
    int ar[]={2,4,5,9};
	int n;
	cin>>n;
	if(MIM(ar,4,n)){
		cout<<"Sum is present\n";
	}else cout<<"Sum is not available.\n";
	return 0;
}