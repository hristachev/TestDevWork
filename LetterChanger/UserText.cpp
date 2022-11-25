#include "UserText.h"
#include <algorithm>
#include <iostream>

UserText::UserText()
{
    cout << "Enter your message!\nEnter [Q] to exit: ";
    getline(cin, str);
}

UserText operator==(const string& str, const string& compare)
{
    return UserText(str == compare);
}

void UserText::StringManip()
{
    transform(str.begin(), str.end(), str.begin(), [](unsigned char c){ return tolower(c); });
    
    for (int i = 0; i < str.length(); i++)
    {
        char buf = str[i];
        int counter = count(begin(str), end(str), str[i]);
        
        if (counter > 1)
        {
            replace(str.begin(), str.end(), buf, ')');
        }
        else
        {
            replace(str.begin(), str.end(), buf, '(');
        }
    }
}
