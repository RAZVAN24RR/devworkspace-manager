//
// Created by Pasaran Razvan on 20.06.2025.
//
#include "NewWayToScanDirectory.h"
#include <filesystem>
#include "Util.h"
using std::filesystem::directory_iterator;

std::vector<std::shared_ptr<FileSystemEntry> >NewWayToScanDirectory(const char * file_path){
  std::vector<std::shared_ptr<FileSystemEntry> > files;
   for(const auto&entry:std::filesystem::directory_iterator (file_path)) {
       files.push_back(std::make_shared<FileSystemEntry>(entry.path()));
  }
  return files;
}