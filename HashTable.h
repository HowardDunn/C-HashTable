#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <functional>

template <typename K, typename T>
class HashTable{

public:

    HashTable();
    ~HashTable();

    void insert(K key, T value);
    bool contains(K key);

    T get(K key);

    T operator[](K key) const;

private:

    T* data;
    bool* isset;
    K* keys;
    unsigned size;
    unsigned capacity;

    void rehash();

    bool collides(K key);




};

#endif