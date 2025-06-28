//
// Created by Pasaran Razvan on 28.06.2025.
//

#include "FileSystemEntry.h"
#include "Directory.h"
#include <filesystem>

Directory::Directory(const std::filesystem::path& path) : FileSystemEntry(path) {
    children_count = 0;
    total_size = 0;
    is_empty = true;
    subdirectory_count = 0;
    file_count = 0;
    scan();
}

void Directory::scan() {
    try {
        if (!std::filesystem::exists(this->getPath()) || !std::filesystem::is_directory(this->getPath())) {
            return;
        }

        children_count = 0;
        subdirectory_count = 0;
        file_count = 0;
        total_size = 0;

        for (const auto& entry : std::filesystem::directory_iterator(this->getPath())) {
            children_count++;

            if (entry.is_regular_file()) {
                file_count++;
                total_size += std::filesystem::file_size(entry);
            }
            else if (entry.is_directory()) {
                subdirectory_count++;
                for (const auto& sub_entry : std::filesystem::recursive_directory_iterator(entry)) {
                    if (sub_entry.is_regular_file()) {
                        total_size += std::filesystem::file_size(sub_entry);
                    }
                }
            }
        }

        is_empty = (children_count == 0);

    } catch (const std::filesystem::filesystem_error& ex) {
        children_count = 0;
        total_size = 0;
        is_empty = true;
        subdirectory_count = 0;
        file_count = 0;
    }
}

std::size_t Directory::getChildrenCount() const {
    return children_count;
}

std::uintmax_t Directory::getTotalSize() const {
    return total_size;
}

bool Directory::isEmpty() const {
    return is_empty;
}

std::size_t Directory::getSubdirectoryCount() const {
    return subdirectory_count;
}

std::size_t Directory::getFileCount() const {
    return file_count;
}