#include <iostream>
#include "HashTable.h"
#include <string>

int main() {
    std::cout << "Hello, World!" << std::endl;

    //HashTable<> x;

    std::cout << std::hash<char>{}('A') << "\n";

    HashTable<std::string,int> myHash;

    myHash.insert("Damien",20);

    std:: cout << "Damien's age: " << myHash["Damien"] << "\n";



    return 0;
}