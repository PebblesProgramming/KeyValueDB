#include <iostream>
#include <map>
#include <sstream>
#include <string>

int main() {
    std::map<std::string, std::string> store;
    std::string input;

    std::cout << "Simple Key-Value Store CLI\n";
    std::cout << "Commands: put <key> <value>, get <key>, delete <key>, exit\n";

    while (true) {
        std::cout << "> ";
        std::getline(std::cin, input);
        std::istringstream iss(input);
        std::string command;
        iss >> command;

        if (command == "put") {
            std::string key, value;
            iss >> key >> value;
            if (!key.empty() && !value.empty()) {
                store[key] = value;
                std::cout << "Stored [" << key << "] = " << value << "\n";
            }
            else {
                std::cout << "Usage: put <key> <value>\n";
            }
        }
        else if (command == "get") {
            std::string key;
            iss >> key;
            if (!key.empty()) {
                if (store.find(key) != store.end()) {
                    std::cout << "Value: " << store[key] << "\n";
                }
                else {
                    std::cout << "Key not found\n";
                }
            }
            else {
                std::cout << "Usage: get <key>\n";
            }
        }
        else if (command == "delete") {
            std::string key;
            iss >> key;
            if (!key.empty()) {
                if (store.erase(key)) {
                    std::cout << "Deleted key: " << key << "\n";
                }
                else {
                    std::cout << "Key not found\n";
                }
            }
            else {
                std::cout << "Usage: delete <key>\n";
            }
        }
        else if (command == "exit") {
            break;
        }
        else {
            std::cout << "Invalid command. Please use put, get, delete, or exit.\n";
        }
    }

    return 0;
}
