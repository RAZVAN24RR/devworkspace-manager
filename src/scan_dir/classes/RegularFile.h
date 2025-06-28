//
// Created by Pasaran Razvan on 21.06.2025.
//

#pragma once
#include "FileSystemEntry.h"
using std::filesystem::path;

class RegularFile : public FileSystemEntry {
    private:
      std::uintmax_t file_size;
      std::string file_extension;
	public:
          RegularFile(const std::filesystem::path& path);
          std::uintmax_t getFileSize() const;
          std::string getFileExtension() const;
};

