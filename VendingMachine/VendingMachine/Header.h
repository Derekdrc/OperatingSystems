//Header file that contains Vending Machine Class and related functions

#include <iostream>
#include <string>
using namespace std;

//Vendim machine class
class VendingMachine {
private:
	//Service Mode and pass to switch
	bool serviceMode;
	string password;

	//Total deposited currently
	double amountDeposited;
	
	//Change
	int numNickels;
	int numDimes;
	int numQuarters;
	int numOnes;
	int numFives;

	//Colas
	int cansCoke;
	int cansPepsi;
	int cansRC;
	int cansJolt;
	int cansFaygo;
	
	//cups
	int cups;


public:
	//Default Constructor
	VendingMachine() {
		//Service Mode True to start
		serviceMode = true;
		password = "modeSwitch";

		//Money
		amountDeposited = 0;
		numNickels = 0;
		numDimes = 0;
		numQuarters = 0;
		numOnes = 0;
		numFives = 0;

		//Sodas
		cansCoke = 0;
		cansPepsi = 0;
		cansRC = 0;
		cansJolt = 0;
		cansFaygo = 0;
		cups = 0;
	}

	//Getters
	string getPassword() {
		return password;
	}

	bool getMode() {
		return serviceMode;
	}

	double getAmount() {
		return amountDeposited;
	}

	int getNickels() {
		return numNickels;
	}

	int getDimes() {
		return numDimes;
	}

	int getQuarters() {
		return numQuarters;
	}

	int getOnes() {
		return numOnes;
	}

	int getFives() {
		return numFives;
	}

	int getCoke() {
		return cansCoke;
	}

	int getPepsi() {
		return cansPepsi;
	}

	int getRC() {
		return cansRC;
	}

	int getJolt() {
		return cansJolt;
	}

	int getFaygo() {
		return cansFaygo;
	}

	int getCups() {
		return cups;
	}


	//Setters
	void setMode(bool b) {
		serviceMode = b;
	}

	void setAmount(int n) {
		amountDeposited = n;
	}

	void setNickels(int n) {
		numNickels = n;
	}

	void setDimes(int n) {
		numDimes = n;
	}

	void setQuarters(int n) {
		numQuarters = n;
	}

	void setOnes(int n) {
		numOnes = n;
	}

	void setFives(int n) {
		numFives = n;
	}

	void setCoke(int n) {
		cansCoke = n;
	}

	void setPepsi(int n) {
		cansPepsi = n;
	}

	void setRC(int n) {
		cansRC = n;
	}

	void setJolt(int n) {
		cansJolt = n;
	}

	void setFaygo(int n) {
		cansFaygo = n;
	}

	void setCups(int n) {
		cups = n;
	}

	//List Service Mode Status
	void serviceListStatus() {
		cout << "Amount Deposited = " << amountDeposited << endl
			<< "total One Dollar Bills = " << numOnes << endl
			<< "total Five Dollar Bills = " << numFives << endl
			<< "total Nickels = " << numNickels << endl
			<< "total Dimes = " << numDimes << endl
			<< "total Quarters = " << numQuarters << endl
			<< "total Coke = " << cansCoke << endl
			<< "total Pepsi = " << cansPepsi << endl
			<< "total RC = " << cansRC << endl
			<< "total Jolt = " << cansJolt << endl
			<< "total Faygo = " << cansFaygo << endl
			<< "total Cups = " << cups << endl;
	}

	//Function to add cups
	void addCups(int num) {
		cups += num;
	}

	//Function to add cola to VM
	void addCola(string brand, int quantity) {
		if (brand == "coke") {
			cansCoke += quantity;
		}
		else if (brand == "pepsi") {
			cansPepsi += quantity;
		}
		else if (brand == "rc") {
			cansRC += quantity;
		}
		else if (brand == "jolt") {
			cansJolt += quantity;
		}
		else if (brand == "faygo") {
			cansFaygo += quantity;
		}
	}

