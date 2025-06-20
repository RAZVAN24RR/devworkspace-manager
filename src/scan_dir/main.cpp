//
// Created by Pasaran Razvan on 20.06.2025.
//
#include "old_way_to_scan_directory.h"
#include "new_way_to_scan_directory.h"
#include "main.h"

void show_files(const std::vector<std::string>&files) {
  std::cout << "Acestea sunt fisierele gasite: \n";
    for (auto file:files) {
        std::cout << file << std::endl;
    }
}

void show_methods(){
    std::cout << "Scanez fisiere din directorul curent...\n";
    std::vector<std::string> old_dir = old_way_to_scan_directory(DIR_STRING);
    std::cout << "Metoda veche: \n";
    show_files(old_dir);
    std::vector<std::string> new_dir = new_way_to_scan_directory(DIR_STRING);
    std::cout << "Metoda noua: \n";
    show_files(new_dir);
}