#include "Users.h"
#include <iostream>
using namespace std;

File file;

//for login
bool Users::isExist(string name, string password, string id) {
	for (int i = 0; i < file.AllUsers.size(); i++) {
		if (file.AllUsers[i].name == name && file.AllUsers[i].password == password && file.AllUsers[i].id == id) {
			return true;
		}
	}
	return false;
}

//for register
bool Users::isExist(string name, string id) {
	for (int i = 0; i < file.AllUsers.size(); i++) {
		if (file.AllUsers[i].name == name || file.AllUsers[i].id == id) {
			return true;
		}
	}
	return false;
}

void Users::setSentMessages() {
	for (int i = 0; i < file.SentMessages.size(); i++) {
		if (file.SentMessages[i].userId == id) {
			sent.push_back(file.SentMessages[i]);
		}
	}
}

void Users::setReceivedMessages() {
	for (int i = 0; i < file.ReceivedMessages.size(); i++) {
		if (file.ReceivedMessages[i].userId == id) {
			received.push_back(file.ReceivedMessages[i]);
		}
	}
}

void Users::setFavoriteMessages() {
	for (int i = 0; i < file.FavoriteMessages.size(); i++) {
		if (file.FavoriteMessages[i].userId == id) {
			favorite.push_back(file.FavoriteMessages[i]);
		}
	}
}

void Users::setContacts() {
	for (int i = 0; i < file.Contacts.size(); i++) {
		if (file.Contacts[i].Id == id) {
			userContacts.push_back(file.Contacts[i].contactId);
		}
	}
}


void Users::setData(string name, string password, string id) {
	this->name = name;
	this->password = password;
	this->id = id;

	setSentMessages();
	setReceivedMessages();
	setFavoriteMessages();
	setContacts();
}


bool Users::registerUser() {
	string userName, userPassword, userId;
	//get data
	cout << "Data: " << endl;
	cout << "Name: "; cin >> userName;
	cout << "Password: "; cin >> userPassword;
	cout << "Id: ";  cin >> userId;

	//check if this user is already exist
	if (isExist(userName, userId)) {
		cout << "This email is already exist, try again" << endl;
		return false;
	}
	//insert the data
	UserStruct user;
	user.name = userName;
	user.password = userPassword;
	user.id = userId;

	file.AllUsers.push_back(user);
	setData(name, password, id);
	return true;
}

bool Users::login() {
	string userName, userPassword, userId;
	cout << "Data: " << endl;
	cout << "Name: "; cin >> userName;
	cout << "Password: "; cin >> userPassword;
	cout << "Id: ";  cin >> userId;

	//check if this user is already exist
	if (!isExist(userName, userPassword, userId)) {
		cout << "This email isn't exist, try again" << endl;
		return false;
	}
	cout << endl << "Hello in our planet" << endl;
	setData(userName, userPassword, userId);
	return true;
}

void Users::viewContacts()
{
	int choice;
	if (userContacts.size() == 0) {
		cout << "You haven't any contact yet" << endl;
		cout << "addContact? (1, 0)" << endl;
		cin >> choice;
		if (choice == 1) {
			addUserToContacts();
			return;
		}
	}
	cout << "Contacts:" << endl;
	for (int i = 0; i < userContacts.size(); i++) {
		cout << "Id: " << userContacts[i] << endl;
	}
}


void Users::viewSentMessages()
{
	int choice;
	if (sent.size() == 0) {
		cout << "You haven't sent any message yet" << endl;
		cout << "send a message? (1, 0)" << endl;
		cin >> choice;
		if (choice == 1) {
			sendMessage();
		}
		return;
	}

	for (int i = 0; i < sent.size(); i++) {
		cout << "Message " << i + 1 << ": " << endl;
		cout << "    Sent to user: " << sent[i].otherId << endl;
		cout << "    Message: " << sent[i].text << endl;
	}
}


//return true + messages if there, and false if there is not
void Users::viewRecievedMessages()
{
	if (received.size() == 0) {
		cout << "There is not any received message yet :(" << endl;
	}
	return;

	for (int i = 0; i < received.size(); i++) {
		cout << "Message " << i + 1 << ": " << endl;
		cout << "    Was sent from user id: " << received[i].otherId << endl;
		cout << "    Message: " << received[i].text << endl;
	}

}

