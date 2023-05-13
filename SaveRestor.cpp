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
			fs::perm_options::remove);
	}
	else
	{
	}
};

void SaveRestor::saveUsers(std::vector<User> &users)
{
	std::string filename{savePath / "Users"};
	std::fstream s{filename, s.binary | s.trunc | s.in | s.out};

	if (!s.is_open())
		std::cout << "failed to open " << filename << '\n';
	else
	{
		for (auto user : users)
		{
			// s << ID << sep << user._ << endl;
			// s << log << sep << user._login << endl;
			// s << pas << sep << user._pass << endl; // text output
		}

		// write

		// for fstream, this moves the file position pointer (both put and get)
		// s.seekp(0);
	}
	s.close();
}
void SaveRestor::restorUsers(std::vector<User> &users)
{
	// read
	std::string filename{savePath / "Users"};
	std::fstream s{filename, s.binary | s.trunc | s.in | s.out};

	if (!s.is_open())
		std::cout << "failed to open " << filename << '\n';
	else
	{

		for (std::string line; std::getline(s, line);)
		{
			// int n = line.find(log);

			// if (n != std::string::npos)
			// {
			// 	int m = line.find(sep);
			// 	if (m != std::string::npos)
			// 	{
			// 		std::cout << "логин: " << std::quoted(line.substr(m + sep.length())) << std::endl;
			// 	}
			// }
		}
	}
}