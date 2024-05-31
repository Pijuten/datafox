//
// Created by stani on 07/05/2024.
//

#include "DatafoxTable.h"

#include <iostream>

void DatafoxTable::AddRow(std::vector<std::string> row) {
    table.push_back(row);
}

void DatafoxTable::printTable() {
    for (const auto& i:table) {
        for (const auto& j:i) {
            std::cout<<j<<"\n";
        }
        std::cout<<std::endl;
    }
}
