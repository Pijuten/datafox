//
// Created by stani on 13/06/2024.
//

#include "ConnectionInfoModel.h"

const std::string &ConnectionInfoModel::getHost() const {
    return host;
}

void ConnectionInfoModel::setHost(const std::string &host) {
    ConnectionInfoModel::host = host;
}

int ConnectionInfoModel::getPort() const {
    return port;
}

void ConnectionInfoModel::setPort(int port) {
    ConnectionInfoModel::port = port;
}

const std::string &ConnectionInfoModel::getDb() const {
    return db;
}

void ConnectionInfoModel::setDb(const std::string &db) {
    ConnectionInfoModel::db = db;
}

const std::string &ConnectionInfoModel::getUser() const {
    return user;
}

void ConnectionInfoModel::setUser(const std::string &user) {
    ConnectionInfoModel::user = user;
}

const std::string &ConnectionInfoModel::getPassword() const {
    return password;
}

void ConnectionInfoModel::setPassword(const std::string &password) {
    ConnectionInfoModel::password = password;
}

const std::string &ConnectionInfoModel::getUnixSocket() const {
    return unix_socket;
}

void ConnectionInfoModel::setUnixSocket(const std::string &unixSocket) {
    unix_socket = unixSocket;
}

const std::string &ConnectionInfoModel::getFilePath() const {
    return filePath;
}

void ConnectionInfoModel::setFilePath(const std::string &filePath) {
    ConnectionInfoModel::filePath = filePath;
}

ConnectionInfoModel::ConnectionInfoModel() {

}
