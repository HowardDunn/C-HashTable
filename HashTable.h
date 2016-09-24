#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <functional>
#include <cassert>
#include <iostream>
template<typename K, typename T>
class HashTable {

public:

    HashTable();

    ~HashTable();

    void insert(K key, T value);

    bool contains(K key);

    T get(K key);

    T& operator[](K key);
    T& operator[](K key) const;

    unsigned size() const;
    unsigned capacity() const;

private:

    T *data;
    bool *isset;
    K *keys;
    unsigned _size;
    unsigned _capacity;

    void rehash();

    bool collides(K key);

    void insert(K key);


};


template<typename K, typename T>
HashTable<K, T>::HashTable() {

    _capacity = 191;
    data = new T[_capacity];
    isset = new bool[_capacity];
    keys = new K[_capacity];

    for(unsigned i=0; i < _capacity; ++i){

        isset[i] = false;
    }
    _size = 0;
}


template<typename K, typename T>
unsigned HashTable<K, T>::size() const{

    return _size;

}

template<typename K, typename T>
unsigned HashTable<K, T>::capacity() const{

    return _capacity;

}

template<typename K, typename T>
bool HashTable<K, T>::contains(K key) {

    return keys[std::hash<K>{}(key) % _capacity] == key;

}

template<typename K, typename T>
bool HashTable<K, T>::collides(K key) {

    if (contains(key)) {

        return false;
    }

    return isset[std::hash<K>{}(key) % _capacity];
}

template<typename K, typename T>
void HashTable<K, T>::insert(K key, T value) {

    if(!contains(key))
        ++_size;

    if (_size >= _capacity / 2) {

        rehash();
    }

    while (collides(key)) {
        
        // Key collision
        rehash();
    }

    data[std::hash<K>{}(key) % _capacity] = value;
    keys[std::hash<K>{}(key) % _capacity] = key;
    isset[std::hash<K>{}(key) % _capacity] = true;
}

template<typename K, typename T>
void HashTable<K, T>::insert(K key) {

    if(!contains(key))
        ++_size;

    if (_size >= _capacity / 2) {

        rehash();
    }

    while (collides(key)) {

        std::cout << "Collision\n";
        // Key collision
        rehash();
    }


    keys[std::hash<K>{}(key) % _capacity] = key;
    isset[std::hash<K>{}(key) % _capacity] = true;
}

template<typename K, typename T>
T& HashTable<K, T>::operator[](K key) const {

    assert(contains(key));
    return data[std::hash<K>{}(key) % _capacity];
}

template<typename K, typename T>
T& HashTable<K, T>::operator[](K key){

    T value;
    insert(key);
    return data[std::hash<K>{}(key) % _capacity];
}

template <class K, class T>
T HashTable<K,T>::get(K key){

    assert(contains(key));

    return data[std::hash<K>{}(key) % _capacity];
}


template<typename K, typename T>
void HashTable<K, T>::rehash() {


    T *temp_data = data;
    bool *temp_isset = isset;
    K *temp_keys = keys;

    data = new T[_capacity * 3];
    isset = new bool[_capacity * 3];
    keys = new K[_capacity * 3];

    for (unsigned i = 0; i < _capacity; ++i) {

        data[i] = temp_data[i];
        isset[i] = temp_isset[i];
        keys[i] = temp_keys[i];
    }

    for(unsigned i = _capacity; i < (_capacity*2 + 1); ++i){

        isset[i] = false;
    }

    _capacity *= 2;
    _capacity += 1;

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