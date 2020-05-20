#include <iostream>
#include "elements.h"

using namespace std;

Book::Book(int id, string t, int y, int pag, string pub)
{
    id_number = id;
    title = t;
    year = y;
    pages = pag;
    publisher = pub;
}

Book::~Book()
{}

Audiobook::Audiobook(int id, string t, int y, int pag, string pub, string form)
{
    id_number = id;
    title = t;
    year = y;
    pages = pag;
    publisher = pub;
    format = form;
}

Audiobook::~Audiobook()
{}

Magazine::Magazine(int id, string t, int y, int pag, string pub, int num)
{
    id_number = id;
    title = t;
    year = y;
    pages = pag;
    publisher = pub;
    number = num;
}

Magazine::~Magazine()
{}

void Book::showProperties()///funkcja placeholderowa
{
    cout<<"Numer ID: "<<id_number<<endl;
    cout<<"Tytul: "<<title<<endl;
    cout<<"Rok wydania: "<<year<<endl;
    cout<<"Iloœæ stron: "<<pages<<endl;
    cout<<"Wydawca: "<<publisher<<endl;
}

void Audiobook::showProperties()///funkcja placeholderowa
{
    cout<<"Numer ID: "<<id_number<<endl;
    cout<<"Tytul: "<<title<<endl;
    cout<<"Rok wydania: "<<year<<endl;
    cout<<"Ilosc stron: "<<pages<<endl;
    cout<<"Wydawca: "<<publisher<<endl;
    cout<<"Format: "<<format<<endl;
}
