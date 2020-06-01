#include <iostream>
#include "application.h"
#include <typeinfo>

using namespace std;

int main()
{
    ///Tutaj bedzie jakis event loop

    ///to tak tylko do testowania
    Library* lib = Library::getInstance();

    try
    {
        lib->read_from_file();
    }
    catch(int x)
    {
        cout<<"Error: "<<x<<endl;
    }
    lib->showAssets();
    bool s = lib->delete_id(2137);
    cout<<s<<endl;
    s = lib->delete_id(1234);
    cout<<s<<endl;
    s = lib->delete_id(6969);
    cout<<s<<endl;
    s = lib->delete_id(666);
    cout<<s<<endl;
    s = lib->delete_id(1);
    cout<<s<<endl;
    s = lib->delete_id(2);
    cout<<s<<endl;
    s = lib->delete_id(3);
    cout<<s<<endl;
    lib->showAssets();

    vector<Issue*> tak = lib->search_by_discipline("Chemistry");

    Book f(1,"d","d","d",4,2,"dsad", false);
    Issue* d = &f;
    cout<<lib->is_unique_id(2137)<<endl;
    cout<<lib->is_unique_id(66622)<<endl;
    cout<<lib->is_unique_id(6662)<<endl;
    cout<<lib->is_unique_id(5)<<endl;
    // lib->save_to_file();

    return 0;
}
