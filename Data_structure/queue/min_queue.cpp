//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Build a minimum  queue data structure. Suports all standered push,pop in O(1).
// T.C         : O()
// A.S         : O()
//============================================================================

#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)
class MinimumQ{
	queue<int>Q;
	public:
		/**
		 * @param {nun} - input number
		 */
		void pushInQ(int num){
			while(!Q.empty() && Q.front()>num)
				Q.pop();
			Q.push(num);
		}
		
		/**
		 * pop the element at the front of the queue.
		 */
		void popQ(){
			Q.pop();
		}
		
		/**
		 * Return minimum element of the queue in O(1)
		 * @return {min} - minimum of the queue.
		 */
		int minQ(){
			return Q.front();
		}
};
// driver code
int main(){
	// I/O
	IOS;

    #ifndef ONLINE_JUDGE
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\input.txt", "r", stdin);
    #endif
	cout<<"Started\n";
	int n;
	cin>>n;
	MinimumQ Q;
	while(n--){
		int type,num;
		cin>>type;
		if(type == 1){
			cin>>num;
			Q.pushInQ(num);
		}else if(type == 2){
			Q.popQ();
		} else cout<<"Minimum : "<<Q.minQ()<<endl;
	}
	cout<<"\nDone:)\n";
	return 0;
}


