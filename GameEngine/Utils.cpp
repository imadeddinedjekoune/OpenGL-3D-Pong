#include "Utils.h"

std::string Utils::readFile(const std::string& fileName)
{

    
    std::string content;
    std::string line;
    std::ifstream file(fileName);
    if (file.is_open()) {
        while (std::getline(file, line)) {
            content += line + '\n';
        }
        file.close();
        return content;
    }
    else {
        std::cout << "Unable to open file";
        return "";
    }
    
}
