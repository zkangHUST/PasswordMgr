#ifndef PASSWORD_H
#define PASSWORD_H
#include<string>
#include<vector>
#include<fstream>
using namespace std;
class Passworditem {
public:
    Passworditem(int num, vector<string>& src);
    Passworditem();
    void readFromInput(int num);
    void display();
    void writeToFile(ofstream& file);
// private:
    int    id;
    string addr;
    string username;
    string password;
    string remark;
};
#endif