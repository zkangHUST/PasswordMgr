#include<cstdio>
#include"sqlite3.h"
#include<iostream>
using namespace std;
int main()
{
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    rc = sqlite3_open("test.db", &db);
    if (rc) {
        cout << "cannot open db" << endl;
    }
    return 0;
}