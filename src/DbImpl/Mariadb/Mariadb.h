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
#include "../../Model/ConnectionInfoModel.h"


class Mariadb : public IDbConnection, public IDbCommit, public IDbTransaction{
public:
    Mariadb(ConnectionInfoModel &connectionInfoModel):connectionInfoModel(connectionInfoModel){};
    ~Mariadb() override;
    bool Connect() override;
    bool Disconnect() override;
    void Commit() override;
    void Rollback() override;
    bool CheckConnection();

    DatafoxTable Query(std::string &queryString) override;
    void Execute(std::string& executeString) override;
private:
    ConnectionInfoModel connectionInfoModel;
    MYSQL *conn = mysql_init(NULL);
    MYSQL_RES *result = new MYSQL_RES;
    MYSQL_ROW row;;
};



#endif //MARIADB_H
