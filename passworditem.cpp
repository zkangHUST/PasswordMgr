#include "passworditem.h"
#include <iostream>
#include<cstdio>
using namespace std;
void Passworditem::readFromInput(int num)
{
    id = num;
    cin >> addr;
    cin >> username;
    cin >> password;
    cin >> remark;
}

void Passworditem::display()
{
    // cout << "+---------------------------------------------------------------------+" << endl;
    // cout << "| ID |      addr     |    username    |    password    |    remark    |" << endl;
    printf("|%04d", id);
    printf("|%-25s", addr.c_str());
    printf("|%-26s", username.c_str());
    printf("|%-26s", password.c_str());
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

}

void Passworditem::writeToFile(ofstream& file)
{
    file << addr << "    " << username << "    " << password << "    " << remark << endl;
}
    