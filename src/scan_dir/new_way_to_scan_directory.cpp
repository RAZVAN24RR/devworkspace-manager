//
// Created by Pasaran Razvan on 20.06.2025.
//
#include "new_way_to_scan_directory.h"
#include <filesystem>
#include "util.h"
namespace fs = std::filesystem;

std::vector<std::string> new_way_to_scan_directory(const char * file_path){
  std::vector<std::string> new_way_to_scan_dir;
  for(const auto&entry:fs::directory_iterator(file_path)) {
    new_way_to_scan_dir.push_back(entry.path());
  }
  procesare_fisier::merge();
  return new_way_to_scan_dir;
}