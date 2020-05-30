#include <iostream>
#include "elements.h"

using namespace std;

Book::Book(int id, string t, string n, string sur, int y, int pag, string pub)
{
    id_number = id;
    title = t;
    authorName = n;
    authorSurname = sur;
    year = y;
    pages = pag;
    publisher = pub;
}

Book::~Book()
{}

Audiobook::Audiobook(int id, string t, string n, string sur, int y, int pag, string pub, string form)
{
    id_number = id;
    title = t;
    authorName = n;
    authorSurname = sur;
    year = y;
    pages = pag;
    publisher = pub;
    format = form;
}

Audiobook::~Audiobook()
{}

Magazine::Magazine(int id, string t, string n, string sur, int y, int pag, string pub, int num)
{
    id_number = id;
    title = t;
    authorName = n;
    authorSurname = sur;
    year = y;
    pages = pag;
    publisher = pub;
    number = num;
}

Magazine::~Magazine()
{}

ScientificWork::ScientificWork(int id, string t, string n, string sur, int y, int pag, string pub, string dis)
{
    id_number = id;
    title = t;
    authorName = n;
    authorSurname = sur;
    year = y;
    pages = pag;
    publisher = pub;
    discipline = dis;
}

ScientificWork::~ScientificWork()
{}

int Issue::get_id()
{
    return id_number;
}

string Issue::get_title()
{
    return title;
}

string Issue::get_name()
{
    return authorName;
}

string Issue::get_surname()
{
    return authorSurname;
}

int Issue::get_year()
{
    return year;
}

int Issue::get_pages()
{
    return pages;
}

string Issue::get_publisher()
{
    return publisher;
}

///zaczyna sie wirtualne na numer dziedzine i format

int Book::get_number()
{
    int i=-1;
    return i;
}

string Book::get_discipline()
{
    string i="NONE";
    return i;
}

string Book::get_format()
{
    string i="NONE";
    return i;
}

int Audiobook::get_number()
{
    int i=-1;
    return i;
}

string Audiobook::get_discipline()
{
    string i="NONE";
    return i;
}

string Audiobook::get_format()
{
    return format;
}

int Magazine::get_number()
{
    return number;
}

string Magazine::get_discipline()
{
    string i="NONE";
    return i;
}

string Magazine::get_format()
{
    string i="NONE";
    return i;
}

int ScientificWork::get_number()
{
    int i=-1;
    return i;
}

string ScientificWork::get_discipline()
{
    return discipline;
}

string ScientificWork::get_format()
{
    string i="NONE";
    return i;
}

void Book::showProperties()///funkcja placeholderowa
{
    cout<<"Numer ID: "<<id_number<<endl;
    cout<<"Tytul: "<<title<<endl;
    cout<<"Autor: "<<authorName<<" "<<authorSurname<<endl;
    cout<<"Rok wydania: "<<year<<endl;
    cout<<"Ilosc stron: "<<pages<<endl;
    cout<<"Wydawca: "<<publisher<<endl;
}

void Audiobook::showProperties()///funkcja placeholderowa
{
    cout<<"Numer ID: "<<id_number<<endl;
    cout<<"Tytul: "<<title<<endl;
    cout<<"Autor: "<<authorName<<" "<<authorSurname<<endl;
    cout<<"Rok wydania: "<<year<<endl;
    cout<<"Ilosc stron: "<<pages<<endl;
    cout<<"Wydawca: "<<publisher<<endl;
    cout<<"Format: "<<format<<endl;
}

void Magazine::showProperties()///funkcja placeholderowa
{
    cout<<"Numer ID: "<<id_number<<endl;
    cout<<"Tytul: "<<title<<endl;
    cout<<"Autor: "<<authorName<<" "<<authorSurname<<endl;
    cout<<"Rok wydania: "<<year<<endl;
    cout<<"Ilosc stron: "<<pages<<endl;
    cout<<"Wydawca: "<<publisher<<endl;
    cout<<"Numer: "<<number<<endl;
}

void ScientificWork::showProperties()///funkcja placeholderowa
{
    cout<<"Numer ID: "<<id_number<<endl;
    cout<<"Tytul: "<<title<<endl;
    cout<<"Autor: "<<authorName<<" "<<authorSurname<<endl;
    cout<<"Rok wydania: "<<year<<endl;
    cout<<"Ilosc stron: "<<pages<<endl;
    cout<<"Wydawca: "<<publisher<<endl;
    cout<<"Dziedzina: "<<discipline<<endl;
}