	//Function to add coins to VM
	void addCoins(int deno, int quantity) {
		if (deno == 5) {
			numNickels += quantity;
		}
		else if (deno == 10) {
			numDimes += quantity;
		}
		else if (deno == 25) {
			numQuarters += quantity;
		}
	}

	//Function to add Bills to VM
	void addBills(int deno, int quantity) {
		if (deno == 1) {
			numOnes += quantity;
		}
		else if (deno == 5) {
			numFives += quantity;
		}
	}

	//Function to remove coins from VM
	void removeCoins(int deno, int quantity) {
		if (deno == 5) {
			if (numNickels < quantity) {
				cout << "There were only " << numNickels << "left. You pulled out all of them and nickels are now zero. " << endl;
				numNickels = 0;
			}
			else {
				numNickels -= quantity;
			}
		}
		else if (deno == 10) {
			if (numDimes < quantity) {
				cout << "There were only " << numDimes << "left. You pulled out all of them and dimes are now zero. " << endl;
				numDimes = 0;
			}
			else {
				numDimes -= quantity;
			}
		}
		else if (deno == 25) {
			if (numQuarters < quantity) {
				cout << "There were only " << numQuarters << "left. You pulled out all of them and quarters are now zero. " << endl;
				numQuarters = 0;
			}
			else {
				numQuarters -= quantity;
			}
		}
	}

	//Function to remove bills from VM
	void removeBills(int deno, int quantity) {
		if (deno == 1) {
			if (numOnes < quantity) {
				cout << "There were only " << numOnes << "left. You pulled out all of them and Ones are now zero. " << endl;
				numOnes = 0;
			}
			else {
				numOnes -= quantity;
			}
		}
		else if (deno == 5) {
			if (numFives < quantity) {
				cout << "There were only " << numFives << "left. You pulled out all of them and Fives are now zero. " << endl;
				numFives = 0;
			}
			else {
				numFives -= quantity;
			}
		}
	}

	//Function for user to deposit coins
	void depositCoins(int deno) {
		if (deno == 25) {
			numQuarters++;
		}
		else if (deno == 10) {
			numDimes++;
		}
		else if (deno == 5) {
			numNickels++;
		}

		amountDeposited += (double(deno)/100);
		cout << deno << " cents deposited" << endl;
		cout << "You have a total of " << amountDeposited << " deposited. " << endl;
	}

	//Function for user to deposit bills
	void depositBills(int deno) {
		if (deno == 5) {
			numFives++;
		}
		else if (deno == 1) {
			numOnes++;
		}
		amountDeposited += deno;
		cout << "$" << deno << " deposited" << endl;
		cout << "You have a total of " << amountDeposited << " deposited. " << endl;
	}

	//Function for user to order cola
	void orderCola(string brand) {
		double priceOfCola = 0.75;
		
		if (amountDeposited < priceOfCola) {
			cout << "Not enough deposited. Please deposit more money to order a cola." << endl;
		}
		else if (cups <= 0) {
			cout << "Vending Machine out of cups. Please see front desk for refills. Money will be given back" << endl;
			calcChange();
		}
		else if (brand == "coke") {
			if (cansCoke >= 1) {
				cout << "Coke dispensed. " << endl;
				cansCoke--;
				cups--;
				calcChange();
			}
			else {
				cout << "Vending Machine out of Coke. Please try again with a different brand." << endl;
			}
		}
		else if (brand == "pepsi") {
			if (cansPepsi >= 1) {
				cout << "Pepsi dispensed. " << endl;
				cansPepsi--;
				cups--;
				calcChange();
			}
			else {
				cout << "Vending Machine out of Pepsi. Please try again with a different brand." << endl;
			}
		}
		else if (brand == "rc") {
			if (cansRC >= 1) {
				cout << "RC dispensed. " << endl;
				cansRC--;
				cups--;
				calcChange();
			}
			else {
				cout << "Vending Machine out of RC. Please try again with a different brand." << endl;
			}
		}
		else if (brand == "jolt") {
			if (cansJolt >= 1) {
				cout << "Jolt dispensed. " << endl;
				cansJolt--;
				cups--;
				calcChange();
			}
			else {
				cout << "Vending Machine out of Jolt. Please try again with a different brand." << endl;
			}
		}
		else if (brand == "faygo") {
			if (cansFaygo >= 1) {
				cout << "Faygo dispensed. " << endl;
				cansFaygo--;
				cups--;
				calcChange();
			}
			else {
				cout << "Vending Machine out of Faygo. Please try again with a different brand." << endl;
			}
		}
	}

