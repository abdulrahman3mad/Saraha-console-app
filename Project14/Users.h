#pragma once
#include <string>
#include <vector>
#include "File.h"
using namespace std;

class Users
{
	string name;
	string password;
	string id;
	vector<Message> received;
	vector<Message> sent;
	vector<Message> favorite;
	vector<string> userContacts;

public:
	void setData(string n, string p, string d);
	bool registerUser();
	bool login();
	void viewContacts();
	void viewSentMessages();
	void viewRecievedMessages();
	void viewFavouriteMessages();
	bool isContactExist(string contactId);
	void searchForContact();
	void putMessageIntoFavorite();
	void addUserToContacts();
	void setFavoriteMessages();
	void setSentMessages();
	void setReceivedMessages();
	void setContacts();
	void DisplayMessagesofSpecificContact();
	void sendMessage();
	void removeOldestFavoriteMessage();
	~Users();

private:
	bool isExist(string name, string password, string id);
	bool isExist(string name, string id);
};

