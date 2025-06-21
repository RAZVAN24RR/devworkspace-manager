//
// Created by Pasaran Razvan on 20.06.2025.
//
#include "NewWayToScanDirectory.h"
#include <filesystem>
#include "util.h"
using std::filesystem::directory_iterator;

std::vector<std::string> NewWayToScanDirectory(const char * file_path){
  std::vector<std::string> new_way_to_scan_dir;
   for(const auto&entry:std::filesystem::directory_iterator (file_path)) {
    new_way_to_scan_dir.push_back(entry.path());
  }
  procesare_fisier::merge();
  return new_way_to_scan_dir;
}