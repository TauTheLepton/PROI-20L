#include <iostream>
#include <assert.h>
#include "application.h"
#include "elements.h"
#include <vector>
#include <sstream>
#include <fstream>
#include "test.h"

using namespace std;

void make_library()
{
    Library* lib = Library::getInstance();
    lib->clear();
    Book* b = new Book(1, "title_1", "name_1", "surname_1", 2001, 101, "publisher_1", true);
    lib->add_to_library(b);
    Audiobook* a = new Audiobook(2, "title_2", "name_2", "surname_2", 2002, 102, "publisher_2", "format", true);
    lib->add_to_library(a);
    Magazine* m = new Magazine(3, "title_3", "name_3", "surname_3", 2003, 103, "publisher_3", 13, true);
    lib->add_to_library(m);
    ScientificWork* s = new ScientificWork(4, "title_4", "name_4", "surname_4", 2004, 104, "publisher_4", "discipline", true);
    lib->add_to_library(s);
}

void book()
{
    Book a(1, "title_1", "name_1", "surname_1", 2001, 101, "publisher_1", true);
    assert(a.get_id() == 1);
    assert(a.get_title() == "title_1");
    assert(a.get_name() == "name_1");
    assert(a.get_surname() == "surname_1");
    assert(a.get_year() == 2001);
    assert(a.get_pages() == 101);
    assert(a.get_publisher() == "publisher_1");
    assert(a.get_format() == "NONE");
    assert(a.get_number() == -1);
    assert(a.get_discipline() == "NONE");
    assert(a.get_is_available() == true);
}

void audiobook()
{
    Audiobook a(1, "title_1", "name_1", "surname_1", 2001, 101, "publisher_1", "format", true);
    assert(a.get_id() == 1);
    assert(a.get_title() == "title_1");
    assert(a.get_name() == "name_1");
    assert(a.get_surname() == "surname_1");
    assert(a.get_year() == 2001);
    assert(a.get_pages() == 101);
    assert(a.get_publisher() == "publisher_1");
    assert(a.get_format() == "format");
    assert(a.get_number() == -1);
    assert(a.get_discipline() == "NONE");
    assert(a.get_is_available() == true);
}

void magazine()
{
    Magazine a(1, "title_1", "name_1", "surname_1", 2001, 101, "publisher_1", 11, true);
    assert(a.get_id() == 1);
    assert(a.get_title() == "title_1");
    assert(a.get_name() == "name_1");
    assert(a.get_surname() == "surname_1");
    assert(a.get_year() == 2001);
    assert(a.get_pages() == 101);
    assert(a.get_publisher() == "publisher_1");
    assert(a.get_format() == "NONE");
    assert(a.get_number() == 11);
    assert(a.get_discipline() == "NONE");
    assert(a.get_is_available() == true);
}

void scientific_work()
{
    ScientificWork a(1, "title_1", "name_1", "surname_1", 2001, 101, "publisher_1", "discipline", true);
    assert(a.get_id() == 1);
    assert(a.get_title() == "title_1");
    assert(a.get_name() == "name_1");
    assert(a.get_surname() == "surname_1");
    assert(a.get_year() == 2001);
    assert(a.get_pages() == 101);
    assert(a.get_publisher() == "publisher_1");
    assert(a.get_format() == "NONE");
    assert(a.get_number() == -1);
    assert(a.get_discipline() == "discipline");
    assert(a.get_is_available() == true);
}

void issues()
{
    Library* lib = Library::getInstance();
    lib->clear();
    Book* b1 = new Book(1, "title_3", "name_1", "surname_1", 2001, 101, "publisher_1", true);
    Audiobook* a1 = new Audiobook(2, "title_1", "name_1", "surname_1", 2001, 101, "publisher_1", "format", true);
    lib->add_to_library(b1);
    lib->add_to_library(a1);
    vector<Issue*> vec = lib->getIssues();
    assert(vec[0]->get_id() == 1);
    assert(vec[0]->get_format() == "NONE");
    assert(vec[1]->get_id() == 2);
    assert(vec[1]->get_format() == "format");
    lib->clear();
}

void write_read()
{
    char* file="test_data.csv";
    make_library();
    Library* lib = Library::getInstance();
    lib->save_to_file(file);
    lib->clear();
    lib->read_from_file(file);
    vector<Issue*> vec = lib->getIssues();
    assert(vec[0]->get_id() == 1);
    assert(vec[1]->get_format() == "format");
    assert(vec[2]->get_number() == 13);
    assert(vec[3]->get_discipline() == "discipline");
    lib->clear();
    delete file;
}

