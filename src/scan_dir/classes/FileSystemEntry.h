//
// Created by Pasaran Razvan on 21.06.2025.
//

#pragma once
#include <iostream>
#include <filesystem>

using std::string;
using std::filesystem::path;
using std::filesystem::perms;

class FileSystemEntry {

private:
    std::string name;
    std::filesystem::path path;
    std::filesystem::path parent_path;
    std::filesystem::perms permissions;
    std::string owner;
    std::string group_name;
    std::filesystem::file_time_type creation_time;
    std::filesystem::file_time_type last_modified;
    std::filesystem::file_time_type last_accessed;
    bool is_hidden;
public:
    FileSystemEntry(const std::filesystem::path& path);
    std::string getName() const;
    std::filesystem::path getPath() const;
    std::filesystem::path getParentPath() const;
    std::filesystem::file_time_type getCreationTime() const;
    std::filesystem::file_time_type getLastModified() const;
    std::filesystem::file_time_type getLastAccessed() const;
	std::string getOwner() const;
    std::string getGroupName() const;
    std::uintmax_t getFileSize() const;
};