	//Function to handle calculating change
	void calcChange() {
		float priceOfCola = 0.75;

		float refundTotal = amountDeposited - priceOfCola;
		
		float fivesWorth = 5;
		float onesWorth = 1;
		float quarterWorth = 0.25;
		float dimeWorth = 0.10;
		float nickelWorth = 0.05;

		if (refundTotal == 0) {
			cout << "No change needed. " << endl;
			amountDeposited = 0;
		}
		else {
			cout << "Your change: $" << refundTotal<< endl;
			
			//Calculate fives
			int refundFives = refundTotal / fivesWorth;
			if (numFives < refundFives) {
				//Arent enough fives in the VM to cover the amount needed
				cout << "Fives: " << numFives << endl;
				numFives = 0;
				refundTotal -= numFives;
			}
			else {
				//there are enough fives to cover the necessary amount
				cout << "Fives: " << refundFives << endl;
				numFives -= refundFives;
				refundTotal -= refundFives;
			}

			//Calculate ones
			int refundOnes = refundTotal / onesWorth;
			if (numOnes < refundOnes) {
				cout << "Ones: " << numOnes << endl;
				numOnes = 0;
				refundTotal -= numOnes;
			}
			else {
				cout << "Ones: " << refundOnes << endl;
				numOnes -= refundOnes;
				refundTotal -= refundOnes;
			}


			//Calculate quarters
			int refundQuarters = refundTotal / quarterWorth;
			if (numQuarters < refundQuarters) {
				cout << "Quarters: " << numQuarters << endl;
				refundTotal -= (numQuarters * quarterWorth);
				numQuarters = 0;
			}
			else {
				cout << "Quarters: " << refundQuarters << endl;
				numQuarters -= refundQuarters;
				refundTotal -= (refundQuarters * quarterWorth);
			}


			//Calculate Dimes
			int refundDimes = refundTotal / dimeWorth;
			if (numDimes < refundDimes) {
				cout << "Dimes: " << numDimes << endl;
				refundTotal -= (numDimes * dimeWorth);
				numDimes = 0;
			}
			else {
				cout << "Dimes: " << refundDimes << endl;
				numDimes -= refundDimes;
				refundTotal -= (refundDimes * dimeWorth);
			}

			//Calculate Nickels
			int refundNickels = refundTotal / nickelWorth;
			if (numNickels < refundNickels) {
				cout << "Nickels: " << numNickels << endl;
				refundTotal -= (numNickels * nickelWorth);
				numNickels = 0;
			}
			else {
				cout << "Nickels: " << refundNickels << endl;
				numNickels -= refundNickels;
				refundTotal -= (refundNickels * nickelWorth);
				
			}

			//Make sure that full change amount was processed, otherwise send to front desk
			//Don't use 0 as comparison to compensate for floating point arithmetic
			if (refundTotal <= 0.001) {
				amountDeposited = 0;
				cout << "Thank you for the transaction. Have a nice day" << endl;
			}
			else {
				cout << "Vending Machine out of change. Please see front desk for your remaining $" << refundTotal << ". Thank you!" << endl;
				amountDeposited = 0;
			}
		}
	}
};