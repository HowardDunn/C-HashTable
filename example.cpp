#include <iostream>
#include "HashTable.h"

int main() {

    HashTable<std::string,int> myHash;

    myHash.insert("Damien",20);

    myHash["Damien"] = 21;;
    myHash["Pablo"] = 20;
    myHash["Bob"] = 23;;
    myHash["Kee"] = 24;

    std::cout << std::boolalpha;
    std:: cout << "Damien's age: " << myHash["Damien"] << "\n";
    std:: cout << "Pablo's age: " << myHash["Pablo"] << "\n";
    std:: cout << "Bob's age: " << myHash["Bob"] << "\n";
    std:: cout << "Kee's age: " << myHash["Kee"] << "\n";
    std:: cout << "Is the name Rovman in datastructure?  " << myHash.contains("Rovman") << "\n";
    std:: cout << "Is the name Bob in datastructure?  " << myHash.contains("Bob") << "\n";
    std:: cout << "Hash Table Size: " << myHash.size() << "\n";
    std:: cout << "Hash Table Capacity: " << myHash.capacity() << "\n";

    std:: cout << "\nReserving space.....\n";
    myHash.reserve(1000);

    std:: cout << "Pablo's age: " << myHash["Pablo"] << "\n";
    std:: cout << "Bob's age: " << myHash["Bob"] << "\n";
    std:: cout << "Kee's age: " << myHash["Kee"] << "\n";
    std:: cout << "Hash Table Capacity: " << myHash.capacity() << "\n";

    return 0;
}