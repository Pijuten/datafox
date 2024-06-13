//
// Created by stani on 04/05/2024.
//

#ifndef SQLITE_H
#define SQLITE_H
#include "../IDbCommit.h"
#include "../IDbConnection.h"
#include "../IDbTransaction.h"
#include "../IDbChangeDb.h"
#include "SQLiteCpp/SQLiteCpp.h"

class Sqlite : public IDbConnection,IDbCommit, IDbTransaction, IDbChangeDb{
public:
    ~Sqlite() override;
    Sqlite(std::string connectionString):connectionString(connectionString){};
    bool ChangeDb() override;
    bool Connect() override;
    bool Disconnect() override;
    void Commit() override;
    void Rollback() override;

    DatafoxTable Query(std::string &queryString) override;
    void Execute(std::string& executeString) override;
private:
    std::string connectionString;
    SQLite::Database*c = nullptr;
    SQLite::Transaction *work = nullptr;
};



#endif //SQLITE_H
