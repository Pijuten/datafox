//
// Created by stani on 4/28/24.
//

#ifndef DATAFOX_IDBCONNECTION_H
#define DATAFOX_IDBCONNECTION_H
#include <string>

class IDbConnection {
public:
    virtual bool Connect() = 0;
    virtual bool Disconnect() = 0;
    virtual ~IDbConnection()=default;
};


#endif //DATAFOX_IDBCONNECTION_H
