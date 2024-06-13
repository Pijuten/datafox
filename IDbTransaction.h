//
// Created by stani on 4/29/24.
//

#ifndef DATAFOX_IDBTRANSACTION_H
#define DATAFOX_IDBTRANSACTION_H

#include <string>

#include "DatafoxTable.h"

class IDbTransaction{
public:
    virtual DatafoxTable Query(std::string &queryString) = 0;
    virtual void Execute(std::string& executeString) = 0;
    virtual ~IDbTransaction()=default;
};
#endif //DATAFOX_IDBTRANSACTION_H
