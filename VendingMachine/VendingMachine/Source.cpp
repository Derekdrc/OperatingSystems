// Project 1 - Vending Machine
// Derek D'Arcy
// 2/22/24
// Operating Systems

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <vector>
#include <sstream>
#include <fstream>
#include "Header.h"
using namespace std;


// Function to initialize vending machine with data saved into text files to persist
void initializeMachine(VendingMachine& VM) {
	try {
		string tmp;
		ifstream ifs;

		ifs.open("inventory.txt");

		vector <string> fromFile;
		while (getline(ifs, tmp)) {
			fromFile.push_back(tmp);
		}


		VM.setAmount(stod(fromFile.at(0)));
		VM.setNickels(stoi(fromFile.at(1)));
		VM.setDimes(stoi(fromFile.at(2)));
		VM.setQuarters(stoi(fromFile.at(3)));
		VM.setOnes(stoi(fromFile.at(4)));
		VM.setFives(stoi(fromFile.at(5)));
		VM.setCoke(stoi(fromFile.at(6)));
		VM.setPepsi(stoi(fromFile.at(7)));
		VM.setRC(stoi(fromFile.at(8)));
		VM.setJolt(stoi(fromFile.at(9)));
		VM.setFaygo(stoi(fromFile.at(10)));
		VM.setCups(stoi(fromFile.at(11)));

		ifs.close();
		cout << "Inventory loaded. Ready for use. " << endl;
	}
	catch (...) {
		cout << "Inventory missing or corrupted. Vending Machine operational with empty inventory. " << endl;
	}

}


