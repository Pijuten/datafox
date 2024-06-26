//
// Created by stani on 4/28/24.
//

#ifndef DATAFOX_POSTGRES_H
#define DATAFOX_POSTGRES_H
#include "../../Interfaces/IDbConnection.h"
#include "../../Interfaces/IDbCommit.h"
#include "../../Interfaces/IDbTransaction.h"
#include "../../Table/DatafoxTable.h"
#include "../../Model/ConnectionInfoModel.h"
#include <pqxx/pqxx>
#include <string>


class Postgres : public IDbConnection, public IDbCommit, public IDbTransaction{
public:
    Postgres(ConnectionInfoModel &connectionInfoModel):connectionInfoModel(connectionInfoModel){};
    ~Postgres() override;
    bool Connect() override;
    bool Disconnect() override;
    void Commit() override;
    void Rollback() override;

    DatafoxTable Query(std::string &queryString) override;
    void Execute(std::string& executeString) override;
private:
    ConnectionInfoModel connectionInfoModel;
    pqxx::connection *c= nullptr;
    pqxx::work *work= nullptr;
};


#endif //DATAFOX_POSTGRES_H
