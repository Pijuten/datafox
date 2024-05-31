//
// Created by stani on 31/05/2024.
//

#ifndef MARIADB_H
#define MARIADB_H

#include <mysql.h>

#include "../../Table/DatafoxTable.h"
#include "../../Interfaces/IDbConnection.h"
#include "../../Interfaces/IDbCommit.h"
#include "../../Interfaces/IDbTransaction.h"


class Mariadb : public IDbConnection, public IDbCommit, public IDbTransaction{
public:
    Mariadb(std::string connectionString):connectionString(connectionString){};
    ~Mariadb() override;
    bool Connect() override;
    bool Disconnect() override;
    void Commit() override;
    void Rollback() override;

    DatafoxTable Query(std::string &queryString) override;
    void Execute(std::string& executeString) override;
private:
    MYSQL *conn = mysql_init(NULL);
    MYSQL_RES *result = new MYSQL_RES;
    MYSQL_ROW row;;
    std::string connectionString;
};



#endif //MARIADB_H
