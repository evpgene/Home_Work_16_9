#pragma once
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
class Chats;
class User;

namespace fs = std::filesystem;

class SaveRestor
{
private:
    /* data */

    fs::path const Path{"/tmp"};
    fs::path const savePath{"/tmp/Chat_Yevgeniy"};
    const std::string ID{"ID:"};     // login
    const std::string log{"login:"};     // login
    const std::string pas{"password:"};  // password
    const std::string name{"username:"}; // user name
    std::string sep{" "};        // separator

public:
    SaveRestor();
    ~SaveRestor();
    void createPath(const fs::path &Path, const fs::path &savePath);
    std::string saveUser(User& user);
    std::shared_ptr<User> restorUser(std::string& str);
    void saveUsers(std::vector<User>& users);
    void restorUsers(std::vector<User> &users);
};
