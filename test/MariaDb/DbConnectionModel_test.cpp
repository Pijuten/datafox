//
// Created by stani on 31/05/2024.

#include <gtest/gtest.h>
#include "../../src/DbImpl/Mariadb/DbConnectionModel.h"

TEST(DbConnectionModel, test1) {
    DbConnectionModel model;
    model.parseJDBCUrl("jdbc:mariadb://localhost:3306/test");
    EXPECT_EQ("localhost", model.get_host());
    EXPECT_EQ("3306", model.get_port());
    EXPECT_EQ("test", model.get_db());
}

TEST(DbConnectionModel, test2) {
    DbConnectionModel model;
    model.parseJDBCUrl("jdbc:mariadb://localhost:3306/test?user=test&password=test");
    EXPECT_EQ("localhost", model.get_host());
    EXPECT_EQ("3306", model.get_port());
    EXPECT_EQ("test", model.get_db());
    EXPECT_EQ("test", model.get_user());
    EXPECT_EQ("test", model.get_password());
}

TEST(DbConnectionModel, test3) {
    DbConnectionModel model;
    model.parseJDBCUrl("jdbc:mariadb://localhost:3306/test?localSocket=/tmp/mysql.sock");
    EXPECT_EQ("localhost", model.get_host());
    EXPECT_EQ("3306", model.get_port());
    EXPECT_EQ("test", model.get_db());
    EXPECT_EQ("/tmp/mysql.sock", model.get_unix_socket());
}
