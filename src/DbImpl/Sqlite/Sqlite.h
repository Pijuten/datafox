//
// Created by stani on 04/05/2024.
//

#ifndef SQLITE_H
#define SQLITE_H
#include "../../Interfaces/IDbCommit.h"
#include "../../Interfaces/IDbConnection.h"
#include "../../Interfaces/IDbTransaction.h"
#include "../../Table/DatafoxTable.h"
#include "SQLiteCpp/SQLiteCpp.h"
#include "../../Model/ConnectionInfoModel.h"

class Sqlite : public IDbConnection,IDbCommit, IDbTransaction{
public:
    ~Sqlite() override;
    Sqlite(ConnectionInfoModel &connectionInfoModel):connectionInfoModel(connectionInfoModel){};
    bool Connect() override;
    bool Disconnect() override;
    void Commit() override;
    void Rollback() override;

    DatafoxTable Query(std::string &queryString) override;
    void Execute(std::string& executeString) override;
private:
    ConnectionInfoModel connectionInfoModel;
    SQLite::Database*c = nullptr;
    SQLite::Transaction *work = nullptr;
};



#endif //SQLITE_H
