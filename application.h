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
    public:
        vector<Issue*> last_results;                                 ///tymczasowo publiczne do testowania
        void read_from_file(); ///czyta zawartosc pliku data.csv i zapisuje ja do vektora issues
        void save_to_file();
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
        //vector<Issue*> getLastResults();
        //void assign_results(vector<Issue*>);
        ///jest szukanie po kazdej rzeczy standardowej, teraz trzeba special

    public:
        ~Library(); ///nie wiem czy dobrze zwalniam pamiec
        static Library* getInstance();///funkcja zwracajaca adres instancji biblioteki
        void add_to_library(Issue*);
        vector<Issue*> search_by(int, int, string);  ///grupuje wszystkie poszczegulne seawrch by
        void showAssets();  ///nie dzialal, program sie zapetlal, poprawilem
};


class OperationStack
{
    ///klasa odpowiedzialna za zapisywanie danych o operacjach wykonanych w programie
    private:
        vector<string> operations;
    public:
        void push(string);
        string pull();
        vector<string> read();
};

#endif // APPLICATION_H_INCLUDED