//Function to process commands while in service mode
bool processCommandService(VendingMachine& VM, string command) {

	//Split command on spaces into vector
	string s;
	stringstream ss(command);
	vector<string> commandVec;
	while (getline(ss, s, ' ')) {
		commandVec.push_back(s);
	}
	commandVec.push_back(" ");

	//Turn the first word to lower and check if password
	for (auto& c : commandVec.at(0)) {
		c = tolower(c);
	}


	if (commandVec.at(0) == "lock" && commandVec.at(1) == VM.getPassword()) {
		VM.setMode(false);
		system("CLS");
		return true;
	}

	//Otherwise turn everything to lowercase as commands are not case sensitve
	for (int i = 0; i < commandVec.size(); i++) {
		for (auto& c : commandVec[i])
		{
			c = tolower(c);
		}
	}

	//Print help commands
	if (commandVec.at(0) == "help") {
		cout << "Commands in Service Mode are: " << endl
			<< "status" << endl
			<< "Add [cups|cola] brand <quantity>" << endl
			<< "Add|Remove [Coins|Bills] <denomination> <quantity> " << endl
			<< "Exit" << endl
			<< "Lock [password]" << endl;
	}
	//print status of VM
	else if(commandVec.at(0) == "status") {
		VM.serviceListStatus();
	}
	//handle addition command
	else if (commandVec.at(0) == "add") {
		//Add cups command
		if (commandVec.at(1) == "cups") {
			try {
				int num = stoi(commandVec.at(2));
				VM.addCups(num);
			}
			catch (invalid_argument) {
				cout << endl << "Invalid command. Please try again. " << endl;
			}
		}
		//Add cola command
		else if (commandVec.at(1) == "cola") {
			if (commandVec.at(2) == "coke" || commandVec.at(2) == "pepsi" || commandVec.at(2) == "rc" || commandVec.at(2) == "jolt" || commandVec.at(2) == "faygo") {
				try {
					int num = stoi(commandVec.at(3));
					VM.addCola(commandVec.at(2), num);
				}
				catch (invalid_argument) {
					cout << "Invalid Quantity. Please Try again. " << endl;
				}
			}
			else {
				cout << "Invalid Brand. Please Try again" << endl;
			}
		}
		//Add coins command
		else if (commandVec.at(1) == "coins") {
			if (commandVec.at(2) == "5" || commandVec.at(2) == "nickel") {
				try {
					int num = stoi(commandVec.at(3));
					VM.addCoins(5, num);
				}
				catch (invalid_argument) {
					cout << "Invalid quantity. Please Try again" << endl;
				}
			}
			else if (commandVec.at(2) == "10" || commandVec.at(2) == "dime") {
				try {
					int num = stoi(commandVec.at(3));
					VM.addCoins(10, num);
				}
				catch (invalid_argument) {
					cout << "Invalid quantity. Please Try again" << endl;
				}
			}
			else if (commandVec.at(2) == "25" || commandVec.at(2) == "quarter") {
				try {
					int num = stoi(commandVec.at(3));
					VM.addCoins(25, num);
				}
				catch (invalid_argument) {
					cout << "Invalid quantity. Please Try again" << endl;
				}
			}
			else {
				cout << "Invalid Denomination. Please Try Again.." << endl;
			}
		}
		//Add Bills command
		else if (commandVec.at(1) == "bills") {
			if (commandVec.at(2) == "1") {
				try {
					int num = stoi(commandVec.at(3));
					VM.addBills(1, num);
				}
				catch (invalid_argument) {
					cout << "Invalid quantity. Please Try again" << endl;
				}
			}
			else if (commandVec.at(2) == "5") {
				try {
					int num = stoi(commandVec.at(3));
					VM.addBills(5, num);
				}
				catch (invalid_argument) {
					cout << "Invalid quantity. Please Try again" << endl;
				}
			}
			else {
				cout << "Invalid denomination. Please Try again" << endl;
			}
		}
		else {
			cout << "Invalid command. Please try again, or enter 'help' for a list of commands." << endl;
		}
	}
	else if (commandVec.at(0) == "remove") {
		if (commandVec.at(1) == "coins") {
			if (commandVec.at(2) == "5" || commandVec.at(2) == "nickel") {
				try {
					int num = stoi(commandVec.at(3));
					VM.removeCoins(5, num);
				}
				catch (invalid_argument) {
					cout << "Invalid quantity. Please try again" << endl;
				}
			}
			else if (commandVec.at(2) == "10" || commandVec.at(2) == "dime") {
				try {
					int num = stoi(commandVec.at(3));
					VM.removeCoins(10, num);
				}
				catch (invalid_argument) {
					cout << "Invalid quantity. Please try again" << endl;
				}
			}
			else if (commandVec.at(2) == "25" || commandVec.at(2) == "quarter") {
				try {
					int num = stoi(commandVec.at(3));
					VM.removeCoins(25, num);
				}
				catch (invalid_argument) {
					cout << "Invalid quantity. Please try again" << endl;
				}
			}
			else {
				cout << "Invalid Denomination. Please try again. " << endl;
			}
		}
		else if (commandVec.at(1) == "bills") {
			if (commandVec.at(2) == "1") {
				try {
					int num = stoi(commandVec.at(3));
					VM.removeBills(1, num);
				}
				catch (invalid_argument) {
					cout << "Invalid quantity. Please try again" << endl;
				}
			}
			else if (commandVec.at(2) == "5") {
				try {
					int num = stoi(commandVec.at(3));
					VM.removeCoins(5, num);
				}
				catch (invalid_argument) {
					cout << "Invalid quantity. Please try again" << endl;
				}
			}
		}
		else {
			cout << "Invalid command. Please try again or enter 'help' for a list of commands";
		}
	}
	//Command for user to exit VM
	else if (commandVec.at(0) == "exit") {
		return false;
	}
	else {
		cout << "Invalid Command. Please enter 'help' for a list of valid commands and try again" << endl;
	}
	return true;
}

