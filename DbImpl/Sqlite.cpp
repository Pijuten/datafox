//
// Created by stani on 04/05/2024.
//

#include "Sqlite.h"

#include <iostream>
#include "../DatafoxTable.h"

Sqlite::~Sqlite() {
    delete work;
    delete c;
}

bool Sqlite::ChangeDb() {
    try {
        delete work;
        delete c;
        c = new SQLite::Database(connectionString, SQLite::OPEN_READWRITE);
        work = new SQLite::Transaction(*c);
        return true;
    } catch (std::exception const &e) {
        std::cerr << e.what() << std::endl;
        return false;
    }
}

bool Sqlite::Connect() {
    try {
        c = new SQLite::Database(connectionString, SQLite::OPEN_READWRITE);
        work = new SQLite::Transaction(*c);
        return true;
    } catch (std::exception const &e) {
        std::cerr << e.what() << std::endl;
        return false;
    }
}

bool Sqlite::Disconnect() {
    return true;
}

void Sqlite::Commit() {
    if (work != nullptr) {
        try {
            work->commit();
        } catch (std::exception const &e) {
            std::cerr << e.what() << std::endl;
        }
    }
}

void Sqlite::Rollback() {
    work->rollback();
}

DatafoxTable Sqlite::Query(std::string &queryString) {
    DatafoxTable datafox_table;
    SQLite::Statement query(*c, queryString);
    while (query.executeStep()) {
        std::vector<std::string> row;
        int columnCtn = query.getColumnCount();
        row.reserve(columnCtn);
        for (int i = 0; i < columnCtn; i++) {
            row.push_back(query.getColumn(i).getString());
        }
        datafox_table.AddRow(row);
    }
    return datafox_table;
}

void Sqlite::Execute(std::string &executeString) {
    if (c != nullptr) {
        try {
            c->exec(executeString);
        } catch (std::exception const &e) {
            std::cerr << e.what() << std::endl;
        }
    }
}
