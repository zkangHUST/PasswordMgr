#include "passwordlist.h"
#include<iostream>
#include<cstdio>
#include<fstream>
#include"db.h"
// #include<fstream>
using namespace std;
PasswordList::PasswordList()
{
    size = 0;
}
void PasswordList::add()
{
    Passworditem it;
    it.readFromInput(size + 1);
    recordList.push_back(it);
    size += 1;
}
void PasswordList::addItem(Passworditem& it)
{
    recordList.push_back(it);
}
void PasswordList::display()
{
    showTableHead();
    showTableContent();
}

void PasswordList::showTableHead()
{
 
    cout << "+-------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "| ID |           addr          |         username         |         password         |         remark         |" << endl;
    cout << "+----+-------------------------+--------------------------+--------------------------+------------------------+" << endl;
}

void PasswordList::showTableContent()
{
    for (vector<Passworditem>::size_type i = 0; i < recordList.size(); i++) {
        recordList[i].display();
    }
}

void PasswordList::readFromFile()
{
    ifstream myfile("password.txt", ios::in); 
    if (!myfile.is_open()) {
        cout << "open file error!" << endl;
        return ;
    }
    string tmp;
    while (getline(myfile, tmp)) {
        vector<string> output;
        stringSplit(tmp, output, ' ');
        Passworditem it(size + 1, output);
        recordList.push_back(it);
        output.clear();
        size += 1;
    }
    myfile.close();
}
void PasswordList::writeToFile()
{
    ofstream file("password.txt", ios::out); 
    if (!file.is_open()) {
        cout << "open file error!" << endl;
        return ;
    }
    for(vector<string>::size_type i = 0; i < recordList.size(); i++) {
        recordList[i].writeToFile(file);
    }
    file.close();
}

void PasswordList::writeToDB()
{
    DB load;
    load.attachDB();
    for (vector<PasswordList>::size_type i = 0; i < recordList.size(); i++) {
        load.insertRecord(recordList[i]);
    }
    load.closeDB();
}

void PasswordList::readFromDB()
{
    DB load ;
    load.attachDB(); 
    load.readToList(*this);
    load.closeDB();
}
    

void PasswordList::stringSplit(string& src, vector<string>& output, char c)
{
    string::size_type pos1, pos2;
    pos1 = 0;
    pos2 = 0;
    while(pos2 < src.size()) {
        while (src[pos1] == c && pos1 < src.size()) {
            pos1++;
        }
        pos2 = pos1;
        while(src[pos2] != c && pos2 < src.size()) {
            pos2++;
        }
        if (pos1 < src.size() && pos2 <= src.size()) {
            output.push_back(src.substr(pos1, pos2 - pos1));
        } 
        pos1 = pos2;
    }
}