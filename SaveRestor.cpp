#include "SaveRestor.h"
#include "User.h"

SaveRestor::SaveRestor()
{
}

SaveRestor::~SaveRestor()
{
}

void SaveRestor::createPath(const fs::path &Path, const fs::path &savePath)
{
	if (!fs::exists(Path))
		fs::create_directory(Path);
	if (!fs::exists(savePath))
		fs::create_directory(savePath);
	if (fs::exists(savePath))
	{
		fs::permissions(
			savePath,
			fs::perms::owner_all,
			fs::perm_options::add);
		fs::permissions(
			savePath,
			fs::perms::owner_exec | fs::perms::others_all | fs::perms::group_all,
			fs::perm_options::add);
	}
	else
	{
	}
};

std::string SaveRestor::saveUser(User &user)
{
	return ID + sep + to_string(user._ID) + " " + log + sep + user._login + " " + pas + sep + user._pass;
};

void SaveRestor::saveUsers(std::vector<User> &users)
{
	// write
	std::string filename{savePath / "Users"};
	std::fstream s{filename, s.binary | s.trunc | s.in | s.out};

	s.clear();

	if (!s.is_open())
		std::cout << "failed to open " << filename << '\n';
	else
	{
		for (auto user : users)
		{
			s << saveUser(user) << endl;
		}
	}
	s.close();
}

std::shared_ptr<User> SaveRestor::restorUser(std::string &str)
{

	// std::vector<std::string> buf;
	bool nextIsID{false}, doneID{false}, nextIsLogin{false}, doneLogin{false}, nextIsPass{false}, donePass{false};
	std::string word;
	shared_ptr<User> user = make_shared<User>(User());
	std::istringstream iss(str);
	while (iss >> word)
	{
		std::cout << word << std::endl;
		if (nextIsID)
		{
			user->setID(stoll(word));
			nextIsID = false;
			doneID = true;
		};
		if (nextIsLogin)
		{
			user->setLogin(word);
			nextIsLogin = false;
			doneLogin = true;
		};
		if (nextIsPass)
		{
			user->setPass(word);
			nextIsPass = false;
			donePass = true;
		};
		if (word == ID)
		{
			nextIsID = true;
		}
		if (word == log)
		{
			nextIsLogin = true;
		}
		if (word == pas)
		{
			nextIsPass = true;
		}
	}
	if (doneID && doneLogin/*  && donePass */) // donePass может отсутствовать для общего чата
	{
		return user;
	}
	return nullptr;
}

void SaveRestor::restorUsers(std::vector<User> &users)
{
	// read
	std::string filename{savePath / "Users"};
	std::fstream s{filename};

	if (!s.is_open())
		std::cout << "failed to open " << filename << '\n';
	else
	{
		s.seekg(0);
		std::cout << "opened " << filename << '\n';
		for (std::string line; std::getline(s, line);)
		{
			std::cout << line << '\n'; // для диагностики - можно убрать
			tmp_ptr = *restorUser(line);
			if (tmp_ptr)
				users.push_back(tmp_ptr);
			else
				std::cout << "User one does not restore"
		}
	}
	s.close();
}