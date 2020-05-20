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
        ~Library();
        static Library* getInstance();///funkcja zwracajaca adres instancji biblioteki
        void add_to_library(Issue*);
        vector<Issue*> search_by();
        void showAssets();
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
