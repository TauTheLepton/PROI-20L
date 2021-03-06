#include <iostream>
#include <vector>
#include "application.h"
#include "elements.h"
#include <fstream>
#include <string>
#include <sstream>
#include <typeinfo>

using namespace std;

vector<string> OperationStack::operations; ///inicjalizacja statycznego wektora

Library::Library()
{
}

Library::~Library()
{
    for(int i=0; i<issues.size(); i++)
    {
        delete issues[i];
    }
}

void Library::add_to_library(Issue* is)
{
    issues.push_back(is);
}

void Library::clear()
{
    for(int i=0; i<issues.size(); i++)
    {
        delete issues[i];
    }
    issues.clear();
}

void Library::read_from_file(const char* file_name)
{
    ifstream dataFile;
    dataFile.open(file_name);
    string type;        ///zmienna do ktorej czytany jest typ kolejnego obiektu z pliku
    string id_number;
    int id_number_int;
    string year;
    int year_int;
    string pages;
    int pages_int;
    string authorName;
    string authorSurname;
    string publisher;
    string title;
    string special;
    int special_int;
    string status;
    bool status_bool;
    Issue* temp2;

    int control_variable_1 = 0;
    int control_variable_2 = 0;

    if(dataFile.fail())
    {
        throw 5;
    }
    while(dataFile.good())
    {
        getline(dataFile,type,'\n');
        if(type=="Book")
        {
            getline(dataFile,id_number,',');
            getline(dataFile,title,',');
            getline(dataFile,authorName,',');
            getline(dataFile,authorSurname,',');
            getline(dataFile,year,',');
            getline(dataFile,pages,',');
            getline(dataFile,publisher,',');
            getline(dataFile,status,'\n');
            stringstream degree1(id_number);
            degree1 >> id_number_int;
            stringstream degree2(year);
            degree2 >> year_int;
            stringstream degree3(pages);
            degree3 >> pages_int;
            if(status == "true")
            {
                status_bool = true;
            }
            else if(status == "false")
            {
                status_bool = false;
            }
            else    ///exceptions
            {
                throw 0;
            }
            if(id_number_int < 1)
            {
                throw 1;
            }
            if(year_int < 1)
            {
                throw 2;
            }
            if(pages_int < 1)
            {
                throw 3;
            }
            if(is_unique_id(id_number_int) == false)
            {
                throw 6;
            }

            Book* b = new Book(id_number_int, title, authorName, authorSurname, year_int, pages_int, publisher, status_bool);
            this->add_to_library(b);
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
            getline(dataFile,special,',');
            getline(dataFile,status,'\n');
            stringstream degree1(id_number);
            degree1 >> id_number_int;
            stringstream degree2(year);
            degree2 >> year_int;
            stringstream degree3(pages);
            degree3 >> pages_int;
            if(status == "true")
            {
                status_bool = true;
            }
            else if(status == "false")
            {
                status_bool = false;
            }
            else    ///exceptions
            {
                throw 0;
            }
            if(id_number_int < 1)
            {
                throw 1;
            }
            if(year_int < 1)
            {
                throw 2;
            }
            if(pages_int < 1)
            {
                throw 3;
            }
            if(is_unique_id(id_number_int) == false)
            {
                throw 6;
            }

            Audiobook* a = new Audiobook(id_number_int, title, authorName, authorSurname, year_int, pages_int, publisher, special, status_bool);
            this->add_to_library(a);
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
            getline(dataFile,special,',');
            getline(dataFile,status,'\n');
            stringstream degree1(id_number);
            degree1 >> id_number_int;
            stringstream degree2(year);
            degree2 >> year_int;
            stringstream degree3(pages);
            degree3 >> pages_int;
            stringstream degree4(special);
            degree4 >> special_int;
            if(status == "true")
            {
                status_bool = true;
            }
            else if(status == "false")
            {
                status_bool = false;
            }
            else    ///exceptions
            {
                throw 0;
            }
            if(id_number_int < 1)
            {
                throw 1;
            }
            if(year_int < 1)
            {
                throw 2;
            }
            if(pages_int < 1)
            {
                throw 3;
            }
            if(special_int < 1)
            {
                throw 4;
            }
            if(is_unique_id(id_number_int) == false)
            {
                throw 6;
            }

            Magazine* m = new Magazine(id_number_int, title, authorName, authorSurname, year_int, pages_int, publisher, special_int, status_bool);
            this->add_to_library(m);
        }
        else if(type=="ScientificWork")
        {
            getline(dataFile,id_number,',');
            getline(dataFile,title,',');
            getline(dataFile,authorName,',');
            getline(dataFile,authorSurname,',');
            getline(dataFile,year,',');
            getline(dataFile,pages,',');
            getline(dataFile,publisher,',');
            getline(dataFile,special,',');
            getline(dataFile,status,'\n');
            stringstream degree1(id_number);
            degree1 >> id_number_int;
            stringstream degree2(year);
            degree2 >> year_int;
            stringstream degree3(pages);
            degree3 >> pages_int;
            if(status == "true")
            {
                status_bool = true;
            }
            else if(status == "false")
            {
                status_bool = false;
            }
            else    ///exceptions
            {
                throw 0;
            }
            if(id_number_int < 1)
            {
                throw 1;
            }
            if(year_int < 1)
            {
                throw 2;
            }
            if(pages_int < 1)
            {
                throw 3;
            }
            if(is_unique_id(id_number_int) == false)
            {
                throw 6;
            }
            ScientificWork* a = new ScientificWork(id_number_int, title, authorName, authorSurname, year_int, pages_int, publisher, special, status_bool);
            this->add_to_library(a);
        }
    }
    dataFile.close();
}

