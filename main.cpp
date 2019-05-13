#include "mgr.h"
#include "db.h"
#include<iostream>
using namespace std;
int main()
{
    Mgr mgr;
    mgr.init();
    mgr.start();
    mgr.exit();
    return 0;
}