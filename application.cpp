#include <iostream>
#include <vector>
#include "application.h"
#include "elements.h"
#include <fstream>
#include <string>
#include <sstream>

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

void Library::read_from_file()
{
    ifstream dataFile;
    dataFile.open("data.csv");
    string type;        ///zmienna do ktorej czytany jest typ kolejnego obiektu z pliku
    string id_number;   ///int
    int id_number_int;
    string year;        ///int
    int year_int;
    string pages;       ///int
    int pages_int;
    string authorName;
    string authorSurname;
    string publisher;
    string title;
    string special;
    int special_int;
    while(dataFile.good())
    {
        cout<<"--------------------"<<endl;
        getline(dataFile,type,'\n');
        if(type=="Book")
        {
            //get_book(dataFile);
            getline(dataFile,id_number,',');
            getline(dataFile,title,',');
            getline(dataFile,authorName,',');
            getline(dataFile,authorSurname,',');
            getline(dataFile,year,',');
            getline(dataFile,pages,',');
            getline(dataFile,publisher,'\n');
            stringstream degree1(id_number);
            degree1 >> id_number_int;
            stringstream degree2(year);
            degree2 >> year_int;
            stringstream degree3(pages);
            degree3 >> pages_int;
            Book temp(id_number_int, title, authorName, authorSurname, year_int, pages_int, publisher);
            temp.showProperties();  ///pokazywanko w konsoli
            Book* temp2 = &temp;
            this->add_to_library(temp2);
        }
        else if(type=="Audiobook")
        {
            getline(dataFile,id_number,',');
            getline(dataFile,title,',');
            getline(dataFile,authorName,',');
            getline(dataFile,authorSurname,',');
            getline(dataFile,year,',');
            getline(dataFile,pages,',');
            getline(dataFile,publisher,',');
            getline(dataFile,special,'\n');
            stringstream degree1(id_number);
            degree1 >> id_number_int;
            stringstream degree2(year);
            degree2 >> year_int;
            stringstream degree3(pages);
            degree3 >> pages_int;
            Audiobook temp(id_number_int, title, authorName, authorSurname, year_int, pages_int, publisher, special);
            temp.showProperties();
            Audiobook* temp2 = &temp;
            this->add_to_library(temp2);
        }
        else if(type=="Magazine")
        {
            getline(dataFile,id_number,',');
            getline(dataFile,title,',');
            getline(dataFile,authorName,',');
            getline(dataFile,authorSurname,',');
            getline(dataFile,year,',');
            getline(dataFile,pages,',');
            getline(dataFile,publisher,',');
            getline(dataFile,special,'\n');
            stringstream degree1(id_number);
            degree1 >> id_number_int;
            stringstream degree2(year);
            degree2 >> year_int;
            stringstream degree3(pages);
            degree3 >> pages_int;
            stringstream degree4(special);
            degree4 >> special_int;
            Magazine temp(id_number_int, title, authorName, authorSurname, year_int, pages_int, publisher, special_int);
            temp.showProperties();
            Magazine* temp2 = &temp;
            this->add_to_library(temp2);
        }
    }
    dataFile.close();
}

///nieudanu pomysl, nie wiem jak przekazac plik do funkcji, a poniewaz i tak
///kazda z tych metod bylaby wywolywana raz to nie ma znaczenia gdzie jest
///ten kod dla dlugosci calego programu

// void Library::get_book(const ifstream dataFile&)
// {
//     int id_number;
//     int year;
//     int pages;
//     string authorName;
//     string authorSurname;
//     string publisher;
//     string title;
//     getline(dataFile,id_number,',');
//     getline(dataFile,title,',');
//     getline(dataFile,authorName,',');
//     getline(dataFile,authorSurname,',');
//     getline(dataFile,year,',');
//     getline(dataFile,pages,',');
//     getline(dataFile,publisher,'\n');
//     Book temp(id_number, title, authorName, authorSurname, year, pages, publisher);
//     this->add_to_library(*temp);
// }

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
