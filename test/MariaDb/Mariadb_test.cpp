//
// Created by stani on 31/05/2024.
//
#include <gtest/gtest.h>
#include "../../src/DbImpl/Mariadb/Mariadb.h"

TEST(Mariadb, test1) {
}
TEST(Mariadb_test, test2) {
    ConnectionInfoModel connectionInfoModel;
    connectionInfoModel.setHost("localhost");
    connectionInfoModel.setPort(3306);
    connectionInfoModel.setUser("test");
    connectionInfoModel.setPassword("test");
    connectionInfoModel.setDb("test");
    connectionInfoModel.setUnixSocket("");
    Mariadb db(connectionInfoModel);
    EXPECT_TRUE(db.Connect());
}