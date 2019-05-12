#ifndef MESSAGE_H
#define MESSAGE_H
#include<string>
using namespace std;
class Msg {
public:
    void showWelcomeMsg();
    void showLoginMsg();
    void showLoginErrMsg();
    void showLogoutMsg();
    void showTitle(const string& user) const;
    void showSaveCompleteMsg();
    void showHelpMsg();
private:

};
#endif