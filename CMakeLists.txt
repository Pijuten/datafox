# CMakeLists.txt
cmake_minimum_required(VERSION 3.28)
project(DFox)

# Set the C++ standard to C++17
set(CMAKE_CXX_STANDARD 23)

# Locate GTest package
find_package(libpqxx CONFIG REQUIRED)
find_package(SQLiteCpp CONFIG REQUIRED)
find_package(unofficial-mysql-connector-cpp CONFIG REQUIRED)
find_package(unofficial-libmariadb CONFIG REQUIRED)
find_package(GTest REQUIRED)
# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests
        src/Main.cpp
        src/DbImpl/Mariadb/Mariadb.cpp
        src/DbImpl/Mariadb/Mariadb.h
        src/DbImpl/Postgres/Postgres.cpp
        src/DbImpl/Postgres/Postgres.h
        src/DbImpl/Sqlite/Sqlite.cpp
        src/DbImpl/Sqlite/Sqlite.h
        src/Interfaces/IDbCommit.h
        src/Interfaces/IDbConnection.h
        src/Interfaces/IDbTransaction.h
        src/Table/DatafoxTable.cpp
        src/Table/DatafoxTable.h
        test/MariaDb/Mariadb_test.cpp
        src/DbFactory.cpp
        src/DbFactory.h
        src/Model/ConnectionInfoModel.cpp
        src/Model/ConnectionInfoModel.h
)
target_link_libraries(runTests PRIVATE libpqxx::pqxx SQLiteCpp unofficial::mysql-connector-cpp::connector  unofficial::libmariadb GTest::gtest)