void _search()
{
    make_library();
    Library* lib = Library::getInstance();
    vector<Issue*> vec;
    vec = lib->search_by(0,1,"");
    assert(vec[0]->get_name() == "name_1");
    vec = lib->search_by(1,1,"title_2");
    assert(vec[0]->get_name() == "name_2");
    vec = lib->search_by(2,1,"name_3");
    assert(vec[0]->get_id() == 3);
    vec = lib->search_by(3,1,"surname_4");
    assert(vec[0]->get_name() == "name_4");
    vec = lib->search_by(4,2001,"");
    assert(vec[0]->get_name() == "name_1");
    vec = lib->search_by(5,1,"publisher_2");
    assert(vec[0]->get_name() == "name_2");
    vec = lib->search_by(6,103,"");
    assert(vec[0]->get_name() == "name_3");
    vec = lib->search_by(7,13,"");
    assert(vec[0]->get_name() == "name_3");
    vec = lib->search_by(8,1,"discipline");
    assert(vec[0]->get_name() == "name_4");
    vec = lib->search_by(9,1,"format");
    assert(vec[0]->get_name() == "name_2");
    lib->clear();
}

void _unique()
{
    make_library();
    Library* lib = Library::getInstance();
    assert(lib->is_unique_id(3) == false);
    assert(lib->is_unique_id(5) == true);
    lib->clear();
}

void id()
{
    make_library();
    Library* lib = Library::getInstance();
    bool bol = lib->delete_id(3);
    assert(bol == true);
    vector<Issue*> vec = lib->getIssues();
    assert(vec[2]->get_name() == "name_4");
    lib->clear();
}

void exception_6()
{
    Library* lib = Library::getInstance();
    const char* file_name = "test_data.csv";
    ofstream save_file;
    save_file.open(file_name, ios::out);
    save_file<<"Book\n";
    save_file<<"1,nazwa1,imie1,nazwisko1,1,1,wydawca1,true\n";
    save_file<<"Audiobook\n";
    save_file<<"1,nazwa2,imie2,nazwisko2,2,2,wydawca2,format2,true\n";
    save_file.close();

    bool exceptionThrown = false;
    ifstream dataFile;
    dataFile.open(file_name);
    string type;
    try
    {
        lib->read_from_file(file_name);
    }
    catch(...)
    {
        exceptionThrown = true;
    }
    assert(exceptionThrown);
    lib->clear();
}

void exception_0()
{
    Library* lib = Library::getInstance();
    const char* file_name = "test_data.csv";
    ofstream save_file;
    save_file.open(file_name, ios::out);
    save_file<<"Book\n";
    save_file<<"1,nazwa1,imie1,nazwisko1,1,1,wydawca1,true1\n";
    save_file.close();

    bool exceptionThrown = false;
    ifstream dataFile;
    dataFile.open(file_name);
    string type;
    try
    {
        lib->read_from_file(file_name);
    }
    catch(...)
    {
        exceptionThrown = true;
    }
    assert(exceptionThrown);
    lib->clear();
}

void exception_1()
{
    Library* lib = Library::getInstance();
    const char* file_name = "test_data.csv";
    ofstream save_file;
    save_file.open(file_name, ios::out);
    save_file<<"Book\n";
    save_file<<"0,nazwa1,imie1,nazwisko1,2,1,wydawca1,true\n";
    save_file.close();

    bool exceptionThrown = false;
    ifstream dataFile;
    dataFile.open(file_name);
    string type;
    try
    {
        lib->read_from_file(file_name);
    }
    catch(...)
    {
        exceptionThrown = true;
    }
    assert(exceptionThrown);
    lib->clear();
}

void exception_2()
{
    Library* lib = Library::getInstance();
    const char* file_name = "test_data.csv";
    ofstream save_file;
    save_file.open(file_name, ios::out);
    save_file<<"Book\n";
    save_file<<"1,nazwa1,imie1,nazwisko1,0,1,wydawca1,true\n";
    save_file.close();

    bool exceptionThrown = false;
    ifstream dataFile;
    dataFile.open(file_name);
    string type;
    try
    {
        lib->read_from_file(file_name);
    }
    catch(...)
    {
        exceptionThrown = true;
    }
    assert(exceptionThrown);
    lib->clear();
}

void exception_3()
{
    Library* lib = Library::getInstance();
    const char* file_name = "test_data.csv";
    ofstream save_file;
    save_file.open(file_name, ios::out);
    save_file<<"Book\n";
    save_file<<"1,nazwa1,imie1,nazwisko1,2,0,wydawca1,true\n";
    save_file.close();

    bool exceptionThrown = false;
    ifstream dataFile;
    dataFile.open(file_name);
    string type;
    try
    {
        lib->read_from_file(file_name);
    }
    catch(...)
    {
        exceptionThrown = true;
    }
    assert(exceptionThrown);
    lib->clear();
}

void exception_4()
{
    Library* lib = Library::getInstance();
    const char* file_name = "test_data.csv";
    ofstream save_file;
    save_file.open(file_name, ios::out);
    save_file<<"Magazine\n";
    save_file<<"6969,Fantastyka,Imie,Nazwisko,2022,30,wydawca_3,0,true\n";
    save_file.close();

    bool exceptionThrown = false;
    ifstream dataFile;
    dataFile.open(file_name);
    string type;
    try
    {
        lib->read_from_file(file_name);
    }
    catch(...)
    {
        exceptionThrown = true;
    }
    assert(exceptionThrown);
    lib->clear();
}
