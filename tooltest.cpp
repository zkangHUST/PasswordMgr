#include "tools.h"
int main()
{
    string cmd;
    // cin >> cmd;
    getline(cin, cmd);
    cmd = trim(cmd);
    if (cmd == "toggle mask") {
        cout << "right" << endl;
    } else {
        cout << cmd << endl;
    }
    // cout << cmd << endl;
}