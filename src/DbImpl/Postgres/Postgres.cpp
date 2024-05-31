//
// Created by stani on 4/28/24.
//

#include "Postgres.h"
#include "../../Table/DatafoxTable.h"
#include <iostream>

bool Postgres::Disconnect() {
    if (c != nullptr) {
        try {
            c->close();
            return true;
        } catch (std::exception const &e) {
            std::cerr << e.what() << std::endl;
            return false;
        }
    }
    return true;
}

void Postgres::Commit() {
    if (work != nullptr) {
        work->commit();
    }
}

void Postgres::Rollback() {
    if (work != nullptr) {
        work->abort();
    }
}

bool Postgres::Connect() {
    try {
        c = new pqxx::connection{connectionString};
        if (c->is_open()) {
            work = new pqxx::work(*c);
            return true;
        }
        return false;
    } catch (std::exception const &e) {
        std::cerr << e.what() << '\n';
        return false;
    }
}

Postgres::~Postgres() {
    delete work;
    delete c;
}

DatafoxTable Postgres::Query(std::string &queryString) {
    if (work!= nullptr) {
        DatafoxTable datafox_table;
        pqxx::result result = work->exec(queryString); // Adjusted to match pqxx function

        // Assuming you cannot directly access metadata(), manually collecting column names
        std::vector<std::string> columnNames;
        int columnIndex = 0;
        for (auto const &row : result) {
            std::vector<std::string> rowData;
            if (columnIndex == 0) { // Only collect column names once
                for (auto const &field : row) {
                    rowData.emplace_back(field.name()); // Assuming field.name() gives the column name
                }
                datafox_table.AddRow(rowData);
                rowData.clear();
                columnIndex++;
            }
            for (auto const &field : row) {
                if (field.is_null()) {
                    rowData.emplace_back("null"); // Handle NULL by pushing an empty string or any default value
                } else {
                    rowData.push_back(field.as<std::string>());
                }
            }
            datafox_table.AddRow(rowData);
        }

        // Now columnNames contains the names of all columns in the result set
        // You can use columnNames as needed, for example, adding them to your datafox_table structure

        return datafox_table;
    }
    return {};
}
void Postgres::Execute(std::string &executeString) {
    if (work != nullptr) {
        work->exec(executeString);
    }
}
