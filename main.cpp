#include <iostream>
#include "application.h"

using namespace std;

int main()
{
    ///Tutaj bedzie jakis event loop

    ///to tak tylko do testowania
    Library lib;
    lib.read_from_file();
    lib.showAssets();
    vector<Issue*> results=lib.search_by(0, 0, "Ferdydurke");
    cout<<results.size()<<endl;
    cout<<results[0]->authorName<<endl;
    results=lib.search_by(1, 2, "Gombrowicz");
    cout<<results.size()<<endl;
    cout<<results[0]->authorName<<endl;
    results=lib.search_by(2, 0, "imie1");
    cout<<results.size()<<endl;
    cout<<results[0]->authorName<<endl;
    results=lib.search_by(3, 0, "Christie");
    cout<<results.size()<<endl;
    cout<<results[0]->authorName<<endl;
    results=lib.search_by(4, 1937, "Gombrowicz");
    cout<<results.size()<<endl;
    cout<<results[0]->authorName<<endl;
    cout<<results[1]->authorName<<endl;
    results=lib.search_by(5, 30, "Gombrowicz");
    cout<<results.size()<<endl;
    cout<<results[0]->authorName<<endl;
    results=lib.search_by(6, 0, "wydawca3");
    cout<<results.size()<<endl;
    cout<<results[0]->authorName<<endl;
    return 0;
}
