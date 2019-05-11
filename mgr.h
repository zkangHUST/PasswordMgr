#ifndef MGR_H
#define MGR_H
#include "message.h"
#include "passwordlist.h"
class Mgr {
public:
    void init();
    void login();
    void start();
    Mgr();
    void exit();
private:
    void handleCmd(string cmd);
    string getCmd();
    void ls();
    void add();
    void save();
private:
    PasswordList    record;
    Msg             msg;
    bool            loginSuccess;
    const string    defaultPassword = "space";
    string          user;
};
#endif