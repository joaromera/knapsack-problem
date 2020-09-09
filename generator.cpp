#include <algorithm>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <time.h>
#include <tuple>
#include <utility>
#include <vector>

#define Item std::pair<unsigned, unsigned>
#define Items std::vector<Item>

static Items generateItemsList(const unsigned num_items, const unsigned max_weight, const unsigned profit)
{
    Items items;
    items.reserve(num_items);
    for (unsigned i = 0; i < num_items; ++i) {
        items.emplace_back(
            (static_cast<unsigned>(rand()) % max_weight) + 1,
            (static_cast<unsigned>(rand()) % profit) + 1
        );
    }
    return items;
}

static void printVectorToFile(const unsigned num_items, const unsigned max_weight, const Items &items, std::ofstream &f)
{
    f << num_items << " " << max_weight << std::endl;
    for(unsigned i = 0; i < num_items; ++i)
    {
        f << items[i].first << " " << items[i].second << std::endl;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cerr << "Not enough parameters" << std::endl;
        return 1;
    }

    const unsigned num_items = static_cast<unsigned>(atoi(argv[1]));
    const unsigned max_weight = static_cast<unsigned>(atoi(argv[2]));
    const unsigned profit = static_cast<unsigned>(atoi(argv[3]));

    const Items items = generateItemsList(num_items, max_weight, profit);
    const std::string fileName = std::to_string(num_items) + "i_" + std::to_string(max_weight) + "w_" + std::to_string(profit) + "p.txt";
    std::ofstream file(fileName, std::fstream::out);
    printVectorToFile(num_items, max_weight, items, file);
    file.close();
    return 0;
}