void Library::save_to_file(const char* file_name)
{
    ofstream save_file;
    save_file.open(file_name, ios::out);

    for (int i=0; i<issues.size(); i++)
    {
        ///z pomoca funkcji typeid() sprawdzam typ kazdego z egzemplarzy
        if(((string)typeid(*issues[i]).name()).find("Audiobook")!= string::npos)
        {
            save_file<<"Audiobook\n";
            int t1 = issues[i]->get_id();
            string t2 = issues[i]->get_title();
            string t3 = issues[i]->get_name();
            string t4 = issues[i]->get_surname();
            int t5 = issues[i]->get_year();
            int t6 = issues[i]->get_pages();
            string t7 = issues[i]->get_publisher();
            string t8 = issues[i]->get_format();
            string t9 = issues[i]->get_is_available()?"true":"false";
            save_file<<t1<<","<<t2<<","<<t3<<","<<t4<<","<<t5<<","<<t6<<","<<t7<<","<<t8<<","<<t9<<"\n";

        }
        else if(((string)typeid(*issues[i]).name()).find("Book")!= string::npos)
        {
            save_file<<"Book\n";
            int t1 = issues[i]->get_id();
            string t2 = issues[i]->get_title();
            string t3 = issues[i]->get_name();
            string t4 = issues[i]->get_surname();
            int t5 = issues[i]->get_year();
            int t6 = issues[i]->get_pages();
            string t7 = issues[i]->get_publisher();
            string t8 = issues[i]->get_is_available()?"true":"false";
            save_file<<t1<<","<<t2<<","<<t3<<","<<t4<<","<<t5<<","<<t6<<","<<t7<<","<<t8<<"\n";
        }
        else if(((string)typeid(*issues[i]).name()).find("Magazine")!= string::npos)
        {
            save_file<<"Magazine\n";
            int t1 = issues[i]->get_id();
            string t2 = issues[i]->get_title();
            string t3 = issues[i]->get_name();
            string t4 = issues[i]->get_surname();
            int t5 = issues[i]->get_year();
            int t6 = issues[i]->get_pages();
            string t7 = issues[i]->get_publisher();
            int t8 = issues[i]->get_number();
            string t9 = issues[i]->get_is_available()?"true":"false";
            save_file<<t1<<","<<t2<<","<<t3<<","<<t4<<","<<t5<<","<<t6<<","<<t7<<","<<t8<<","<<t9<<"\n";
        }
        else if(((string)typeid(*issues[i]).name()).find("ScientificWork")!= string::npos)
        {
            save_file<<"ScientificWork\n";
            int t1 = issues[i]->get_id();
            string t2 = issues[i]->get_title();
            string t3 = issues[i]->get_name();
            string t4 = issues[i]->get_surname();
            int t5 = issues[i]->get_year();
            int t6 = issues[i]->get_pages();
            string t7 = issues[i]->get_publisher();
            string t8 = issues[i]->get_discipline();
            string t9 = issues[i]->get_is_available()?"true":"false";
            save_file<<t1<<","<<t2<<","<<t3<<","<<t4<<","<<t5<<","<<t6<<","<<t7<<","<<t8<<","<<t9<<"\n";
        }
    }

    save_file.close();
}

