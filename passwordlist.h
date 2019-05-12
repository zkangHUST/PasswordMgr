#ifndef PASSWORDLIST_H
#define PASSWORDLIST_H
#include<vector>
#include "passworditem.h"
using namespace std;
class PasswordList {
public:
    PasswordList();
    void addItem(Passworditem& it);
    void display(bool ismask = true);
    void showTableHead();
    void showTableContent(bool ismask = true);
    void readFromFile();
    void writeToFile(const string& filename);
    void writeToDB();
    void readFromDB();

    static void stringSplit(string& src, vector<string>& output, char c);
    const vector<Passworditem>& getRecordList() const;
    vector<Passworditem>& getRecordList() ;
    vector<PasswordList>::size_type size();
private:
    vector<Passworditem>  recordList;
};
#endif