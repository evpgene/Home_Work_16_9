#pragma once
#include <memory>
#include <string>
#include <vector>
#include "Chat.h"

using namespace std;

class User
{
public:
	User();
	explicit User(std::string);
	~User();
	void setID(unsigned long long);
	void setLogin(std::string);
	void setPass(std::string);
	unsigned long long getID() const;
	std::string getLogin() const;
	std::string getPass() const;
	void printUser() const;
	void addChat(shared_ptr<Chat> chat);
	void printChatNames();
private:
	std::string _login;
	std::string _pass;
	unsigned long long _ID{ 0 };

	std::vector<shared_ptr<Chat>> _chats;
	std::vector<int> _readPos; // array of chats read positions

};
