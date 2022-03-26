#include <iostream>
#include "sha1.h"
#include "sha256.h"
#include "md5.h"
#include "hashtable.cpp"

using namespace std;
int main() {
    HashTable<string> h(1000, &sha256); // choose whatever hash functions you want
    h.insert("apple");
    h.insert("pen");
    h.print();
    cout << h.find("apple")<<endl;
    cout << h.find("cc")<<endl;
    h.remove("apple");
    h.print();
    return 0;
}
