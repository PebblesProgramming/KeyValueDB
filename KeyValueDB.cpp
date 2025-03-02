#include <iostream>
#include <map>
#include <string>

int main()
{
    std::map<std::string, int> learning;
    std::string key;
    int value;
    
    while(true)
    {
        std::cout << "\nEnter command (write, see all, exit): ";
        
        // // Makes sure the newline (When pressed ENTER \n enters the buffer) gets ignored,
        // //otherwise that newline will be seen as command to be read when in fact you just pressed ENTER
        // std::cin.ignore(); 
        std::getline(std::cin, key); // this ensures we get the whole input including spaces for stuff like 'see all' for example

        if(key == "exit")
        {
            break;
        }

        
        if(key == "write")
        {
            std::string tempKey; // need this otherwise we will overwrite key and we dont want that
            std::cout << "Enter String and Number:  ";
            std::cin >> tempKey;
            
            if(!(std::cin >> value))
            {
                std::cout << "Invalid input! Please enter a name followed by a number\n";
                std::cin.clear();
                std::cin.ignore(100, '\n');
                continue;
            }
        
            learning[tempKey] = value; // store the key value pair in the map
            std::cout << "Entry added: " << tempKey << value;
            continue; // this needs to be here otherwise you dont return to the key cin
        }

        if(key == "see all")
        {
            if(learning.empty())
            {
                std::cout << "No data stored \n";
            } else
            {
                std::cout << "All stored values: \n";
                for(auto& index: learning)
                {
                    std::cout << index.first << " : " << index.second << "\n";
                }
            }
            continue; // same here as for the write
        }

        
    std::cout << "Invalid Command! Please enter 'write', 'see all' or 'exit' \n";
    }

    return 0;
}
