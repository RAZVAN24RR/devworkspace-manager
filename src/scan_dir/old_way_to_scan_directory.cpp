//
// Created by Pasaran Razvan on 20.06.2025.
//

#include "old_way_to_scan_directory.h"
#include "util.h"

std::vector<std::string> old_way_to_scan_directory(const char *filePath) {
  std::vector<std::string> files;
  DIR *dr;
    struct dirent *en;
    dr = opendir(filePath);
    if (dr) {
        while ((en = readdir(dr))!=NULL) {
            files.push_back(en->d_name);
        }
    }
    procesare_fisier::merge();
    closedir(dr);
    return files;
}