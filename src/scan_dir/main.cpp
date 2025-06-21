//
// Created by Pasaran Razvan on 20.06.2025.
//
#include "OldWayToScanDirectory.h"
#include "NewWayToScanDirectory.h"
#include "main.h"

void show_files(const std::vector<std::string>&files) {
  std::cout << "Acestea sunt fisierele gasite: \n";
    for (auto file:files) {
        std::cout << file << std::endl;
    }
}

void show_methods(){
    std::cout << "Scanez fisiere din directorul curent...\n";
    std::vector<std::string> old_dir = OldWayToScanDirectory(DIR_PRINCIPAL);
    std::cout << "Metoda veche: \n";
    show_files(old_dir);
    std::vector<std::string> new_dir = NewWayToScanDirectory(DIR_PRINCIPAL);
    std::cout << "Metoda noua: \n";
    show_files(new_dir);
    std::cout << "Dupa cum se poate vedea, metoda veche gaseste \".\" si \"..\", dar cea noua nu.";
}