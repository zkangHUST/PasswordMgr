#include "mgr.h"
#include<string>
#include<iostream>
#include<cstdio>
#include "tools.h"
using namespace std;
Mgr::Mgr()
{
    loginSuccess = false;
}
void Mgr::init()
{
    msg.showWelcomeMsg();
    login();
    record.readFromFile();
}

void Mgr::start()
{
    if (!loginSuccess) {
        return ;
    }
    while (loginSuccess) {
        msg.showTitle(user);
        string cmd = getCmd();
        handleCmd(cmd);
    }
}
string Mgr::getCmd()
{
    string cmd;
    cin >> cmd;
    getchar();
    return cmd;
}


void Mgr::handleCmd(string cmd)
{
    if (cmd == "quit") {
        loginSuccess = false;
        save();
    } else if (cmd == "ls") {
        ls();
    } else if (cmd == "add") {
        add();
    } else if (cmd == "save") {
        save();

    }
}

void Mgr::exit()
{
    msg.showLogoutMsg();
}

void Mgr::ls()
{
    record.display();
}

void Mgr::add()
{
    record.add();
}

void Mgr::save()
{
    record.writeToFile();
    msg.showSaveCompleteMsg();
}

void Mgr::login()
{
    cout << "Login:";
    getline(cin, user);

    string p =getpass("Password:", true);
    // cout << "Password:";
    // string p;
    // getline(cin, p);
    if (p == defaultPassword) {
        msg.showLoginMsg();
        loginSuccess = true;
    } else {
        msg.showLoginErrMsg();
        loginSuccess = false;
    }
}