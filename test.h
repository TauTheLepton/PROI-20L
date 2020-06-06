#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

void make_library();        ///funkcja pomocnicza do testow tworzaca podstawowa biblioteke
void book();                ///test sprawdzajacy dzialanie konstruktora klasy Book
void audiobook();           ///test sprawdzajacy dzialanie konstruktora klasy Audiobook
void magazine();            ///test sprawdzajacy dzialanie konstruktora klasy Magazine
void scientific_work();     ///test sprawdzajacy dzialanie konstruktora klasy ScientificWork
void issues();              ///test sprawdzajacy dodawanie obiektow do biblioteki i czytanie ich
void write_read();          ///test sprawdzajacy czytanie i zapisywanie do pliku
void _search();             ///test sprawdzajacy mechanizmy szukania po konkretnych parametrach
void _unique();             ///test sprawdzajacy mechanizm sprawdzania czy numer ID jest unikalny
void id();                  ///test sprawdzajacy mechanizm usuwania obiektow po ID z biblioteki
void exception_0();         ///test sprawdzajacy obsluge wyjatku numer 0 (funkcji czytania z pliku)
void exception_1();         ///test sprawdzajacy obsluge wyjatku numer 1 (funkcji czytania z pliku)
void exception_2();         ///test sprawdzajacy obsluge wyjatku numer 2 (funkcji czytania z pliku)
void exception_3();         ///test sprawdzajacy obsluge wyjatku numer 3 (funkcji czytania z pliku)
void exception_4();         ///test sprawdzajacy obsluge wyjatku numer 4 (funkcji czytania z pliku)
void exception_6();         ///test sprawdzajacy obsluge wyjatku numer 6 (funkcji czytania z pliku)

#endif // TEST_H_INCLUDED
