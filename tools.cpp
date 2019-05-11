#include "tools.h"
#include <conio.h>

// mask password 
string getpass(const char *prompt, bool show_asterisk=true)
{
    const char BACKSPACE=8;
    const char RETURN=13;

    string password;
    unsigned char ch=0;

    cout << prompt;

    while ((ch = getch()) != RETURN) {
        if (ch == BACKSPACE) {
            if (password.length() != 0) {
                if(show_asterisk) {
                    cout <<"\b \b";
                }
                password.resize(password.length()-1);
            }
        } else if (ch == 0 || ch == 224) { // handle escape sequences
            getch(); // ignore non printable chars
            continue;
        } else {
            password += ch;
            if (show_asterisk) {
                cout <<'*';
            }
        }
    }
    cout <<endl;
    return password;
}