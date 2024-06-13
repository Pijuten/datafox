//
// Created by stani on 13/06/2024.
//

#ifndef DFOX_CONNECTIONINFOMODEL_H
#define DFOX_CONNECTIONINFOMODEL_H
#include <string>

class ConnectionInfoModel {
private:
    std::string host;
    int port;
    std::string db;
    std::string user;
    std::string password;
    std::string unix_socket;
    std::string filePath;
public:
    ConnectionInfoModel();
    const std::string &getHost() const;
    void setHost(const std::string &host);
    int getPort() const;
    void setPort(int port);
    const std::string &getDb() const;
    void setDb(const std::string &db);
    const std::string &getUser() const;
    void setUser(const std::string &user);
    const std::string &getPassword() const;
    void setPassword(const std::string &password);
    const std::string &getUnixSocket() const;
    void setUnixSocket(const std::string &unixSocket);
    const std::string &getFilePath() const;
    void setFilePath(const std::string &filePath);
};


#endif //DFOX_CONNECTIONINFOMODEL_H
