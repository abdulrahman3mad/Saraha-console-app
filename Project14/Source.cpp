#include <iostream>
#include <stdio.h>
#include <ios>
#include "fstream" 
#include "string"
#include <vector>
#include "File.h"
#include "Users.h"
using namespace std;

void initalizeApp() {

}

int main() {

	Users user;
	int choice;
	bool userEntered = false;

	while (true) {
		cout << string(62, '-') << "Saraha Site" << string(62, '-') << endl << endl;
		cout << "Login(1)" << endl;
		cout << "Register(2)" << endl << endl;
		cout << "Choice: ";      cin >> choice;    cout << endl;
		if (choice == 1) {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			userEntered = user.login();
			system("CLS");
		}
		else if (choice == 2) {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			userEntered = user.registerUser();
			system("CLS");
		}
		else {
			cout << "This is not a vaild option :(" << endl;
		}
		while (userEntered) {
			cout << "--------------------------------------------" << endl;
			cout << "Add a contact user(1)" << endl;
			cout << "View contact data(2)" << endl;
			cout << "Search for a contact in my contact(3)" << endl;
			cout << "View recevied messages(4)" << endl;
			cout << "View Sent messages(5)" << endl;
			cout << "View favorite messages(6)" << endl;
			cout << "Add a message to favorite(7)" << endl;
			cout << "Remove the oldest message from favorite(8)" << endl;
			cout << "Send a msssage to a contact(9)" << endl;
			cout << "Display message of specific contect(10)" << endl;
			cout << "Exit(11)" << endl;
			cout << "--------------------------------------------" << endl;
			cout << "Choice: ";      cin >> choice;    cout << endl;

			if (choice == 11) {
				user.~Users();
				break;
			}

			switch (choice) {
			case 1:
				user.addUserToContacts();
				break;
			case 2:
				user.viewContacts();
				break;
			case 3:
				user.searchForContact();
				break;
			case 4:
				user.viewRecievedMessages();
				break;
			case 5:
				user.viewSentMessages();
				break;
			case 6:
				user.viewFavouriteMessages();
				break;
			case 7:
				user.putMessageIntoFavorite();
				break;
			case 8:
				user.removeOldestFavoriteMessage();
				break;
			case 9:
				user.sendMessage();
				break;
			case 10:
				user.DisplayMessagesofSpecificContact();
				break;
			}
		}
	}
	return 0;
}

