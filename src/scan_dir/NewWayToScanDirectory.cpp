//
// Created by Pasaran Razvan on 20.06.2025.
//
#include "NewWayToScanDirectory.h"
#include <filesystem>
#include "Util.h"
using std::filesystem::directory_iterator;

std::vector<FileSystemEntry> NewWayToScanDirectory(const char * file_path){
  std::vector<FileSystemEntry> files;
   for(const auto&entry:std::filesystem::directory_iterator (file_path)) {
    files.push_back(FileSystemEntry(entry.path()));
  }
  return files;
}