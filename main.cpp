#include "mgr.h"
#include<iostream>
using namespace std;
int main()
{
    Mgr mgr;
    mgr.init();
    mgr.start();
    mgr.exit();
    // string test = "    hello wordl    here is a test string    ";
    // vector<string> out;
    // PasswordList::stringSplit(test, out, ' ');
    // for (int i = 0; i < out.size(); i++) {
    //     cout << out[i] << "-";
    // }
    return 0;
}