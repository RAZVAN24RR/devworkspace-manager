//
// Created by Pasaran Razvan on 21.06.2025.
//

#include "FileSystemEntry.h"
#include <string>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <unistd.h>
using namespace std;
using namespace std::filesystem;

FileSystemEntry::FileSystemEntry(const std::filesystem::path& path){
	this->path = path;
	this->parent_path = path.parent_path();
    this->name = path.filename().string();
    this->is_hidden = !this->name.empty() && this->name[0] == '.';
    this->permissions = std::filesystem::status(path).permissions();

    this->last_modified = std::filesystem::last_write_time(path);
    this->creation_time = std::filesystem::last_write_time(path);

    struct stat file_stat;
    if(stat(path.c_str(), &file_stat) == 0){
      this->last_accessed = std::filesystem::file_time_type(
    std::chrono::duration_cast<std::filesystem::file_time_type::duration>(
        std::chrono::system_clock::from_time_t(file_stat.st_atime).time_since_epoch()
    	)
	);


      struct passwd* pw = getpwuid(file_stat.st_uid);
        if (pw != nullptr) {
            this->owner = pw->pw_name;
        }

        struct group* gr = getgrgid(file_stat.st_gid);
        if (gr != nullptr) {
            this->group_name = gr->gr_name;
        }
    }

};

std::string FileSystemEntry::getName() const{
  return this->name;
}
std::filesystem::path FileSystemEntry::getPath() const{
  return this->path;
}

std::filesystem::path FileSystemEntry::getParentPath() const{
  return this->parent_path;
}

std::filesystem::file_time_type FileSystemEntry::getCreationTime() const{
  return this->creation_time;
};

std::filesystem::file_time_type FileSystemEntry::getLastModified() const{
  return this->last_modified;
};

std::filesystem::file_time_type FileSystemEntry::getLastAccessed() const{
  return this->last_accessed;
};

std::string FileSystemEntry::getOwner() const{
  return this->owner;
};

std::string FileSystemEntry::getGroupName() const{
  return this->group_name;
};

bool FileSystemEntry::isFile(){
  return std::filesystem::is_regular_file(this->getPath());
}
bool FileSystemEntry::isDirectory(){
  return std::filesystem::is_directory(this->getPath());
}