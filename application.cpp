#include <iostream>
#include <vector>
#include "application.h"
#include "elements.h"

using namespace std;

Library::Library()
{
}

Library::~Library()
{

}

void Library::showAssets()
{
    for(Issue* n: issues)
    {
        cout<<n->title<<endl;
    }
}

void Library::add_to_library(Issue* is)
{
    issues.push_back(is);
}

Library* Library::instance = 0;

Library* Library::getInstance()
{
    if (instance == 0)
    {
        instance = new Library();
    }

    return instance;
}

void OperationStack::push(string n)
{
    operations.push_back(n);
}

string OperationStack::pull()
{
    if (operations.size() != 0)
    {
        string f = operations[operations.size()-1];
        operations.pop_back();

        return f;
    }

    else
    {
        return "Brak informacji o poprzednich operacjach";
    }
}
