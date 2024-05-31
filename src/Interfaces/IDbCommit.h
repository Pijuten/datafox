//
// Created by stani on 4/28/24.
//

#ifndef DATAFOX_IDBCOMMIT_H
#define DATAFOX_IDBCOMMIT_H

class IDbCommit{
public:
    virtual void Commit() = 0;
    virtual void Rollback() = 0;
    virtual ~IDbCommit()=default;
};

#endif //DATAFOX_IDBCOMMIT_H
