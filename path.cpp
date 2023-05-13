#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>

	namespace fs = std::filesystem;

void path(const fs::path&  Path, const fs::path&  savePath)
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
}