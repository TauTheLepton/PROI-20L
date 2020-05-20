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
        //Author autor;
        string publisher;
    public:
        string title;
        virtual void showProperties() = 0;

};

class Book:public Issue
{
    ///Klasa reprezentujaca ksiazke
    public:
        Book(int, string, int, int, string);
        ~Book();
        void showProperties();
};

class Magazine:public Issue
{
    ///Klasa reprezentujaca czasopismo
    public:

};

class ScientificWork:public Issue
{
    ///Klasa reprezentujaca prace naukowa
};

class Audiobook:public Issue
{
    ///Klasa reprezentująca audiobook

    private:
        string format;
    public:
        Audiobook(int, string, int, int, string, string);
        ~Audiobook();
        void showProperties();

};


#endif // ELEMENTS_H_INCLUDED
