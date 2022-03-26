//
// Created by hungc on 3/26/2022.
//
#define c1 3
#define c2 5
#include <iostream>
#include <string>
#include <sstream>
using namespace std;



template <typename T>
class HashTable{
private:
    T* table;
    int size;
    string (*h_func)(string);

public:
    HashTable():table(nullptr), size(0), h_func(nullptr){};
    HashTable(int N, string (*hfunc)(string)): table(new T[N]), size(N), h_func(hfunc){};

    ~HashTable(){
        delete [] table;
        this->size = 0;
        this->h_func = nullptr;
    }

    void insert(T value){
        string h_Val;
//        try {h_Val = to_string(value);}
//        catch (const char* msg){
//            cout << msg << endl;
//        }
        h_Val = this->h_func(value);
        h_Val = h_Val.substr(h_Val.length()-16); // took last 16 bytes cause C++ can't handle more...
        unsigned long long int hkey;
        std::stringstream ss;
        ss << std::hex << h_Val;
        ss >> hkey;
        hkey = hkey % size;
        int i = 0;
        int hp = int(hkey);
        while(table[hp] != "" && i < this->size){
            if (table[hp] == value) {
                cout << "Duplicate!\n";
                return;
            }
            hp = (hkey + c1 * i + c2 * i * i) % this->size; // Quadratic probing
            i++;
        }
        if (i == this->size) {
            cout<<"Cannot insert value\n";
            return;
        }
        table[hp] = value;
    }

    void remove(T value){
        string h_Val;
        h_Val = this->h_func(value);
        h_Val = h_Val.substr(h_Val.length()-16);// took last 16 bytes cause C++ can't handle more...
        unsigned long long int hkey;
        std::stringstream ss;
        ss << std::hex << h_Val;
        ss >> hkey;
        hkey = hkey % size;
        int i = 0;
        int hp = int(hkey);
        while(table[hp] != "" && i < this->size){
            if (table[hp] == value) {
                table[hp] = "";
                return;
            }
            hp = (hkey + c1 * i + c2 * i * i) % this->size; // Quadratic probing
            i++;
        }
        if (i == this->size || table[hp] == "") cout << "Value not found\n";
    }

    int find(T value){
        string h_Val;
        h_Val = this->h_func(value);
        h_Val = h_Val.substr(h_Val.length()-16);// took last 16 bytes cause C++ can't handle more...
        unsigned long long int hkey;
        std::stringstream ss;
        ss << std::hex << h_Val;
        ss >> hkey;
        hkey = hkey % size;
        int i = 0;
        int hp = int(hkey);
        while(table[hp] != "" && i < this->size){
            if (table[hp] == value) {
                return hp;
            }
            hp = (hkey + c1 * i + c2 * i * i) % this->size; // Quadratic probing
            i++;
        }
        if (i == this->size || table[hp] == "") cout << "Value not found\n";
        return -1;
    }

    void print(){
        cout << "-----Hash Table------\n";
        for(int i = 0;i < this->size; i++){
            if(table[i] != "")
                cout << "Key:"<<i<<", Value:"<<table[i]<<endl;
        }
        cout << "---------END---------\n";
    }


};

