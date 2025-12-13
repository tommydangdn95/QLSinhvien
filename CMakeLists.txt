cmake_minimum_required(VERSION 3.29)
project(QLSinhvien)

set(CMAKE_CXX_STANDARD 20)

add_executable(QLSinhvien main.cpp
        src/MonHoc.cpp
        src/Diem.cpp
        includes/MonHoc.h
        includes/SinhVien.h
        src/SinhVien.cpp
        includes/Diem.h
        includes/BangDiem.h
        src/Node.cpp
        includes/Node.h
        src/BangDiem.cpp
        includes/LinkedList.h
        src/LinkedList.cpp
        includes/QLSinhVienService.h
        src/QLSinhVienService.cpp
        includes/QLMonHocService.h
        src/QLMonHocService.cpp
        includes/AppService.h
        src/AppService.cpp
)
