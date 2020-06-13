#ifndef ELEMENTS_H_INCLUDED
#define ELEMENTS_H_INCLUDED

#include <vector>
#include <string>

using namespace std;

class Issue
{
    ///Klasa reprezentujaca egzemplarz danego wydania
    ///Dziedziczy bezposrednio po Release oraz bêdzie
    ///ona podstawa dla dziedziczenia polimorficznego
    ///dla Book, Magazine i ScientificWork oraz dziedziczenia
    ///normalnego dla Audiobook

    protected:
        int id_number;  ///zmienna reprezentujaca numer ID danego wydania
        int year;       ///zmienna reprezentujaca rok powstania danegop wydania
        int pages;      ///zmienna reprezentujaca liczbe stron danego wydania
        string authorName;      ///zmienna reprezentujaca imie autora
        string authorSurname;   ///zmienna reprezentujaca nazwisko autora
        string publisher;       ///zmienna reprezentujaca wydawce
        string title;           ///zmienna reprezentujaca tytul danego wydania
        bool is_available;      ///zmienna oznaczajaca stan, czy ksiazka jest wypozyczona
    public:
        int get_id();   ///gettery do wszystkich pol
        string get_title();
        string get_name();
        string get_surname();
        int get_year();
        int get_pages();
        string get_publisher();
        void change_status();   ///metoda zmieniajaca status wypozyczenia danego elementu
        bool get_is_available();    ///funkcja sprawdzajaca dostepnosc ksiazki
        virtual string get_info() = 0;  ///wirtualna funkcja zwracajaca wszystkie informacje o obiekcie
        virtual int get_number() = 0;   ///wirtualne gettery pol specjalnych, powtarzaja sie potem dla kazdego z typow obiektow
        virtual string get_discipline() = 0;
        virtual string get_format() = 0;
        virtual string get_caption() = 0;   ///funkcja zwracająca tekst, ktory bedzie reprezentowal rekord w wynikach wyszukiwania

};

class Book:public Issue
{
    ///Klasa reprezentujaca ksiazke
    public:
        Book(int, string, string, string, int, int, string, bool);
        ~Book();
        void showProperties();
        int get_number();
        string get_discipline();
        string get_format();
        string get_info();
        string get_caption();
};

class Magazine:public Issue
{
    ///Klasa reprezentujaca czasopismo
    private:
        int number; /// zmienna oznaczajaca numer czasopisma
    public:
        Magazine(int, string, string, string, int, int, string, int, bool);
        ~Magazine();
        int get_number();
        string get_discipline();
        string get_format();
        string get_info();
        string get_caption();
};

class ScientificWork:public Issue
{
    ///Klasa reprezentujaca prace naukowa
    private:
        string discipline;  ///pole reprezentujace dziedzine nauki danej prscy naukowej
    public:
        ScientificWork(int, string, string, string, int, int, string, string, bool);
        ~ScientificWork();
        int get_number();
        string get_discipline();
        string get_format();
        string get_info();
        string get_caption();
};

class Audiobook:public Issue
{
    ///Klasa reprezentująca audiobook
    private:
        string format;  ///pole reprezentujace format plikow danego audiobooka
    public:
        Audiobook(int, string, string, string, int, int, string, string, bool);
        ~Audiobook();
        int get_number();
        string get_discipline();
        string get_format();
        string get_info();
        string get_caption();
};



#endif // ELEMENTS_H_INCLUDED