//Function to process commands while in user mode
bool processCommandUser(VendingMachine& VM, string command) {
	//Split command on spaces into vector
	string s;
	stringstream ss(command);
	vector<string> commandVec;
	while (getline(ss, s, ' ')) {
		commandVec.push_back(s);
	}
	commandVec.push_back(" ");

	//Turn the first word to lower and check if password
	for (auto& c : commandVec.at(0)) {
		c = tolower(c);
	}

	//Unlock command
	if (commandVec.at(0) == "unlock" && commandVec.at(1) == VM.getPassword()) {
		VM.setMode(true);
		system("CLS");
		return true;
	}

	//Otherwise turn everything to lowercase as commands are not case sensitve
	for (int i = 0; i < commandVec.size(); i++) {
		for (auto& c : commandVec[i])
		{
			c = tolower(c);
		}
	}

	//Help command
	if (commandVec.at(0) == "help") {
		cout << "Commands in normal mode are: " << endl
			<< "Coin <Value> where value is 5 10 25 nickel dime quarter" << endl
			<< "Bill <Value> where value is 1 5 " << endl
			<< "Cola <Value> where value is coke pepsi rc jolt faygo" << endl
			<< "Exit" << endl
			<< "Unlock [password]" << endl;
	}
	else if (commandVec.at(0) == "coin") {
		//coin command
		if (commandVec.at(1) == "5" || commandVec.at(1) == "nickel") {
			VM.depositCoins(5);
		}
		else if (commandVec.at(1) == "10" || commandVec.at(1) == "dime") {
			VM.depositCoins(10);
		}
		else if (commandVec.at(1) == "25" || commandVec.at(1) == "quarter") {
			VM.depositCoins(25);
		}
		else {
			cout << "Invalid denomination" << endl;
		}
	}
	else if (commandVec.at(0) == "bill") {
		//bill command
		if (commandVec.at(1) == "1") {
			VM.depositBills(1);
		}
		else if (commandVec.at(1) == "5") {
			VM.depositBills(5);
		}
		else {
			cout << "Invalid denomination" << endl;
		}
	}
	else if (commandVec.at(0) == "cola") {
		//cola command
		if (commandVec.at(1) == "coke" || commandVec.at(1) == "pepsi" || commandVec.at(1) == "rc" || commandVec.at(1) == "jolt" || commandVec.at(1) == "faygo") {
			VM.orderCola(commandVec.at(1));
		}
		else {
			cout << "Invalid cola order. Please try again or enter help for a list of commands" << endl;
		}
	}
	//Command for user to exit VM
	else if (commandVec.at(0) == "exit") {
		return false;
	}
	else {
		cout << "Invalid Command. Please enter 'help' for a list of valid commands and try again" << endl;
	}
	return true;
}


//Shutdown machine and write info to file to persist
void shutdownMachine(VendingMachine& VM) {
	ofstream output;
	output.open("inventory.txt");

	output << VM.getAmount() << endl <<  VM.getNickels()  << endl
		<< VM.getDimes() << endl << VM.getQuarters() << endl
		<< VM.getOnes()  << endl << VM.getFives() << endl
		<< VM.getCoke()  << endl << VM.getPepsi() << endl
		<< VM.getRC() << endl << VM.getJolt() << endl
		<< VM.getFaygo() << endl << VM.getCups();

	output.close();
	

}


//Main function
int main() {
	//Initialuize vending machine object
	VendingMachine VM;

	//Call function to populate inventory from last session
	initializeMachine(VM);
	cout << "Please enter a command and it's parameter" << endl
		<< "(Type Help for a list of commands, EXIT to quit" << endl;
	
	//Run until user wishes to exit
	bool open = true; 
	while (open) {
		if (VM.getMode() == true) {
			//Service mode
			cout << "[SERVICE MODE] > ";
			string command;

			getline(cin, command);
			open = processCommandService(VM, command);
		}
		else if (VM.getMode() == false) {
			//User mode
			cout << "[USER MODE] > ";
			string command;

			getline(cin, command);
			open = processCommandUser(VM, command);
		}
		
	}

	//Save inventory to file so inventory persists through runs
	shutdownMachine(VM);

	return 0;
}