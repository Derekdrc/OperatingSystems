//Header file that contains Vending Machine Class

#include <iostream>
#include <string>
using namespace std;

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
	//Constructor
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


	//Setters
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
		cansCoke = n;
	}

	void setRC(int n) {
		cansCoke = n;
	}

	void setJolt(int n) {
		cansCoke = n;
	}

	void setFaygo(int n) {
		cansCoke = n;
	}

	void setCups(int n) {
		cansCoke = n;
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

};