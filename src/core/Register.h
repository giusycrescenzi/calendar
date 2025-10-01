#pragma once

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class Register {
public:
    Register() = default;

    void loadFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Failed to open file: " << filename << std::endl;
            return;
        }

        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string name;
            int value;
            if (!(iss >> name >> value)) {
                std::cerr << "Failed to parse line: " << line << std::endl;
                continue;
            }

            data[name] = value;
        }
    }

    void saveToFile(const std::string& filename) const {
        std::ofstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Failed to open file: " << filename << std::endl;
            return;
        }

        for (const auto& [name, value] : data) {
            file << name << " " << value << std::endl;
        }
    }

    int getValue(const std::string& name) const {
        auto it = data.find(name);
        if (it == data.end()) {
            return 0;
        }

        return it->second;
    }

private:
    std::map<std::string, int> data;
};