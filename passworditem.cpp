#include "passworditem.h"
#include <iostream>
#include <cstdio>
#include "db.h"
using namespace std;
void Passworditem::readFromInput()
{
    cin >> addr;
    cin >> username;
    cin >> password;
    cin >> remark;
}

void Passworditem::display(bool mask)
{
    // cout << "+---------------------------------------------------------------------+" << endl;
    // cout << "| ID |      addr     |    username    |    password    |    remark    |" << endl;
    printf("|%04d", id);
    printf("|%-25s", addr.c_str());
    printf("|%-26s", username.c_str());
    if (mask) {
        printf("|%-26s", "********");
    } else {
        printf("|%-26s", password.c_str());
    }
    printf("|%-24s", remark.c_str());
    printf("|");
    cout << endl << "+----+-------------------------+--------------------------+--------------------------+------------------------+" << endl;

    // cout << "| " << id << " |" << addr << "|" << username << "|" << password << "|" << remark << "|" << endl;
    // cout << "+---------------------------------------------------------------------+" << endl;
}
Passworditem::Passworditem(int num, vector<string>& src)
{
    id = num;
    addr = src[0];
    username = src[1];
    password = src[2];
    if (src.size() >= 4) {
        remark = src[3];
    } else {
        remark = "null";
    }
}
Passworditem::Passworditem()
{
    addr = "www.google.com";
    username = "vincent.zheng";
    password = "space";
    remark = "null";
}

void Passworditem::writeToFile(ofstream& file)
{
    file << addr << "    " << username << "    " << password << "    " << remark << endl;
}

void Passworditem::writeToDB()
{
    DB load;
    load.attachDB();
    load.insertRecord(*this);
    load.closeDB();
}