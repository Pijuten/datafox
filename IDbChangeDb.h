//
// Created by stani on 07/05/2024.
//

#ifndef IDBCHANGEDB_H
#define IDBCHANGEDB_H
class IDbChangeDb{
public:
    virtual bool ChangeDb() = 0;
    virtual ~IDbChangeDb()=default;
};

#endif //IDBCHANGEDB_H
