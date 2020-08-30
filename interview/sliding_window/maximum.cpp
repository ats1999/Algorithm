//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
//
// Description : You have an array of n elements. In this array, at a time you can see only
//               k elements. Assume this as a window of k size. You have to return an array 
//               which contains maximum element of each window.
//
// T.C         : O()
// A.S         : O()
//============================================================================

#include<bits/stdc++.h>
using namespace std;
/*
Method - 1

We can run a loop for (N-K) times, for each loop calculates maximum in the current
window. 
T.C = O(N*K)
A.S = O(1)

==================
Method - 2

Make use of priority queue...

In this method, we'll run the  same outer loop for N-K times. 
For each loop, enque the i+1^th element and dequeu i-k^th element from queue. 
While each window in under processing, push greter element from the queue in the result array. 

T.C = O(N*log(k)) -  enqueu and dequeu operation takes log(n) time. 
A.S = O(k)

==================
Method - 3

Make use of linear queue...
--- If array contains no duplicates elements ---

In this method, we'll run the  same outer loop for N-K times. 
For each loop, enque the i+1^th element at the end of the queue, 
dequeu i-k^th element from front of the queue. 

T.C = O(N) -  enqueu and dequeu operation takes O(1) time. 
A.S = O(k)

==================
Method - 4

Don't use queue...
--- If array contains no duplicates elements ---
Same method as above. 

*/
// driver code

/**
 * This method prints the result array.
 * It has nothing to do with algorithm.
 * @param {ar} - input array
 * @param {n} - size of the array.
 */
void print(int ar[], int n){
	for(int i=0;i<n;i++){
		cout<<ar[i]<<" ";
	}
	cout<<endl;
}
/**
 * This method uses  deque data structure to implement this algorithm.
 * Time complexity of this algorithm is O(N*Log(K)) - insertion and deletion form priority queue takes log(n) time.
 * Space complexity of this algorithm is O(K)
 *
 * @param {ar} - input array
 * @param {n} - size of array
 * @param {k} - size of window
 * @param {result} - result array, which contains the greater nummber of each window of size K. 
 */
void usingPQ(int ar[],int n, int k, int result[]){
	deque<int>dq;
	
	// do processing for the first k elements seperatly.
	for(int i=0; i<k; i++){
		while(!dq.empty() && ar[dq.back()]<ar[i]) 
			dq.pop_back();
			
		dq.push_back(i);
	}
	
	result[0] = ar[dq.front()];
	
	// process remaining items
	for(int i=k; i<n; i++){
		
		while(!dq.empty() && ar[dq.back()]<ar[i]) 
			dq.pop_back();
			
		dq.push_back(i);
		
		// remove the front element if it is outside of window
		if(dq.front()<=(i-k))
			dq.pop_front();
		// store the result
		result[i-k+1] = ar[dq.front()];
	}
}
int main(){
	cout<<"Started\n";
    int ar[] = {4,5,6,0,7,9,5,6,4};
    int n = sizeof(ar)/sizeof(ar[0]);
    int k = 3;
    
    int result[n-k+1];
    usingPQ(ar,n,k,result);
    for(int i =0; i<(n-k+1); i++){
    	cout<<result[i]<<" ";
	}
	cout<<"\nDone:)\n";
	return 0;
}
