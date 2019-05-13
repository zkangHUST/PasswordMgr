#include "message.h"
#include<iostream>
using namespace std;
void Msg::showWelcomeMsg()
{
    cout << "welcome to the Password Manage System!\n";
}
void Msg::showLoginMsg()
{
    cout << "login correct!" << endl;
    cout << "if you have any problem, type \"help\" or \"h\" for help!" << endl;
}

void Msg::showTitle(const string& user) 
{
    cout << "[" << user << "]$ ";
}
void Msg::showLoginErrMsg()
{
    cout << "login incorrect!" << endl;
}

void Msg::showLogoutMsg()
{
    cout << "Bye Bye!" << endl;
}
void Msg::showSaveCompleteMsg()
{
    cout <<"save complete!" << endl;
}

void Msg::showHelpMsg()
{
    cout << "usage:[help] [h] [ls] [ls <id list>] [add] [quit]" << endl;
    cout << "      [exit] [load] [toogle mask] [reset] [saveas <filename>]" << endl << endl;
    cout << "  help, h        show help messages." << endl;
    cout << "  add            add a password record." << endl;
    cout << "  load           load records form a file." << endl;
    cout << "  toogle mask    toogle show password as \"******\" or normal." << endl;
    cout << "  exit, quit, q  exit the program." << endl;
    cout << "  reset          reset user name and password." << endl;
    cout << "  saveas xxx     save records to file xxx." << endl;
    cout << "  ls             list all records." << endl;
    cout << "  ls id1 id2     list id1, id2 records." << endl;
    cout << endl;
}