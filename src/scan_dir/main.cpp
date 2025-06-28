//
// Created by Pasaran Razvan on 20.06.2025.
//
#include "OldWayToScanDirectory.h"
#include "NewWayToScanDirectory.h"
#include "classes/FileSystemEntry.h"
#include "main.h"

void show_files(const std::vector<FileSystemEntry>&files) {
  std::cout << "Acestea sunt fisierele gasite: \n";
    for(const auto &entry : files){
      std::cout << entry.getName() << "\n" << entry.getName() << "\n";
    }
}

void show_methods(){
    std::vector<FileSystemEntry> new_dir = NewWayToScanDirectory(DIR_PRINCIPAL);
    std::cout << "Metoda noua: \n";
    show_files(new_dir);
}