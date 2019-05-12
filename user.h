#ifndef USER_H
#define USER_H
#include<string>
using namespace std;
class User {
public:
    User();
    void setName(const string& m);
    void setLoginPassword(const string& p);
    void getLoginMsgFromDB();
    string getName();
    string getLoginPassword();
    void print();
    void writeToDB();
private:
    
    // string getLoginPasswordFromDB();
private:
    string name;
    string loginPassword;
};
#endif