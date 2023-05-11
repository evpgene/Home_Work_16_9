#pragma once
#include <string>
#include <vector>
#include "Message.h"
class Chat
{
public:
	Chat();
	explicit Chat(const std::string& chatname);
	~Chat();
	void setID(unsigned long long);
	void printMessage();
	void addMessage(const Message& message);
	unsigned long long getID() const;
	void printChatName() const;
	std::string getChatName() const;
protected:
	std::string _chatname;
	int userID[2]{ 0 };
	unsigned long long _ID{ 0 };
	std::vector<Message> _messages;
};

