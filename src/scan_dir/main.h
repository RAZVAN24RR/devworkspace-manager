//
// Created by Pasaran Razvan on 20.06.2025.
//

#pragma once
#include <iostream>
#define DIR_PRINCIPAL "../"
#include <map>
#include <sstream>
void show_methods();
void build_entries(const std::vector<std::string>&files);
void printMetrics();
std::string formatBytes(std::uintmax_t bytes);
