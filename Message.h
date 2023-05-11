#pragma once
#include <string>
class Message
{
public:
	Message();

	~Message();
	void userName(const std::string& userName);
	void setMessage(const std::string& message);
	void setTimeSend(const std::string& time);
	void printMessage() const;
private:
	std::string _userName;
	std::string _timeSend;
	std::string _message;
	std::string _timeRead;
};

