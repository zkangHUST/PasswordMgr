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
// private:
    int    id;
    string addr;
    string username;
    string password;
    string remark;
};
#endif