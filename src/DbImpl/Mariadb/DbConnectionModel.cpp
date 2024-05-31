//
// Created by stani on 31/05/2024.
//

#include "DbConnectionModel.h"

#include <regex>


void DbConnectionModel::parseJDBCUrl(const std::string& url) {
    std::regex urlRegex(R"(jdbc:mariadb://([^:/]+)(?::(\d+))?(/[^?]*)?(\?.*)?)");
    std::smatch urlMatch;

    if (std::regex_match(url, urlMatch, urlRegex)) {
        set_host(urlMatch[1].str());

        if (urlMatch[2].matched) {
            set_port(stoi(urlMatch[2].str()));
        }

        if (urlMatch[3].matched) {
            set_db(urlMatch[3].str().substr(1));  // Remove leading '/'
        }

        if (urlMatch[4].matched) {
            std::string query = urlMatch[4].str().substr(1); // Remove leading '?'
            std::regex queryRegex(R"(([^=&]+)=([^&]*)&?)");
            std::smatch queryMatch;
            std::string::const_iterator searchStart(query.cbegin());

            while (std::regex_search(searchStart, query.cend(), queryMatch, queryRegex)) {
                std::string key = queryMatch[1].str();
                std::string value = queryMatch[2].str();

                if (key == "user") {
                    set_user(value);
                } else if (key == "password") {
                    set_password(value);
                } else if (key == "localSocket") {
                    set_unix_socket(value);
                }

                searchStart = queryMatch.suffix().first;
            }
        }
    } else {
        throw std::invalid_argument("Invalid JDBC URL format");
    }
}
