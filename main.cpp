#include <iostream>
#include "application.h"
#include <typeinfo>

using namespace std;

int main()
{
    ///Tutaj bedzie jakis event loop

    ///to tak tylko do testowania
    Library* lib = Library::getInstance();

    lib->read_from_file();
    lib->showAssets();

    vector<Issue*> tak = lib->search_by_discipline("Chemistry");

    Book f(1,"d","d","d",4,2,"dsad");
    Issue* d = &f;

    lib->save_to_file();

    return 0;
}
