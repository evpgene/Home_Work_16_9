#pragma once
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
class Chat;
class User;
class Message;

namespace fs = std::filesystem;

class SaveRestor
{
private:

    fs::path const Path{"/tmp"};
    fs::path const savePath{"/tmp/Chat_Yevgeniy"};
    fs::path const savePathChats{savePath / "Chats"};
    const std::string ID{"ID:"};             // login
    const std::string log{"login:"};         // login
    const std::string pas{"password:"};      // password
    const std::string name{"username:"};     // user name
    const std::string timesend{"timesend:"}; // user name
    const std::string mess{"message:"};      // user name
    std::string sep{" "};                    // separator



public:
    SaveRestor();
    ~SaveRestor();
    void createPath(const fs::path &Path, const fs::path &savePath);

    std::string saveUser(User &user);
    std::shared_ptr<User> restorUser(std::string &str);

    void saveChat(std::shared_ptr<Chat> chat);
    std::shared_ptr<Chat> restorChat(fs::path path);

    std::string saveMessage(Message &message);
    std::shared_ptr<Message> restorMessage(std::string &str);

    void saveUsers(std::vector<User> &users);
    void restorUsers(std::vector<User> &users);

    void restorChats(std::vector<std::shared_ptr<Chat>>& chats);
    void saveChats(std::vector<std::shared_ptr<Chat>> chats);
};
