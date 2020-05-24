#ifndef ELEMENTS_H_INCLUDED
#define ELEMENTS_H_INCLUDED

#include <vector>

using namespace std;

class Author
{
    ///Klasa reprezentujaca autora
    private:
        string name;
        string surname;
        //Date birth_date;
        //vector<string> pseudonyms;
    public:
        Author(string,string);
        ~Author();
};

class Issue
{
    ///Klasa reprezentujaca egzemplarz danego wydania
    ///Dziedziczy bezposrednio po Release oraz bêdzie
    ///ona podstawa dla dziedziczenia polimorficznego
    ///dla Book, Magazine i ScientificWork oraz dziedziczenia
    ///normalnego dla Audiobook

    protected:
        int id_number;
        int year;
        int pages;
        string authorName;
        string authorSurname;
        //Author autor;
        string publisher;
    public:
        int get_id();
        string get_title();
        string get_name();
        string get_surname();
        int get_year();
        int get_pages();
        string get_publisher();
        virtual int get_number() = 0;
        virtual string get_discipline() = 0;
        virtual string get_format() = 0;
        string title;
        virtual void showProperties() = 0;

};

class Book:public Issue
{
    ///Klasa reprezentujaca ksiazke
    public:
        Book(int, string, string, string, int, int, string);
        ~Book();
        void showProperties();
        int get_number();
        string get_discipline();
        string get_format();
};

class Magazine:public Issue
{
    ///Klasa reprezentujaca czasopismo
    private:
        int number; /// zmienna oznaczajaca numer czasopisma
    public:
        Magazine(int, string, string, string, int, int, string, int);
        ~Magazine();
        void showProperties();
        int get_number();
        string get_discipline();
        string get_format();
};

class ScientificWork:public Issue
{
    ///Klasa reprezentujaca prace naukowa
    private:
        string discipline;
    public:
        ScientificWork(int, string, string, string, int, int, string, string);
        ~ScientificWork();
        void showProperties();
        int get_number();
        string get_discipline();
        string get_format();
};

class Audiobook:public Issue
{
    ///Klasa reprezentująca audiobook

    private:
        string format;
    public:
        Audiobook(int, string, string, string, int, int, string, string);
        ~Audiobook();
        void showProperties();
        int get_number();
        string get_discipline();
        string get_format();

};

void get_info();


#endif // ELEMENTS_H_INCLUDED
