#include <iostream>
#include "DbImpl/Postgres.h"
#include "DbImpl/Sqlite.h"

int main() {

    std::string connectionString = R"(host=localhost port=5432 dbname=postgres user=root password=root)";
    Postgres postgres(connectionString);
    postgres.Connect();
    std::string cmd = "SELECT * FROM tour";
    DatafoxTable result = postgres.Query(cmd);
    postgres.Disconnect();
    result.printTable();
    return 0;
}
