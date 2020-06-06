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
        void read_from_file(const char*); ///czyta zawartosc pliku data.csv i zapisuje ja do vektora issues
        void save_to_file(const char*);
        vector<Issue*> search_by_name(string);  ///szuka po imieniu, skladowa szukania ogolnego
        vector<Issue*> search_by_surname(string);
        vector<Issue*> search_by_id(int);
        vector<Issue*> search_by_title(string);
        vector<Issue*> search_by_year(int);
        vector<Issue*> search_by_pages(int);
        vector<Issue*> search_by_publisher(string);
        vector<Issue*> search_by_number(int);
        vector<Issue*> search_by_discipline(string);
        vector<Issue*> search_by_format(string);
        vector<Issue*> getIssues();
        void clear();
        bool is_unique_id(int);     ///zwraca true jak jest unikatowe, czyli nic innego na liscie nie ma takiego id
        bool delete_id(int);  ///usuwa  obiekt(y)? o podanym id, zwraca bool (true jak cos usunal, false jak nic nie usunal)
        //vector<Issue*> getLastResults();
        //void assign_results(vector<Issue*>);
        ///jest szukanie po kazdej rzeczy standardowej, teraz trzeba special

    public:
        ~Library(); ///nie wiem czy dobrze zwalniam pamiec
        static Library* getInstance();///funkcja zwracajaca adres instancji biblioteki
        void add_to_library(Issue*);
        vector<Issue*> search_by(int, int, string);  ///grupuje wszystkie poszczegulne seawrch by
};


class OperationStack
{
    ///klasa odpowiedzialna za zapisywanie danych o operacjach wykonanych w programie
    private:
        static vector<string> operations;
    public:
        void push(string);
        string pull();
        vector<string> read();
};



///funkcja pomocnicza stworzona z mysla o OperationStack
///type - rodzaj operacji
///message - tekst, ktory opisuje zapisana akcje
///issue_id - numer id rekordu, na ktorym zostala wykonana operacja
///parameter_1, parameter_2 - inne dane
string report_creator(int type, string message, int issue_id, string parameter_1="", string parameter_2="");

#endif // APPLICATION_H_INCLUDED
