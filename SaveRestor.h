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

public:
    SaveRestor();
    ~SaveRestor();
    void createPath(const fs::path &Path, const fs::path &savePath);
    std::string&& saveUser(User& user);
    void saveUsers(std::vector<User>& users);
    void restorUsers(std::vector<User> &users);
};
