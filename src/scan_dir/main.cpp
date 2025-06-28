//
// Created by Pasaran Razvan on 20.06.2025.
//

#include "OldWayToScanDirectory.h"
#include "NewWayToScanDirectory.h"
#include "classes/FileSystemEntry.h"
#include "classes/RegularFile.h"
#include "classes/Directory.h"
#include "main.h"
#include <vector>
#include <memory>

std::vector<std::shared_ptr<FileSystemEntry> > fileSystemEntries;
std::vector<std::shared_ptr<RegularFile> > regularFiles;
std::vector<std::shared_ptr<Directory> > dirs;

void build_entries(const std::vector<std::shared_ptr<FileSystemEntry> >&files) {
  std::cout << "The classes are building..: \n";
    regularFiles.clear();
    dirs.clear();
    for(const auto &entry : files){
        if(entry->isDirectory()){
            auto dir = std::make_shared<Directory>(entry->getPath());
            dirs.push_back(dir);
        }
        else if(entry->isFile()){
            auto file = std::make_shared<RegularFile>(entry->getPath());
            regularFiles.push_back(file);
        }
    }
}

void show_methods(){
    fileSystemEntries = NewWayToScanDirectory(DIR_PRINCIPAL);
    std::cout << "Build classes: \n";
    build_entries(fileSystemEntries);
}