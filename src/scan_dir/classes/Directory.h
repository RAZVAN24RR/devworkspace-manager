//
// Created by Pasaran Razvan on 28.06.2025.
//

#pragma once
#include "FileSystemEntry.h"
#include <cstddef>

class Directory : public FileSystemEntry {
private:
    std::size_t children_count;
    std::uintmax_t total_size;
    bool is_empty;
    std::size_t subdirectory_count;
    std::size_t file_count;

public:
    Directory(const std::filesystem::path& path);
    std::size_t getChildrenCount() const;
    std::uintmax_t getTotalSize() const;
    bool isEmpty() const;
    std::size_t getSubdirectoryCount() const;
    std::size_t getFileCount() const;
    void scan();
};