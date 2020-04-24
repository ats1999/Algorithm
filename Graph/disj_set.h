//============================================================================
// Name        : disj_set.h
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Implements Disjoints set data structure. 
//============================================================================


/**
* This claass repersents Disjoints set data structure.
*
* set			 : A array repersenting disjoint set. 
* size			 : an integer - size of set
* 
* DisjSet(int n) : this is a constuctor. 
*				- Constructs a new set containing the given number of singleton sets.
*				- For example, new DisjointSet(3) ? {{0}, {1}, {2}}.
* 
* printSet()		: print set elements alongs with their parent
* printSize()		: print set size.
*
* areInSameSet()	: returns true if both number in the same set false otherwise.	 
*					- areInSameSet(int elem1,int elem2)
*
* find(int num)	    : returns parent of the given element.
* getSize()			: returns size of set. (constant).
* isUnion()			: returns true and make union if both numbers belongs to different false otherwise/
*					- isUnion(int num1,int num2)
*/
//template<typename T>
class DisjSet{
	int *set=NULL,*size=NULL;
	int setSize=0;
	public:
		/**
		* This constructor creates a disjoint set of size n.
		*/
		DisjSet(int n){
			setSize=n+1;
			set=new int[n+1];
			size=new int[n+1];
	
			//set all values that means, it's parent is itself
			for(int i=0;i<=n;i++)
				set[i]=i;
			
			//set all size of all elements to zero.
			for(int i=0;i<=n;i++)
				size[i]=0;
		}
		
		/**
		* Print all value of the set at any time. 
		* Mainly used for debuging purpose. 
		*/
		void printSet(){
			printf("\n");
			for(int i=0;i<setSize;i++)
				printf("Set element: %d.. parent %d\n",i,set[i]);
		}
		
		/**
		* This function print size of all set.
		*/
		void printSize(){
			printf("\n");
			for(int i=0;i<setSize;i++){
				printf("Size of: %d\t%d\n",i,size[i]);
			}
		}
		
		/**
		* Tests whether the given two elements are members of the same set. 
		* Note that the arguments are orderless.
		* @param num1: an int - number 1 
		* @param num2: an int - number 2
		* @return bool : true denotes both number belongs to the same set, different set otherwise. 
		*/
		bool areInSameSet(int num1,int num2){
			// both belongs to the same set.
			if(set[num1]==set[num2])
				return true;
				
			// both belongs to the different set.
			return false;
		}
		
		/**
		* This function returns parent of the given element.
		* @param elem: an element - whose parent is to be find.
		* @return : root of the given element
		*/
		int find(int elem){
			return set[elem];
		}
		
		/**
		* Merges together the sets that the given two elements belong to. 
		* This method is also known as “union” in the literature. 
		* If the two elements belong to different sets, then the two sets are merged and the method returns true. 
		* Otherwise they belong in the same set, nothing is changed and the method returns false.
		* Note that the arguments are orderless.
		* @param index1: an index of first number.
		* @param index2: an index of second number
		* @retrun bool: true denotes that both numbers belongs to different sets and they are merged and false denotes that both number belongs to the same set. 
		*/
		bool isUnion(int index1,int index2){
			// if both already belongs to the same set
			if(find(index1)==find(index2))
				return false;
				
			// if both belongs to different set.
			// make parent of both whose size is greater.
			if(size[find(index1)]>size[find(index2)]){
				set[index2]=find(index1);
				size[find(index1)]++;
			}
			else{
				set[index1]=find(index2);
				size[find(index2)]++;
			}
			return true;	
		}
		
		/**
		* This function returns size of set. 
		* Size of set is constant for lifetime. 
		* @return size: an int - size of set. 
		*/
		int getSize(){
			return setSize;
		}
};


