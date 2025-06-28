//
// Created by Pasaran Razvan on 21.06.2025.
//

#include "RegularFile.h"
#include "FileSystemEntry.h"
using namespace std;
using namespace std::filesystem;

RegularFile::RegularFile(const std::filesystem::path& path) : FileSystemEntry(path) {
    this -> file_size = std::filesystem::file_size(path);
    this -> file_extension = std::filesystem::path(path).extension();
}

std::uintmax_t RegularFile::getFileSize() const {
  return this->file_size;
}

std::string RegularFile::getFileExtension() const {
  return this->file_extension;
}
