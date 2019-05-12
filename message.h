#ifndef MESSAGE_H
#define MESSAGE_H
#include<string>
using namespace std;
class Msg {
public:
    static void showWelcomeMsg();
    static void showLoginMsg();
    static void showLoginErrMsg();
    static void showLogoutMsg();
    static void showTitle(const string& user);
    static void showSaveCompleteMsg();
    static void showHelpMsg();
};
#endif