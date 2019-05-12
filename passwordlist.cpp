#include "passwordlist.h"
#include<iostream>
#include<cstdio>
#include<fstream>
#include"db.h"
// #include<fstream>
using namespace std;
PasswordList::PasswordList()
{

}

void PasswordList::addItem(Passworditem& it)
{
    it.id = recordList.size();
    recordList.push_back(it);
}
void PasswordList::display(bool ismask)
{
    showTableHead();
    showTableContent(ismask);
}

void PasswordList::showTableHead()
{
 
    cout << "+-------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "| ID |           addr          |         username         |         password         |         remark         |" << endl;
    cout << "+----+-------------------------+--------------------------+--------------------------+------------------------+" << endl;
}

void PasswordList::showTableContent(bool ismask)
{
    for (vector<Passworditem>::size_type i = 0; i < recordList.size(); i++) {
        recordList[i].display(ismask);
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
        Passworditem it(size() + 1, output);
        recordList.push_back(it);
        output.clear();
        // size += 1;
    }
    myfile.close();
}
void PasswordList::writeToFile(const string& filename)
{
    ofstream file(filename, ios::out); 
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

const vector<Passworditem>& PasswordList::getRecordList() const
{
    return recordList;
}

vector<Passworditem>& PasswordList::getRecordList() 
{
    return recordList;
}

vector<PasswordList>::size_type PasswordList::size()
{
    return recordList.size();
}

Passworditem& PasswordList::operator[](int i) 
{
    return recordList[i];
}