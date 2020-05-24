#include <iostream>
#include "application.h"

using namespace std;

int main()
{
    ///Tutaj bedzie jakis event loop

    ///to tak tylko do testowania
    Library lib;
    lib.read_from_file();
    lib.showAssets();   ///ladnie pokazuje zawartosc
    vector<Issue*> results;
    results=lib.search_by(0, 0, "Ferdydurke");  ///szukanie po tytule
    cout<<results.size()<<endl;
    cout<<results[0]->get_name()<<endl;
    results=lib.search_by(1, 2, "Gombrowicz");  ///szukanie po id
    cout<<results.size()<<endl;
    cout<<results[0]->get_name()<<endl;
    results=lib.search_by(2, 0, "imie1");   ///szukanie po imieniu
    cout<<results.size()<<endl;
    cout<<results[0]->get_name()<<endl;
    results=lib.search_by(3, 0, "Christie");    ///szukanie po nazwisku
    cout<<results.size()<<endl;
    cout<<results[0]->get_name()<<endl;
    results=lib.search_by(4, 1937, "Gombrowicz");   ///szukanie po roku
    cout<<results.size()<<endl;
    cout<<results[0]->get_name()<<endl;
    cout<<results[1]->get_name()<<endl;
    results=lib.search_by(5, 30, "Gombrowicz"); ///szukanie po stronach
    cout<<results.size()<<endl;
    cout<<results[0]->get_name()<<endl;
    results=lib.search_by(6, 0, "wydawca3");    ///szukanie po wydawcy
    cout<<results.size()<<endl;
    cout<<results[0]->get_name()<<endl;
    results=lib.search_by(7, 3, "wydawca3");    ///szukanie po numerze
    cout<<results.size()<<endl;
    cout<<results[0]->get_name()<<endl;
    results=lib.search_by(8, 0, "Chemistry");   ///szukanie po dziedzinie
    cout<<results.size()<<endl;
    cout<<results[0]->get_name()<<endl;
    results=lib.search_by(9, 0, "format2"); ///szukanie po formacie
    cout<<results.size()<<endl;
    cout<<results[0]->get_name()<<endl;

    return 0;
}
