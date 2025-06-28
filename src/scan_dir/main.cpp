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
#include <iostream>
#include <iomanip>

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

void printMetrics() {
    std::cout << "\n" << std::string(50, '=') << std::endl;
    std::cout << "           FILESYSTEM METRICS" << std::endl;
    std::cout << std::string(50, '=') << std::endl;

    // Basic counts
    std::cout << std::left << std::setw(25) << "Total entries:" << fileSystemEntries.size() << std::endl;
    std::cout << std::left << std::setw(25) << "Regular files:" << regularFiles.size() << std::endl;
    std::cout << std::left << std::setw(25) << "Directories:" << dirs.size() << std::endl;

    // File size metrics
    std::uintmax_t totalSize = 0;
    std::uintmax_t largestFile = 0;
    std::string largestFileName = "";

    for(const auto& file : regularFiles) {
        std::uintmax_t size = file->getFileSize();
        totalSize += size;
        if(size > largestFile) {
            largestFile = size;
            largestFileName = file->getName();
        }
    }

    std::cout << std::string(50, '-') << std::endl;
    std::cout << std::left << std::setw(25) << "Total size:" << formatBytes(totalSize) << std::endl;
    std::cout << std::left << std::setw(25) << "Average file size:" <<
                 (regularFiles.empty() ? "0 B" : formatBytes(totalSize / regularFiles.size())) << std::endl;
    std::cout << std::left << std::setw(25) << "Largest file:" << formatBytes(largestFile) << std::endl;
    std::cout << std::left << std::setw(25) << "Largest file name:" << largestFileName << std::endl;

    // Directory metrics
    std::cout << std::string(50, '-') << std::endl;
    std::size_t totalChildren = 0;
    std::size_t largestDirChildren = 0;
    std::string largestDirName = "";

    for(const auto& dir : dirs) {
        std::size_t children = dir->getChildrenCount();
        totalChildren += children;
        if(children > largestDirChildren) {
            largestDirChildren = children;
            largestDirName = dir->getName();
        }
    }

    std::cout << std::left << std::setw(25) << "Total dir children:" << totalChildren << std::endl;
    std::cout << std::left << std::setw(25) << "Avg children per dir:" <<
                 (dirs.empty() ? "0" : std::to_string(totalChildren / dirs.size())) << std::endl;
    std::cout << std::left << std::setw(25) << "Largest directory:" << largestDirName <<
                 " (" << largestDirChildren << " items)" << std::endl;

    // File type breakdown
    std::cout << std::string(50, '-') << std::endl;
    std::cout << "FILE TYPE BREAKDOWN:" << std::endl;

    std::map<std::string, int> extensionCount;
    for(const auto& file : regularFiles) {
        std::string ext = file->getFileExtension();
        if(ext.empty()) ext = "[no extension]";
        extensionCount[ext]++;
    }

    for(const auto& pair : extensionCount) {
        std::cout << std::left << std::setw(15) << pair.first << ": " << pair.second << std::endl;
    }

    std::cout << std::string(50, '=') << std::endl;
}

std::string formatBytes(std::uintmax_t bytes) {
    const char* units[] = {"B", "KB", "MB", "GB", "TB"};
    int unitIndex = 0;
    double size = static_cast<double>(bytes);

    while(size >= 1024.0 && unitIndex < 4) {
        size /= 1024.0;
        unitIndex++;
    }

    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << size << " " << units[unitIndex];
    return oss.str();
}

void show_methods(){
    fileSystemEntries = NewWayToScanDirectory(DIR_PRINCIPAL);
    std::cout << "Build classes: \n";
    build_entries(fileSystemEntries);

    // Print detailed metrics
    printMetrics();
}