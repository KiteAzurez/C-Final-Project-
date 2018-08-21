#ifndef STORE_H
#define STORE_H
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class store
{
	public:
		void thePushFun();
		//Function to initalize the vector stack.
		//Pushes 5 variables onto the vector stack.
		
		void printFun();
		//Displays the current stack of vectors.
		
		void foundFun(string name);
		//finds a string name and displays it back to the user if
		//If it was found or not.
		
		
		void priceFun(string name);
		//Finds the price of string name and displays it back
		//To the user.
		
		
		void insertFun(string id, string name, int order, int inStore, int sold, float manuPrice, float sellPrice);
		//Takes in 7 variables and pushes it onto the vector stack.
		//Will not push an item if ID matches to something prior on stack.
		
		void deleteAllFun();
		//Deletes all items on the stack.
		
		
		void buyFun(string name, int x);
		//Takes in string name of item and how much the user wants to buy
		//If name does not exist, will get out and if x is over how much is
		//in store, it will say to user you are buying too much.
		//After it functions correctly, inStore will be subtractede and 
		//sold will be added based on x.
		
		
		int checkFun(string name);
		//Pseudo-boolean function used by most functions to check if a
		//String name exist on the stack.
		
	protected:
		//Information about each item on list.
		vector<int> pOrdered, pInstore, pSold;
		vector<float> manufPrice, sellingPrice;
		vector<string> itemId, itemName;
};

#endif
