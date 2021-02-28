//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description :
// T.C         : O()
// A.S         : O()
//============================================================================

#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

struct CTime{
	int startTime;
	int endTime;
};

string hhIn24(string hh,string format){
	if(format.compare("PM")==0 && stoi(hh) != 0 && stoi(hh) != 12){
		hh = to_string(stoi(hh)+12);
	}else if(format.compare("AM") ==0 && stoi(hh) == 12){
		hh="00";
	}
	return hh;
}
int extractTime(string timeStr){
	string hh,mm,format;
	hh = timeStr.substr(0,2);
	mm = timeStr.substr(3,2);
	format = timeStr.substr(6,2);
	
	// change hour value
	// this is the only required value to change, to make it 24 hr format
	hh = hhIn24(hh,format);
	return stoi(hh+mm);
}

void extractCurTime(CTime *t,string timeStr){
	// get start time
	t->startTime = extractTime(timeStr.substr(0,8));
	t->endTime = extractTime(timeStr.substr(9,8));
}
// driver code
int main(){
	// I/O
	IOS;

    #ifndef ONLINE_JUDGE 
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\input.txt", "r", stdin);  
    #endif 
    int t,N;
	cin>>t;
    string ptime,ctime;
	CTime Ctime;
	
	while(t--){
		int pt;
        getline(cin>>ws,ptime);
		pt = extractTime(ptime);
		cin>>N;
		for(int i=0; i<N; i++){
			getline(cin>>ws,ctime);
			extractCurTime(&Ctime,ctime);

			if(Ctime.startTime <= pt && Ctime.endTime >= pt)
				cout<<"1";
			else cout<<"0";
		}
		cout<<endl;
	}
	return 0;
}