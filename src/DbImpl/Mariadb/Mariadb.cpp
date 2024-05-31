//
// Created by stani on 31/05/2024.
//

#include "Mariadb.h"

#include "DbConnectionModel.h"


Mariadb::~Mariadb() {
    free(result);
    free(conn);
}

bool Mariadb::Connect() {

    if(!conn){
        return false;
    }
    mysql_autocommit(conn, false);
    DbConnectionModel model;
    model.parseJDBCUrl(connectionString);
    if(mysql_real_connect(conn,
        model.get_host().c_str(),
        model.get_user().c_str(),
        model.get_password().c_str(),
        model.get_db().c_str(),
        model.get_port(),
        model.get_unix_socket().c_str(),
        0) == nullptr){
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
    if(!conn) {
        return {};
    }
    if(mysql_query(conn, queryString.c_str())) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        return {};
    }
    DatafoxTable table;
    result = mysql_store_result(conn);
    while(row = mysql_fetch_row(result)) {
        for(int i = 0; i < mysql_num_fields(result); i++) {
            printf("%s\n", row[i]);
        }
    }
    mysql_free_result(result);
    return table;
}

void Mariadb::Execute(std::string &executeString) {
    MYSQL_STMT *stmt = mysql_stmt_init(conn);
    if(mysql_stmt_prepare(stmt, executeString.c_str(), executeString.length())) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        return;
    }
    if(mysql_stmt_execute(stmt)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        return;
    }
    mysql_stmt_close(stmt);
}
