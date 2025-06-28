//
// Created by Pasaran Razvan on 20.06.2025.
//

#pragma once
#include <iostream>
#include "classes/FileSystemEntry.h"
#include <vector>
#include <memory>

std::vector<std::shared_ptr<FileSystemEntry> > NewWayToScanDirectory(const char *file_path);

