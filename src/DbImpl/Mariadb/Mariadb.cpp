//
// Created by stani on 31/05/2024.
//

#include "Mariadb.h"

Mariadb::~Mariadb() {
    free(result);
    free(conn);
}

bool Mariadb::Connect() {

    if (!conn) {
        return false;
    }
    mysql_autocommit(conn, false);
    if (mysql_real_connect(conn,
                           connectionInfoModel.getHost().c_str(),
                           connectionInfoModel.getUser().c_str(),
                           connectionInfoModel.getPassword().c_str(),
                           connectionInfoModel.getDb().c_str(),
                           connectionInfoModel.getPort(),
                           connectionInfoModel.getUnixSocket().c_str(),
                           0) == nullptr) {
        return false;
    }
    return true;
}

bool Mariadb::Disconnect() {
    mysql_close(conn);
    return true;
}

void Mariadb::Commit() {
    mysql_commit(conn);
}

void Mariadb::Rollback() {
    mysql_rollback(conn);
}

DatafoxTable Mariadb::Query(std::string &queryString) {
    if (!conn) {
        return {};
    }
    if (mysql_query(conn, queryString.c_str())) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        return {};
    }
    DatafoxTable table;
    result = mysql_store_result(conn);
    row = mysql_fetch_row(result);
    while (row) {
        for (int i = 0; i < mysql_num_fields(result); i++) {
            printf("%s\n", row[i]);
        }
        row = mysql_fetch_row(result);
    }
    mysql_free_result(result);
    return table;
}

void Mariadb::Execute(std::string &executeString) {
    MYSQL_STMT *stmt = mysql_stmt_init(conn);
    if (mysql_stmt_prepare(stmt, executeString.c_str(), executeString.length())) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        return;
    }
    if (mysql_stmt_execute(stmt)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        return;
    }
    mysql_stmt_close(stmt);
}

bool Mariadb::CheckConnection() {
    if (mysql_ping(conn) == 0)
        return true;
    return false;
}
