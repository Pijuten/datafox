//
// Created by stani on 31/05/2024.
//

#ifndef DBCONNECTIONMODEL_H
#define DBCONNECTIONMODEL_H

#include <string>


class DbConnectionModel {
public:
    [[nodiscard]] std::string get_host() const {
        return host;
    }

    void set_host(const std::string &host) {
        this->host = host;
    }

    [[nodiscard]] std::string get_user() const {
        return user;
    }

    void set_user(const std::string &user) {
        this->user = user;
    }

    [[nodiscard]] std::string get_password() const {
        return password;
    }

    void set_password(const std::string &password) {
        this->password = password;
    }

    [[nodiscard]] std::string get_db() const {
        return db;
    }

    void set_db(const std::string &db) {
        this->db = db;
    }

    [[nodiscard]] int get_port() const {
        return port;
    }

    void set_port(const int port) {
        this->port = port;
    }

    [[nodiscard]] std::string get_unix_socket() const {
        return unix_socket;
    }

    void set_unix_socket(const std::string &unix_socket) {
        this->unix_socket = unix_socket;
    }
    void parseJDBCUrl(const std::string& url);
private:
    std::string host;
    std::string user;
    std::string password;
    std::string db;
    int port=0;
    std::string unix_socket;
};


#endif //DBCONNECTIONMODEL_H
