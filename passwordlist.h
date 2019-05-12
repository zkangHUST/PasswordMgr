#ifndef PASSWORDLIST_H
#define PASSWORDLIST_H
#include<vector>
#include"passworditem.h"
using namespace std;
class PasswordList {
public:
    PasswordList();
    void add();
    void addItem(Passworditem& it);
    void display();
    void showTableHead();
    void showTableContent();
    void readFromFile();
    void writeToFile();
    void writeToDB();
    void readFromDB();
    static void stringSplit(string& src, vector<string>& output, char c);
    vector<Passworditem>& getRecordList();
private:
    vector<Passworditem>  recordList;
    int size;
};
#endif