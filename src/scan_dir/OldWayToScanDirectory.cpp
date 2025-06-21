//
// Created by Pasaran Razvan on 20.06.2025.
//

#include <iostream>
#include <stdlib.h>
#include <dirent.h>
#include <vector>
#include "OldWayToScanDirectory.h"
#include "Util.h"

std::vector<std::string> OldWayToScanDirectory(const char *filePath) {
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