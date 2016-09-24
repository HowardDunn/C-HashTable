#include <iostream>
#include "HashTable.h"
#include <string>

int main() {
    std::cout << "Hello, World!" << std::endl;

    //HashTable<> x;



    HashTable<std::string,int> myHash;

    myHash.insert("Damien",20);

    myHash["Damien"] = 21;;
    myHash["Pablo"] = 20;
    myHash["Bob"] = 23;;
    myHash["Kee"] = 24;

    std:: cout << "Damien's age: " << myHash["Damien"] << "\n";
    std:: cout << "Pablo's age: " << myHash["Pablo"] << "\n";
    std:: cout << "Bob's age: " << myHash["Bob"] << "\n";
    std:: cout << "Kee's age: " << myHash["Kee"] << "\n";
    std:: cout << "Hash Table Size: " << myHash.size() << "\n";
    std:: cout << "Hash Table Capacity: " << myHash.capacity() << "\n";


    return 0;
}