//return true + messages if there, and false if there is not
void Users::viewFavouriteMessages()
{
	int choice;
	if (favorite.size() == 0) {
		cout << "You haven't any favorite messages yet" << endl;
		cout << "Put a message into your favorite box? (1, 0)" << endl;
		cin >> choice;
		if (choice == 1) {
			putMessageIntoFavorite();
		}
		return;
	}

	for (int i = 0; i < favorite.size(); i++) {
		cout << "Message " << i + 1 << ": " << endl;
		cout << "    Message: " << favorite[i].text << endl;
	}
}


bool Users::isContactExist(string contactId) {
	for (int i = 0; i < userContacts.size(); i++) {
		if (userContacts[i] == contactId) {
			return true;
		}
	}
	return false;
}

void Users::searchForContact() {
	string contactId;
	bool found = false;
	cout << "enter sender id" << endl;
	cin >> contactId;
	for (int i = 0; i < userContacts.size(); i++) {
		if (userContacts[i] == contactId) {
			cout << "This contact exists" << endl;
			return;
		}
	}
	cout << "This contact doesn't exist" << endl;
}

void Users::addUserToContacts() {
	cout << "Enter the id of the user: " << endl;
	string contactId;
	cin >> contactId;

	if (isContactExist(contactId)) {
		cout << "This contact already exist!" << endl;
	}
	if (!file.isContactExist(contactId) || contactId == id) {
		cout << "There is not a user with this id :(" << endl;
	}
	return;

	Contact contact;
	contact.Id = id;
	contact.contactId = contactId;
	userContacts.push_back(contactId);
	cout << "id: " << contact.Id << endl;
	cout << "contact id: " << contact.contactId << endl;
	file.Contacts.push_back(contact); //for all contacts
}

void Users::sendMessage() {
	cout << "Enter the id of the contact: " << endl;
	string contactId, senderMessage;
	cin >> contactId;
	Contact contact;
	if (!file.isContactExist(contactId) || contactId == id) {
		cout << "There is not a user with this id. try again " << endl;
		return;
	}
	cout << "Enter the message: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, senderMessage);
	Message message;
	message.userId = id;
	message.otherId = contactId;
	message.text = senderMessage;
	file.SentMessages.push_back(message);
	sent.push_back(message);

	message.userId = contactId;
	message.otherId = id;
	message.text = senderMessage;
	file.ReceivedMessages.push_back(message);
}

void Users::removeOldestFavoriteMessage()
{
	if (favorite.size() == 0) {
		cout << "There is not any message in favorite!" << endl;
	}
	return;

	favorite.erase(favorite.begin());
	file.FavoriteMessages.erase(file.FavoriteMessages.begin());
	cout << "the last message has been removed successfully" << endl;
}


void Users::putMessageIntoFavorite() {
	
	for (int i = 0; i < received.size(); i++) {
		cout << i+1 << ":  ID: "<<received[i].otherId <<":   "<<received[i].text<< endl;
	}

	int index;
	cout << "Write the number of the message you want: ";
	cin >> index;

	favorite.push_back(received.at(index-1));
	file.FavoriteMessages.push_back(received.at(index-1));
}


void Users::DisplayMessagesofSpecificContact() {

	string contactId;

	cout << "Enter contact id: ";
	cin >> contactId;

	if (!file.isContactExist(contactId)) {
		cout << "There is not a contact in yours with this id :(" << endl;
	}

	cout << "1- Received messages from this user:" << endl;
	for (int i = 0; i < received.size(); i++) {
		if (received[i].otherId == contactId) {
			cout << "Contact ID: " << received[i].otherId << endl;
			cout << "Message: " << received[i].text << endl << endl;
		}
	}

	cout << "2- Sent messages to this user:" << endl;
	for (int i = 0; i < sent.size(); i++) {
		if (sent[i].otherId == contactId) {
			cout << "Contact ID: " << sent[i].otherId << endl;
			cout << "Message: " << sent[i].text << endl << endl;
		}
	}

}

Users::~Users() {
	file.saveDataIntoContacts();
	file.saveDataIntoFavoriteMessages();
	file.saveDataIntoSentMessages();
	file.saveDataIntoReceivedMessages();
	file.saveDataIntoUsers();
}