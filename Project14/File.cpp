#include "File.h"
#include <ios>
#include <fstream>
#include <iostream>


File::File() {
	startProgram();
}

//used to get all contacts from its file and putting them into [Contacts] vector
void File::getContact() {
	fstream readingFile;
	string contactId;
	readingFile.open("D:\\contacts.txt", ios::in);
	Contact contact;
	while (getline(readingFile, contact.Id)) {
		getline(readingFile, contact.contactId);
		Contacts.push_back(contact);
		Contact contact;
	}
	readingFile.close();
}


// for getting all users from its file and putting them into AllUsers vector 
// used for login, register 
void File::getAllUsers() {
	fstream readingFile;
	readingFile.open("D:\\users.txt", ios::in);
	UserStruct user;
	while (getline(readingFile, user.name, ',')) {
		getline(readingFile, user.password, ',');
		getline(readingFile, user.id);
		AllUsers.push_back(user);
		UserStruct user;
	}
	readingFile.close();
}

//used as a global method for the next three methods- to get all data from messages files 
//----private ---
vector<Message> File::getMessagesData(string filePath, vector<Message> savingVector) {
	fstream readingFile;
	ifstream infile(filePath);
	if (infile.good()) {
		readingFile.open(filePath, ios::in);
		Message message;
		string newLine;
		while (getline(readingFile, message.userId)) {
			getline(readingFile, message.otherId);
			getline(readingFile, message.text);
			savingVector.push_back(message);
			getline(readingFile, newLine);
			Message message;
		}
		readingFile.close();
	}
	return savingVector;
}



void File::getReceivedMessages() {
	ReceivedMessages = getMessagesData("D:\\receivedMessages.txt", ReceivedMessages);
}

void File::getSentMessages() {
	SentMessages = getMessagesData("D:\\sentMessages.txt", SentMessages);
}

void File::getFavoriteMessages() {
	FavoriteMessages = getMessagesData("D:\\favoriteMessages.txt", FavoriteMessages);
}


//save users into its file
//called after register 
void File::saveDataIntoUsers() {
	fstream writingFile;
	writingFile.open("D:\\users.txt", ios::out);
	for (int x = 0; x < AllUsers.size(); x++) {
		writingFile << AllUsers[x].name << "," << AllUsers[x].password << "," << AllUsers[x].id << endl;
	}
}

//save contact into its file
//called after changes into contacts
void File::saveDataIntoContacts() {
	fstream writingFile;
	writingFile.open("D:\\contacts.txt", ios::out);
	for (int x = 0; x < Contacts.size(); x++) {
		writingFile << Contacts[x].Id << endl << Contacts[x].contactId << endl;
	}
	writingFile.close();
}

//global method for the next three methods, to write any data into messages files 
//--private--
void File::saveMessagesData(string filePath, vector<Message> writingVector) {
	fstream writingFile;
	writingFile.open(filePath, ios::out);
	for (int x = 0; x < writingVector.size(); x++) {
		writingFile << writingVector[x].userId << endl << writingVector[x].otherId << endl << writingVector[x].text << endl << endl;
	}
	writingFile.close();
}

void File::saveDataIntoSentMessages() {
	saveMessagesData("D:\\sentMessages.txt", SentMessages);
}

void File::saveDataIntoReceivedMessages() {
	saveMessagesData("D:\\receivedMessages.txt", ReceivedMessages);
}

void File::saveDataIntoFavoriteMessages() {
	saveMessagesData("D:\\favoriteMessages.txt", FavoriteMessages);
}

// used after any changes in files, to get all the data from all files  
// and set them into all vectors 
void File::startProgram() {
	getAllUsers();
	getContact();
	getReceivedMessages();
	getSentMessages();
	getFavoriteMessages();
}


//to check if a particular user exists or not 
bool File::isContactExist(string contactId)
{
	for (int i = 0; i < AllUsers.size(); i++) {
		if (AllUsers[i].id == contactId) {
			return true;
		}
	}
	return false;
}
