//
// Created by stani on 07/05/2024.
//

#ifndef DATAFOXTABLE_H
#define DATAFOXTABLE_H
#include <string>
#include <vector>


class DatafoxTable {
public:
    void AddRow(std::vector<std::string> row);
    [[nodiscard]] std::vector<std::vector<std::string>> GetTable() const {
        return table;
    }
    void printTable();
private:
    std::vector<std::vector<std::string>> table;
};



#endif //DATAFOXTABLE_H
