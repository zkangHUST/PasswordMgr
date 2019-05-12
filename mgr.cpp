#include "mgr.h"
#include<string>
#include<iostream>
#include<cstdio>
#include "tools.h"
#include "user.h"
using namespace std;
Mgr::Mgr()
{
    loginSuccess = false;
}
void Mgr::init()
{
    msg.showWelcomeMsg();
    db.init();
    user.getLoginMsgFromDB();
    login();
    record.readFromDB();
}

void Mgr::start()
{
    if (!loginSuccess) {
        return ;
    }
    while (loginSuccess) {
        msg.showTitle(user.getName());
        string cmd = getCmd();
        handleCmd(cmd);
    }
}
string Mgr::getCmd()
{
    string cmd;
    getline(cin, cmd);
    cmd = trim(cmd);
    return cmd;
}


void Mgr::handleCmd(string cmd)
{
    if (cmd == "quit" || cmd == "exit") {
        loginSuccess = false;
    } else if (cmd == "ls") {
        lsAll();
    } else if (cmd == "add") {
        add();
    } else if (cmd == "load") {
        load();
    } else if (cmd == "toggle mask") {
        ismask = ismask ? false:true;
    } else if (cmd == "help" || cmd == "h") {
        help();
    }
}

void Mgr::exit()
{
    msg.showLogoutMsg();
}

void Mgr::lsAll()
{
    record.display(ismask);
}

void Mgr::add()
{
    Passworditem it;
    it.readFromInput();
    record.addItem(it);
    it.writeToDB(); 
}

void Mgr::login()
{
    cout << "Login:";
    string userName;
    
    getline(cin, userName);
    string p =getpass("Password:", true);

    if (p == defaultPassword) {
        msg.showLoginMsg();
        loginSuccess = true;
    } else {
        msg.showLoginErrMsg();
        loginSuccess = false;
    }
}

void Mgr::load()
{
    PasswordList tmp;
    tmp.readFromFile();
    tmp.writeToDB();
    cout << "load complete!" << endl;
    vector<Passworditem> it = tmp.getRecordList();
    for (vector<Passworditem>::size_type i = 0; i < it.size(); i++) {
        record.addItem(it[i]);
    }
}

void Mgr::help()
{
    msg.showHelpMsg();
}