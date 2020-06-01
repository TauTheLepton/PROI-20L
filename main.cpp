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

    Book f(1,"d","d","d",4,2,"dsad", false);
    Issue* d = &f;
    cout<<lib->is_unique_id(2137)<<endl;
    cout<<lib->is_unique_id(66622)<<endl;
    cout<<lib->is_unique_id(6662)<<endl;
    cout<<lib->is_unique_id(5)<<endl;
    lib->save_to_file();

    return 0;
}
