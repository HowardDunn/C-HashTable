#include <iostream>
#include "HashTable.h"
#include <string>

int main() {
    std::cout << "Hello, World!" << std::endl;

    //HashTable<> x;



    HashTable<std::string,int> myHash;

    myHash.insert("Damien",20);

    myHash["Damien"] = 21;
    std::cout << std::hash<std::string>{}("Damien")%11 << "\n";
    std::cout << std::hash<std::string>{}("Pablo2")%11 << "\n";
    myHash["Pablo"] = 20;

    std:: cout << "Damien's age: " << myHash["Damien"] << "\n";
    std:: cout << "Pablo's age: " << myHash["Pablo"] << "\n";


    return 0;
}