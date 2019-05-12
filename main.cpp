#include "mgr.h"
#include "db.h"
#include<iostream>
using namespace std;
int main()
{
    Mgr mgr;
    mgr.init();
    mgr.start();
    mgr.exit();
    // DB test;
    // PasswordList it;
    // test.attachDB();
    // test.createTable();
    // test.readToList(it);
    // it.display();
    // cout << "---------" << endl;
    // Passworditem it;
    // test.insertRecord(it);
    // string test = "    hello wordl    here is a test string    ";
    // vector<string> out;
    // PasswordList::stringSplit(test, out, ' ');
    // for (int i = 0; i < out.size(); i++) {
    //     cout << out[i] << "-";
    // }
    return 0;
}