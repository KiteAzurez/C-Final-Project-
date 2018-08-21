/*
	Program store will contain all functions from header store.h.
	Look into store.h for more information about them.
	
	Written by Kevin Cochran.

*/

#include "store.h"
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>

void store::thePushFun()
{
	itemId.push_back("0001");
	itemId.push_back("0002");
	itemId.push_back("0003");
	itemId.push_back("0004");
	itemId.push_back("0005");
	
	itemName.push_back("Zwiehander");
	itemName.push_back("WolfRing");
	itemName.push_back("HornetsRing");
	itemName.push_back("Katana");
	itemName.push_back("HavelsArmor");
	
	
	pOrdered.push_back(10);
	pOrdered.push_back(30);
	pOrdered.push_back(200);
	pOrdered.push_back(5);
	pOrdered.push_back(50);
	
	pInstore.push_back(10);
	pInstore.push_back(30);
	pInstore.push_back(200);
	pInstore.push_back(5);
	pInstore.push_back(50);
	
	pSold.push_back(3);
	pSold.push_back(10);
	pSold.push_back(150);
	pSold.push_back(2);
	pSold.push_back(25);
	
	manufPrice.push_back(100.00);
	manufPrice.push_back(25.25);
	manufPrice.push_back(10.00);
	manufPrice.push_back(250.00);
	manufPrice.push_back(15.00);
	
	sellingPrice.push_back(200.00);
	sellingPrice.push_back(40.00);
	sellingPrice.push_back(20.00);
	sellingPrice.push_back(500.00);
	sellingPrice.push_back(35.00);
	
};

void store::insertFun(string id, string name, int order, int inStore, int sold, float manuPrice, float sellPrice)
{
	bool match;
	
	
	for(int i = 0; i < itemId.size(); i ++)
		{
			//Id was found to match a prior one.
			if (itemId[i] == id)
				{
					match = true;
				}
			
		}
	
	if(match == true)
	{
		cout << "ERROR: ID Matches a previous input. Can not put in." << endl;
	}
	else
	{
		cout << name << " will now be inserted into the store!" << endl;
	
		itemId.push_back(id);
		itemName.push_back(name);
		pOrdered.push_back(order);
		pInstore.push_back(inStore);
		pSold.push_back(sold);
		manufPrice.push_back(manuPrice);
		sellingPrice.push_back(sellPrice);
	}
};

//I did try to locate an exact item and delete it, but just went with this one
//Since it seemed simplier.
void store::deleteAllFun()
{
	int size = itemId.size();
	
	for(int i = 0; i < size; i++)
	{
		itemId.pop_back();
		itemName.pop_back();
		pOrdered.pop_back();
		pInstore.pop_back();
		pSold.pop_back();
		manufPrice.pop_back();
		sellingPrice.pop_back();	
		
	}
	
	cout << "Whole list was deleted." << endl;

};

void store::foundFun(string name)
{
	//Most functions have this to check if the name
	//exit before doing its function.
	int i = checkFun(name);
	
	if(i < 0)
	{
		cout << name << " is not on the list." << endl;
	}
	else
	{
		cout << "itemID: " << itemId[i] << endl;
		cout << "itemName: " << itemName[i] << endl;
		cout << "pOrdered: " << pOrdered[i] << endl;
		cout << "pInstore: " << pInstore[i] << endl;
		cout << "pSold: " << pSold[i] << endl;
		cout << "manufPrice: " << manufPrice[i] << endl;
		cout << "sellingPrice: " << sellingPrice[i] << endl;
		cout << endl;
		
	}

};

void store::priceFun(string name)
{
	int i = checkFun(name);
	
	if(i < 0)
	{
		cout << name << " is not on the list." << endl;
	}
	
	else
	{
		cout << "The price of " << name << " is: $" << sellingPrice[i] << endl;
	}
};

void store::buyFun(string name, int x)
{
	int i = checkFun(name);
	
	if(i < 0)
	{
		cout << name << " is not on the list." << endl;
		
	}
	
	else if(pInstore[i] == 0)
	{
		cout << "We are sold out! Sorry." << endl;
		cout << endl;
	}
	else if(x > pInstore[i])
	{
		cout << "You are trying to buy too much. We only have " << pInstore[i];
		cout << " avaliable for purchase." << endl;
		cout << endl;
	}
	
	else
	{
		double temp = sellingPrice[i];
		
		pInstore[i] -= x;
		pSold[i] += x;
		
		temp *= x; 
		
		
		cout << "You owe: $" << setprecision(2) << fixed <<   temp << endl;
	}
	
};

int store::checkFun(string name)
{
	for(int i = 0; i < itemName.size(); i++)
	{
		if(itemName[i] == name)
			return i;
	}
	
	return -1;
};

void store::printFun()
{
	float sumInventory = 0;
	int sumStore = 0;
	
	
	cout << "The Trusty Patches Inventory." << endl;
	cout << "itemId" << setw(20) << "itemName" << setw(20) << "pOrdered"; 
	cout << setw(15) << "pInstore" << setw(15) << "pSold" << setw(15);
	cout << "manufPrice" << setw(15) << "sellingPrice" <<  endl;
	
	
	for(int i = 0; i < itemId.size(); i++)
	{
		cout << itemId[i] << setw(25) << itemName[i] <<  setw(16)<<  pOrdered[i] <<  setw(16);
		cout << pInstore[i] <<  setw(16) <<  pSold[i]  <<  setw(14) << manufPrice[i] <<  setw(17);
		cout << sellingPrice[i] << endl;
		
		sumInventory += (pInstore[i]* sellingPrice[i]);
		sumStore += pInstore[i];
	}
	cout << "Total Inventory: $" << setprecision(2) << fixed << sumInventory << endl;
	cout << "Total number of items in the Store: " << sumStore << endl;
	
};
