#ifndef PASSWORDLIST_H
#define PASSWORDLIST_H
#include<vector>
#include"passworditem.h"
using namespace std;
class PasswordList {
public:
    PasswordList();
    void add();
    void display();
    void showTableHead();
    void showTableContent();
    void readFromFile();
    void writeToFile();
    static void stringSplit(string& src, vector<string>& output, char c);
private:
    vector<Passworditem>  recordList;
    int size;
};
#endif