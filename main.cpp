#include <iostream>
#include "sha1.h"
#include "sha256.h"
#include "md5.h"
#include "hashtable.cpp"

using namespace std;
int main() {
    HashTable<string> *h;
    int choice;
    home:
    cout << "Hash function or Hash table?\n1. Hash function\n2. Hash table\n3. Exit\n";
    cin >> choice;
    cin.ignore();
    if(choice == 1){
        string str;
        cout << "Input ur string: ";
        getline(cin, str);
        hash_func:
        cout << "Choose ur hash algorithm:\n1. MD5\n2. SHA-1\n3. SHA-2\n4. Exit\n";
        cin >> choice;
        cin.ignore();
        if(choice == 1){
            cout << str << " hashed to: " << md5(str) << endl;
        }
        else if(choice == 2){
            cout << str << " hashed to: " << sha1(str) << endl;
        }
        else if(choice == 3){
            cout << str << " hashed to: " << sha256(str) << endl;
        }
        else if(choice == 4) goto home;
        else{
            cout << "Wrong choice\n";
            goto hash_func;
        }
    }
    else if (choice == 2){
        hash_table:
        cout << "Choose ur table size: ";
        int size;
        cin >> size;
        cin.ignore();
        cout << "Choose your hash function used for hash table:\n1. MD5\n2. SHA-1\n3. SHA-2\n4. Back\n";
        cin >> choice;
        cin.ignore();
        if(choice == 1){
            h = new HashTable<string>(size, &md5);
        }
        else if(choice == 2){
            h = new HashTable<string>(size, &sha1);
        }
        else if(choice == 3){
            h = new HashTable<string>(size, &sha256);
        }
        else if(choice == 4) goto home;
        else{
            cout << "Wrong choice\n";
            goto hash_table;
        }
        hash_table_choice:
        while(true) {
            cout << "Choose your operation on hash table:\n1. Insert\n2. Remove\n3. Find\n4. Print\n5. Back\n";
            cin >> choice;
            cin.ignore();
            string str;
            switch (choice) {
                case 1:
                    cout << "Insert your value(string): ";
                    getline(cin, str);
                    h->insert(str);
                    break;
                case 2:
                    cout << "Remove your value: ";
                    getline(cin, str);
                    h->remove(str);
                    break;
                case 3:
                    cout << "Find your value: ";
                    getline(cin, str);
                    cout << str << " was found on key: " << h->find(str) << endl;
                    break;
                case 4:
                    h->print();
                    break;
                case 5:
                    goto hash_table;
                default:
                    cout << "Wrong choice\n";
                    goto hash_table_choice;
            }
        }
    }
    else if(choice == 3) return 0;

}
