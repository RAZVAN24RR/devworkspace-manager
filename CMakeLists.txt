cmake_minimum_required(VERSION 3.10)
project(devworkspace-manager)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(
        main
        main.cpp
        src/scan_dir/OldWayToScanDirectory.cpp
        src/scan_dir/NewWayToScanDirectory.cpp
        src/scan_dir/main.cpp src/scan_dir/Util.cpp
        src/scan_dir/classes/FileSystemEntry.cpp
)