vector<Issue*> Library::search_by(int category, int liczba, string napis)
{
    vector<Issue*> results;
    switch(category)
    {
        case 0:
            results=search_by_id(liczba);
            break;
        case 1:
            results=search_by_title(napis);
            break;
        case 2:
            results=search_by_name(napis);
            break;
        case 3:
            results=search_by_surname(napis);
            break;
        case 4:
            results=search_by_year(liczba);
            break;
        case 5:
            results=search_by_publisher(napis);
            break;
        case 6:
            results=search_by_pages(liczba);
            break;
        case 7:
            results=search_by_number(liczba);
            break;
        case 8:
            results=search_by_discipline(napis);
            break;
        case 9:
            results=search_by_format(napis);
            break;
    }

    return results;
}

vector<Issue*> Library::search_by_name(string name)
{
    vector<Issue*> results;
    for(int i=0; i<issues.size(); i++)
    {
        if (issues[i]->get_name()==name)
        {
            results.push_back(issues[i]);
        }
    }
    return results;
}

vector<Issue*> Library::search_by_surname(string surname)
{
    vector<Issue*> results;
    for(int i=0; i<issues.size(); i++)
    {
        if (issues[i]->get_surname()==surname)
        {
            results.push_back(issues[i]);
        }
    }
    return results;
}

vector<Issue*> Library::search_by_id(int id)
{
    vector<Issue*> results;
    for(int i=0; i<issues.size(); i++)
    {
        if (issues[i]->get_id()==id)
        {
            results.push_back(issues[i]);
        }
    }
    return results;
}

vector<Issue*> Library::search_by_title(string title)
{
    vector<Issue*> results;
    for(int i=0; i<issues.size(); i++)
    {
        if (issues[i]->get_title()==title)
        {
            results.push_back(issues[i]);
        }
    }
    return results;
}

vector<Issue*> Library::search_by_year(int year)
{
    vector<Issue*> results;
    for(int i=0; i<issues.size(); i++)
    {
        if (issues[i]->get_year()==year)
        {
            results.push_back(issues[i]);
        }
    }
    return results;
}

vector<Issue*> Library::search_by_pages(int pages)
{
    vector<Issue*> results;
    for(int i=0; i<issues.size(); i++)
    {
        if (issues[i]->get_pages()==pages)
        {
            results.push_back(issues[i]);
        }
    }
    return results;
}

vector<Issue*> Library::search_by_publisher(string publisher)
{
    vector<Issue*> results;
    for(int i=0; i<issues.size(); i++)
    {
        if (issues[i]->get_publisher()==publisher)
        {
            results.push_back(issues[i]);
        }
    }
    return results;
}

vector<Issue*> Library::search_by_number(int number)
{
    vector<Issue*> results;
    for(int i=0; i<issues.size(); i++)
    {
        if (issues[i]->get_number()==number)
        {
            results.push_back(issues[i]);
        }
    }
    return results;
}

vector<Issue*> Library::search_by_discipline(string discipline)
{
    vector<Issue*> results;
    for(int i=0; i<issues.size(); i++)
    {
        if (issues[i]->get_discipline()==discipline)
        {
            results.push_back(issues[i]);
        }
    }
    return results;
}

vector<Issue*> Library::search_by_format(string format)
{
    vector<Issue*> results;
    for(int i=0; i<issues.size(); i++)
    {
        if (issues[i]->get_format()==format)
        {
            results.push_back(issues[i]);
        }
    }
    return results;
}

vector<Issue*> Library::getIssues()
{
    return issues;
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

bool Library::is_unique_id(int id)
{
    bool result = true;
    for(int i=0; i<issues.size(); i++)
    {
        if(issues[i]->get_id() == id)
        {
            result=false;
        }
    }
    return result;
}

bool Library::delete_id(int id)
{
    bool status=false;
    vector<Issue*> results;
    for(int i=0; i<issues.size(); i++)
    {
        if(issues[i]->get_id() == id)
        {
            status=true;
        }
        else
        {
            results.push_back(issues[i]);
        }
    }
    issues = results;
    return status;
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

vector<string> OperationStack::read()
{
    vector<string> output = this->operations;

    this->operations.clear();

    return output;
}

string report_creator(int type, string message, int issue_id, string parameter_1, string parameter_2)
{
    ostringstream ss;

    if(type == 1)
    {
        ss<<message<<" "<<issue_id;
    }
    else if(type == 2)
    {
        ss<<message<<" "<<parameter_1<<", "<<parameter_2;
    }

    return ss.str();
}
