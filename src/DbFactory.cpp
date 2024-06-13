//
// Created by stani on 10/06/2024.
//

#include "DbFactory.h"
#include "DbImpl/Mariadb/Mariadb.h"
#include "DbImpl/Postgres/Postgres.h"
#include "DbImpl/Sqlite/Sqlite.h"

IDbConnection *DbFactory::createConnection(const std::string &jdbcUrl) {
    return nullptr;
}
