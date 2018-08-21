/*
	Program is written for the inventory of a store.
	Main function will have a menu that the user will traverse through as long as 
	the user does not press Q. Store.h is the header where it will call functions
	based on what the user pressed.
	
	Written by Kevin Cochran.

*/

#include <iostream>
#include <vector>
#include "store.h"

using namespace std;

int main()
{
	char inp;
	char del;
	string name, id;
	
	int buy, order, inStore, sold;
	float manuPrice, sellPrice;
	
	store riven;
	
	riven.thePushFun();

	do 
	{
		cout << "Welcome to Trusty Patches shop!" << endl;
		cout << "A: To find an item on the list." << endl;
		
		cout << "B: To buy an item." << endl;
		cout << "C: To check the price of an item." << endl;
		cout << "D: To print the inventory." << endl;
		cout << "E: To add to the inventory." << endl;
		cout << "F: To delete all inventory." << endl;
		cout << "Q: To quit the program." << endl;
		cout << endl;
		
		cin >> inp;
		
		
		
		if(inp == 'A')
		{	
			
			cout << "What item did you want to look for?" << endl;
			cin >> name;
			cout << endl;
			riven.foundFun(name);	
			
		}
		
		else if(inp == 'B')
		{
			cout << "What item did you want to buy?" << endl;
			cin >> name;
			cout << endl;
			cout << "How many would you like to buy?" << endl;
			cin >> buy;
			cout << endl;
			riven.buyFun(name, buy);
			
			
		}
		
		else if(inp == 'C')
		{
			cout << "What item did you want to check the price for?" << endl;
			cin >> name;
			cout << endl;
			riven.priceFun(name);
			
		}
		
		else if (inp == 'D')
		{
			riven.printFun();
			cout << endl;
			
		}
		
		else if(inp == 'E')
		{
			cout << "ID: ";
			cin >> id;
			cout <<"\nName: ";
			cin >> name;
			cout <<"\nOrdered: ";
			cin >> order;
			cout <<"\nIn Store: ";
			cin >> inStore;
			cout <<"\nSold: ";
			cin >> sold;
			cout <<"\nManufacture Price: ";
			cin >>manuPrice;
			cout <<"\nSelling Price: ";
			cin >> sellPrice;
			cout << endl;
			
			riven.insertFun(id, name, order, inStore, sold, manuPrice, sellPrice);
			
			cout << endl;
			
		}
		
		else if(inp == 'F')
		{
			cout << "Are you sure you want to delete all items on the list?";
			cout << " Y for yes or type any other key to cancel." << endl;
			cin >> del;
			if(del == 'Y')
			{
				riven.deleteAllFun();
				
			}
			else
			{
				cout << "Wise decision. I really didn't feel like typing all that out again!" << endl;
			}
		}
			
		else if(inp == 'Q')
		{
			cout << "Have a great day!" << endl;
		}
		
		
		else
		{
			cout << "Choice is invalid. Please put in a proper choice!" << endl;
			
		}
		
		
	}
	while(inp != 'Q');
	
	return 0;
}
