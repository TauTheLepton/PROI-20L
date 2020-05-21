#include <iostream>
#include "application.h"

using namespace std;

int main()
{
    ///Tutaj bedzie jakis event loop

    ///to tak tylko do testowania
    Library lib;
    lib.read_from_file();
    for(int i=0; i<4; i++)
    {
        Issue* temp;
        temp=lib.issues[i];
        // *temp.showProperties();
        // Issue temp2=*temp;
        // temp2.showProperties();
    }
    return 0;
}
