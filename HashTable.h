#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <functional>

template<typename K, typename T>
class HashTable {

public:

    HashTable();

    ~HashTable();

    void insert(K key, T value);

    bool contains(K key);

    T get(K key);

    T operator[](K key) const;

private:

    T *data;
    bool *isset;
    K *keys;
    unsigned size;
    unsigned capacity;

    void rehash();

    bool collides(K key);


};


template<typename K, typename T>
HashTable<K, T>::HashTable() {

    capacity = 11;
    data = new T[capacity];
    isset = new bool[capacity];
    keys = new K[capacity];
    size = 0;
}

template<typename K, typename T>
bool HashTable<K, T>::contains(K key) {

    return keys[std::hash<K>{}(key) % capacity] == key;

}

template<typename K, typename T>
bool HashTable<K, T>::collides(K key) {

    if (contains(key)) {

        return false;
    }

    return isset[std::hash<K>{}(key) % capacity];
}

template<typename K, typename T>
void HashTable<K, T>::insert(K key, T value) {

    ++size;

    if (size >= capacity / 2) {

        rehash();
    }

    while (collides(key)) {

        // Key collision
        rehash();
    }

    data[std::hash<K>{}(key) % capacity] = value;
    keys[std::hash<K>{}(key) % capacity] = key;
    isset[std::hash<K>{}(key) % capacity] = true;
}

template<typename K, typename T>
T HashTable<K, T>::operator[](K key) const {

    return data[std::hash<K>{}(key) % capacity];
}

template<typename K, typename T>
void HashTable<K, T>::rehash() {


    T *temp_data = data;
    bool *temp_isset = isset;
    K *temp_keys = keys;

    data = new T[capacity * 3];
    isset = new bool[capacity * 3];
    keys = new K[capacity * 3];

    for (unsigned i = 0; i < capacity; ++i) {

        data[i] = temp_data[i];
        isset[i] = temp_isset[i];
        keys[i] = temp_keys[i];
    }

    capacity *= 3;

    delete[] temp_data;
    delete[] temp_isset;
    delete[] temp_keys;


}

template<typename K, typename T>
HashTable<K, T>::~HashTable() {

    delete[] data;
    delete[] isset;
    delete[] keys;
}

#endif