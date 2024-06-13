//
// Created by stani on 10/06/2024.
//

#ifndef DFOX_DBFACTORY_H
#define DFOX_DBFACTORY_H


#include "Interfaces/IDbConnection.h"

class DbFactory {
    public:
    IDbConnection* createConnection(const std::string& jdbcUrl);
};


#endif //DFOX_DBFACTORY_H
