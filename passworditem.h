#ifndef PASSWORD_H
#define PASSWORD_H
#include<string>
#include<vector>
#include<fstream>
class DB;
using namespace std;
class Passworditem {
public:
    Passworditem(int num, vector<string>& src);
    Passworditem();
    void readFromInput();
    void display(bool mask = true);
    void writeToFile(ofstream& file);
    void writeToDB();

    // get and set 
    string getAddr() const;
    string getUsername() const;
    string getPassword() const;
    string getRemark() const;
    void setAddr(const string& address);
    void setUsername(const string& name);
    void setPassword(const string& pass);
    void setRemark(const string& mark);
    void setId(int num);

private:
    int    id;
    string addr;
    string username;
    string password;
    string remark;
};
#endif