#pragma once
#include <string>
#include <vector>
using namespace std;

struct Message {
	string userId;
	string otherId;
	string text;
};

struct Contact {
	string Id;
	string contactId;
};

struct UserStruct {
	string name;
	string id;
	string password;
};

class File {

public:
	vector<UserStruct> AllUsers;
	vector<Contact> Contacts;
	vector<Message> ReceivedMessages;
	vector<Message> SentMessages;
	vector<Message> FavoriteMessages;

	File();
	void getContact();
	void getReceivedMessages();
	void getSentMessages();
	void getFavoriteMessages();
	void getAllUsers();
	void saveDataIntoUsers();
	void saveDataIntoContacts();
	void saveDataIntoSentMessages();
	void saveDataIntoReceivedMessages();
	void saveDataIntoFavoriteMessages();
	void startProgram();
	bool isContactExist(string contactName);

private:
	vector<Message> getMessagesData(string filePath, vector<Message> savingVector);
	void saveMessagesData(string filePath, vector<Message> writingVector);
};