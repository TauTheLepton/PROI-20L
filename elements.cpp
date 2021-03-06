#include <iostream>
#include <sstream>
#include <string>
#include "elements.h"

using namespace std;

Book::Book(int id, string t, string n, string sur, int y, int pag, string pub, bool status)
{
    id_number = id;
    title = t;
    authorName = n;
    authorSurname = sur;
    year = y;
    pages = pag;
    publisher = pub;
    is_available = status;
}

Book::~Book()
{}

Audiobook::Audiobook(int id, string t, string n, string sur, int y, int pag, string pub, string form, bool status)
{
    id_number = id;
    title = t;
    authorName = n;
    authorSurname = sur;
    year = y;
    pages = pag;
    publisher = pub;
    format = form;
    is_available = status;
}

Audiobook::~Audiobook()
{}

Magazine::Magazine(int id, string t, string n, string sur, int y, int pag, string pub, int num, bool status)
{
    id_number = id;
    title = t;
    authorName = n;
    authorSurname = sur;
    year = y;
    pages = pag;
    publisher = pub;
    number = num;
    is_available = status;
}

Magazine::~Magazine()
{}

ScientificWork::ScientificWork(int id, string t, string n, string sur, int y, int pag, string pub, string dis, bool status)
{
    id_number = id;
    title = t;
    authorName = n;
    authorSurname = sur;
    year = y;
    pages = pag;
    publisher = pub;
    discipline = dis;
    is_available = status;
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

bool Issue::get_is_available()
{
    return is_available;
}

void Issue::change_status()
{
    if (is_available == true)
    {
        is_available = false;
    }
    else
    {
        is_available = true;
    }
}

///gettery pol specjalnych

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

string Book::get_caption()
{
    ostringstream ss;

    ss<<this->title<<"; "<<this->authorName[0]<<". "<<this->authorSurname<<"; "<<this->year;

    return ss.str();
}

string Book::get_info()
{
    ostringstream ss;
    ss<<"Typ egzemplarza: ksiazka"<<"\n";
    ss<<"Numer sygnatury: "<<this->get_id()<<"\n";
    ss<<"Tytul: "<<this->get_title()<<"\n";
    ss<<"Autor: "<<this->get_name()<<" "<<this->get_surname()<<"\n";
    ss<<"Rok wydania: "<<this->get_year()<<"\n";
    ss<<"Wydawca: "<<this->get_publisher()<<"\n";
    ss<<"Liczba stron: "<<this->get_pages()<<"\n";

    string status = this->get_is_available()?"Dostepny":"Wypozyczony";
    ss<<"Status: "<<status;

    return ss.str();
}

string Audiobook::get_info()
{
    ostringstream ss;
    ss<<"Typ egzemplarza: audiobook"<<"\n";
    ss<<"Numer sygnatury: "<<this->get_id()<<"\n";
    ss<<"Tytul: "<<this->get_title()<<"\n";
    ss<<"Autor: "<<this->get_name()<<" "<<this->get_surname()<<"\n";
    ss<<"Rok wydania: "<<this->get_year()<<"\n";
    ss<<"Wydawca: "<<this->get_publisher()<<"\n";
    ss<<"Format: "<<this->get_format()<<"\n";
    ss<<"Dlugosc w minutach: "<<this->get_pages()<<"\n";

    string status = this->get_is_available()?"Dostepny":"Wypozyczony";
    ss<<"Status: "<<status;

    return ss.str();
}

string Audiobook::get_caption()
{
    ostringstream ss;

    ss<<this->title<<"; "<<this->authorName[0]<<". "<<this->authorSurname<<"; "<<this->year;

    return ss.str();
}

string Magazine::get_info()
{
    ostringstream ss;

    ss<<"Typ egzemplarza: czasopismo"<<"\n";
    ss<<"Numer sygnatury: "<<this->get_id()<<"\n";
    ss<<"Tytul: "<<this->get_title()<<"\n";
    ss<<"Autor: "<<this->get_name()<<" "<<this->get_surname()<<"\n";
    ss<<"Rok wydania: "<<this->get_year()<<"\n";
    ss<<"Numer: "<<this->get_number()<<"\n";
    ss<<"Wydawca: "<<this->get_publisher()<<"\n";
    ss<<"Liczba stron: "<<this->get_pages()<<"\n";

    string status = this->get_is_available()?"Dostepny":"Wypozyczony";
    ss<<"Status: "<<status;

    return ss.str();
}

string Magazine::get_caption()
{
    ostringstream ss;

    ss<<this->title<<"; "<<this->authorName[0]<<". "<<this->authorSurname<<"; ";
    if(number<10)
    {
        ss<<0;
    }
    ss<<this->number<<"/"<<this->year;

    return ss.str();
}

string ScientificWork::get_info()
{
    ostringstream ss;


    ss<<"Typ egzemplarza: ksiazka"<<"\n";
    ss<<"Numer sygnatury: "<<this->get_id()<<"\n";
    ss<<"Tytul: "<<this->get_title()<<"\n";
    ss<<"Autor: "<<this->get_name()<<" "<<this->get_surname()<<"\n";
    ss<<"Dziedzina naukowa: "<<this->get_discipline()<<"\n";
    ss<<"Rok wydania: "<<this->get_year()<<"\n";
    ss<<"Wydawca: "<<this->get_publisher()<<"\n";
    ss<<"Liczba stron: "<<this->get_pages()<<"\n";

    string status = this->get_is_available()?"Dostepny":"Wypozyczony";
    ss<<"Status: "<<status;

    return ss.str();
}

string ScientificWork::get_caption()
{
    ostringstream ss;

    ss<<this->title<<"; "<<this->authorName[0]<<". "<<this->authorSurname<<"; "<<this->discipline<<";"<<this->year;

    return ss.str();
}
