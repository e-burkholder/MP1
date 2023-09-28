/*
MP1 conversion.cpp - Elizabeth Huang Burkholder - 09/19/23
Program will receive order details regarding the number of regular donuts, fancy donuts, and apple fritters.
Using the data gathered, it will organize/price them respectively then add on tax for a total price.
Program will then receive the amount paid by the customer and will calculate how much to give back.
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	int regDonuts, fanDonuts, appleFrit, dozReg, dozFan;
	int dollars = 0, quarters = 0, dimes = 0, nickels = 0, pennies = 0;
	double subtotal, total, pays, changeDue, tax;

	//Asking user for order details
	cout << "Number of regular donuts ordered: ";
	cin >> regDonuts;
	cout << "Number of fancy donuts ordered: ";
	cin >> fanDonuts;
	cout << "Number of apple fritters ordered: ";
	cin >> appleFrit;

	//Calculating donut dozens (dozens of 12)
	dozReg = regDonuts / 12;
	regDonuts = regDonuts % 12;

	dozFan = fanDonuts / 12;
	fanDonuts = fanDonuts % 12;

	//Calculating total cost & change due
	subtotal = (regDonuts * 0.75) + (dozReg * 7.99) + (fanDonuts * 0.85) + (dozFan * 8.49) + (appleFrit * 1.50);
	tax = subtotal * 0.075;
	total = subtotal + tax;

	cout << "Customer owes: $" << fixed << setprecision(2) << total << "\nCustomer Pays: $";
	cin >> pays;

	changeDue = pays - total;
	changeDue = round(changeDue * 100) / 100;

	//If change is greater than $0.00
	if (changeDue > 0)
	{
		cout << "Change owed is $" << changeDue << " - ";
		//If change is greater than $1.00
		if (changeDue >= 1) 
		{
			dollars = changeDue;
			changeDue = changeDue - dollars;
			changeDue = round(changeDue * 100.0) / 100.0;

			//Dollars, dollar, dollar.
			if (dollars > 1 && changeDue > 0.00)
		{
			cout << dollars << " dollars, ";
		}
			else if (dollars == 1 && changeDue > 0.00)
		{
			cout << dollars << " dollar, ";
		}
			else
		{
			cout << dollars << " dollar.";
		}		
		} 
	
		//If change is less than $1.00 but greater than $0.00
		if (changeDue < 1 && changeDue>0)
		{
			if (changeDue >= .25)
			{
				quarters = changeDue / .25;
				changeDue = (changeDue - (.25 * quarters));
				changeDue = round(changeDue * 100.0) / 100.0;

				//Quarters, quarter, quarter.
				if (quarters > 1 && changeDue > 0.00)
				{
					cout << quarters << " quarters, ";
				}
				else if (quarters > 1 && changeDue <= 0.00)
				{
					cout << quarters << " quarters.";
				}
				else if (quarters == 1 && changeDue > 0.00)
				{
					cout << quarters << " quarter, ";
				}
				else
				{
					cout << quarters << " quarter.";
				}
			}

			if (changeDue >= .10 && changeDue < .25)
			{
				dimes = changeDue / .10;
				changeDue = (changeDue - (.10 * dimes));
				changeDue = round(changeDue * 100.0) / 100.0;

				//Dimes, dime, dime.
				if (dimes > 1 && changeDue > 0.00)
				{
					cout << dimes << " dimes, ";
				}
				else if (dimes > 1 && changeDue <= 0.00)
				{
					cout << dimes << " dimes.";
				}
				else if (dimes == 1 && changeDue > 0.00)
				{
					cout << dimes << " dime, ";
				}
				else
				{
					cout << dimes << " dime.";
				}
			}

			if (changeDue >= .05 && changeDue < .10)
			{
				nickels = changeDue / .05;
				changeDue = (changeDue - (0.05 * nickels));
				changeDue = round(changeDue * 100.0) / 100.0;
				
				//Nickels, nickel, nickel.
				if (nickels > 1 && changeDue > 0.00)
				{
					cout << nickels << " nickels, ";
				}
				else if (nickels > 1 && changeDue <= 0.00)
				{
					cout << nickels << " nickels.";
				}
				else if (nickels == 1 && changeDue > 0.00)
				{
					cout << nickels << " nickel, ";
				}
				else
				{
					cout << nickels << " nickel.";
				}
			}

			if (changeDue >= .01 && changeDue < .05)
			{
				pennies = changeDue/0.01;
				pennies = round(pennies * 100.0) / 100.0;


				//Pennies. penny.
				if (pennies > 1)
				{
					cout << pennies << " pennies. ";
				}
				else
				{
					cout << pennies << " penny.";
				}
			}
		}
	}

	//Else change is exactly $0.00
	else
	{
		cout << "Exact payment received - no changed owed.";
	}

	return 0;
}

