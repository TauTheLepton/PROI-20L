#ifndef ELEMENTS_H_INCLUDED
#define ELEMENTS_H_INCLUDED

class Autor
{
    ///Klasa reprezentujaca autora
};

class Release
{
    ///Klasa reprezentujaca pojedyncze wydanie
};

class Issue:public Release
{
    ///Klasa reprezentujaca egzemplarz danego wydania
    ///Dziedziczy bezposrednio po Release oraz bêdzie
    ///ona podstawa dla dziedziczenia polimorficznego
};

class Book:public Issue
{
    ///Klasa reprezentujaca ksiazkê
};

class Magazine:public Issue
{
    ///Klasa reprezentuj¹ca czasopismo
};

class Scientific_work:public Issue
{
    ///Klasa reprezentujaca prace naukowa
};

void get_info()
{
    ///Funkcja zwracająca informacje o obiektach
}

#endif // ELEMENTS_H_INCLUDED
