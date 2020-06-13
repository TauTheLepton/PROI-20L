#ifndef APPLICATION_H_INCLUDED
#define APPLICATION_H_INCLUDED

#include <vector>
#include "elements.h"


using namespace std;

class Library
{
    ///singletonowska implementacja klasy sterujacej aplikacji

    private:
        static Library* instance;
        vector<Issue*> issues;
        Library(); ///blokuje konstruktor klasy, aby upewnic sie,
            /// ze istniec bedzie tylko jedna instancja klasy Library
    public:                             ///tymczasowo publiczne do testowania
        void read_from_file(const char*);       ///czyta zawartosc pliku o podanej nazwie i zapisuje ja do wektora issues
        void save_to_file(const char*);         ///zapisuje do pliku o podanej nazwie zawartosc wektora issues
        vector<Issue*> search_by_name(string);          ///metoda szukajaca po imieniu autora w spisie wszystkich obiektow biblioteki
        vector<Issue*> search_by_surname(string);       ///metoda szukajaca po nazwisku autora w spisie wszystkich obiektow biblioteki
        vector<Issue*> search_by_id(int);               ///metoda szukajaca po numerze ID w spisie wszystkich obiektow biblioteki
        vector<Issue*> search_by_title(string);         ///metoda szukajaca po tytule w spisie wszystkich obiektow biblioteki
        vector<Issue*> search_by_year(int);             ///metoda szukajaca po roku powstania w spisie wszystkich obiektow biblioteki
        vector<Issue*> search_by_pages(int);            ///metoda szukajaca po liczbie stron w spisie wszystkich obiektow biblioteki
        vector<Issue*> search_by_publisher(string);     ///metoda szukajaca po wydawcy w spisie wszystkich obiektow biblioteki
        vector<Issue*> search_by_number(int);           ///metoda szukajaca po numerze czasopisma w spisie wszystkich obiektow biblioteki (tylko dla czasopisma)
        vector<Issue*> search_by_discipline(string);    ///metoda szukajaca po dziedzinie naukowej w spisie wszystkich obiektow biblioteki (tylko dla pracy naukowej)
        vector<Issue*> search_by_format(string);        ///metoda szukajaca po formacie plikow audiobooka w spisie wszystkich obiektow biblioteki (tylko dla audiobookow)
        vector<Issue*> getIssues();     ///getter wektora wskaznikow do obiektow znajdujacych sie w bibliotece
        void clear();                   ///czysci (usuwa) zawartosc biblioteki
        bool is_unique_id(int);         ///metoda sprawdzajaca unikalnosc ID, zwraca true jak jest unikatowe, czyli nic innego na liscie nie ma takiego ID
        bool delete_id(int);            ///usuwa  obiekty o podanym id, zwraca bool (true jak cos usunal, false jak nic nie usunal)

    public:
        ~Library();
        static Library* getInstance();      ///metoda zwracajaca adres instancji biblioteki
        void add_to_library(Issue*);        ///metoda dodajaca element do biblioteki
        vector<Issue*> search_by(int, int, string);  ///metoda agregujaca poszczegolne metody szukania po konkretnych parametrach
};


class OperationStack
{
    ///klasa odpowiedzialna za zapisywanie danych o operacjach wykonanych w programie
    private:
        static vector<string> operations;       ///pole zawierajace rekordy wydarzen
    public:
        void push(string);      ///umieszcza rekord na stosie
        string pull();          ///wyciaga rekord ze stosu
        vector<string> read();  ///zwraca wszystkie rekordy i je czysci
};



///funkcja pomocnicza stworzona z mysla o OperationStack
///type - rodzaj operacji
///message - tekst, ktory opisuje zapisana akcje
///issue_id - numer id rekordu, na ktorym zostala wykonana operacja
///parameter_1, parameter_2 - inne dane
string report_creator(int type, string message, int issue_id, string parameter_1="", string parameter_2="");

#endif // APPLICATION_H_INCLUDED
