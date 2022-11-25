#include <iostream>
#include <conio.h>
#include "UserText.h"

int main(int argc, char* argv[])
{
    while (true)
    {
        auto* text = new UserText;
        
        if (text->GetStr() == "q" || text->GetStr() == "Q")
        {
            delete text;
            break; 
        }
        
        text->StringManip();
        cout << "Replace: " << text->GetStr() << endl;
    }
    
    return 0;
}
