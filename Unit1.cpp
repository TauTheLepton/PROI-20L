//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include <vector>
#include "application.h"
#include "elements.h"
#include <iostream>
#include <sstream>
#include <typeinfo>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
OperationStack stack;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
        /// Inicjuje okno oraz wczytuje dane
        Library* g = Library::getInstance();
        try
        {
                g->read_from_file("data.csv");
        }
        catch (int t)
        {
                /// Obsluga wyjatkow, w zaleznosci od typu bledu, wyswietlany
                /// jest stosowny komunikat, a aplikacja jest zamykana.

                if(t==0)
                {
                        ShowMessage("W pliku wejsciowym podano niepoprawna deklaracje statusu wypozyczenia w jednym z rekordow.");
                        Application->Terminate();
                }
                else if(t==1)
                {
                        ShowMessage("W pliku wejsciowym podano niepoprawna deklaracje numeru ID w jednym z rekordow.");
                        Application->Terminate();
                }
                else if(t==2)
                {
                        ShowMessage("W pliku wejsciowym podano niepoprawna deklaracje roku wydania w jednym z rekordow.");
                        Application->Terminate();
                }
                else if(t==3)
                {
                        ShowMessage("W pliku wejsciowym podano niepoprawna deklaracje ilosci stron w jednym z rekordow");
                        Application->Terminate();
                }
                else if(t==4)
                {
                        ShowMessage("W pliku wejsciowym podano niepoprawna deklaracje parametru specjalnego w jednym z rekordow.");
                        Application->Terminate();
                }
                else if(t==5)
                {
                        ShowMessage("Nie mozna otworzyc pliku wejsciowego.");
                        Application->Terminate();
                }
                else if(t==6)
                {
                        ShowMessage("Numery ID nie sa unikalne.");
                        Application->Terminate();
                }
        }
        stack.push("Wczytano dane z pliku");

        ComboBox1->Items->Add("Dowolny");
        ComboBox1->Items->Add("Ksi¹¿ka");
        ComboBox1->Items->Add("Czasopismo");
        ComboBox1->Items->Add("Praca naukowa");
        ComboBox1->Items->Add("Audiobook");

        ComboBox2->Enabled = false;
        Edit1->Enabled = false;
        Button1->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
        /// funkcja, ktora zmienia zmienia zawartosc drugiej listy rozwijanej
        /// w zaleznosci od pierwszej

        ComboBox2->Enabled = true;
        ComboBox2->Clear();
        ComboBox2->Text = "Parametr wyszukiwania";
        ComboBox2->Items->Add("Numer ID");
        ComboBox2->Items->Add("Tytu³");
        ComboBox2->Items->Add("Imiê autora");
        ComboBox2->Items->Add("Nazwisko autora");
        ComboBox2->Items->Add("Rok wydania");
        ComboBox2->Items->Add("Wydawca");

        if (ComboBox1->ItemIndex == 1)
        {
                ComboBox2->Items->Add("Liczba stron");
        }

        else if (ComboBox1->ItemIndex == 2)
        {
                ComboBox2->Items->Add("Liczba stron");
                ComboBox2->Items->Add("Numer czasopisma");
        }

        else if (ComboBox1->ItemIndex == 3)
        {
                ComboBox2->Items->Add("Liczba stron");
                ComboBox2->Items->Add("Dziedzina naukowa");
        }

        else if (ComboBox1->ItemIndex == 4)
        {
                ComboBox2->Items->Add("D³ugosc w minutach");
                ComboBox2->Items->Add("Format pliku");
        }

}


//---------------------------------------------------------------------------



void __fastcall TForm1::ComboBox2Change(TObject *Sender)
{
        Edit1->Enabled = true;
}
//---------------------------------------------------------------------------




void __fastcall TForm1::Button5Click(TObject *Sender)
{
        Library* g  = Library::getInstance();

        stack.push("Pokazano wszystkie rekordy");

        ListBox1->Clear();

        vector <Issue*> issues = g->getIssues();

        for(int x = 0; x<issues.size(); x++)
        {
                ListBox1->Items->Add(issues[x]->get_caption().c_str());
        }

        Form1->res = issues;

        /// gdy lista wynikow jest pusta, blokuje przyciski do operacji na rekordach,
        /// zeby nie dopuscic do bledu krytycznego
        if(Form1->res.size() == 0)
        {
                Button3->Enabled = false;
                Button2->Enabled = false;
                Button4->Enabled = false;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        /// przycisk sluzacy do wyszukiwania

        Library* g = Library::getInstance();

        vector<Issue*> results;
        ListBox1->Clear();

        int t = ComboBox1->ItemIndex; ///w tej zmiennej zapisuje ktora opcje
                                      ///wybralem w pierwszym checkboxie
        int p = ComboBox2->ItemIndex; ///analogicznie jak w pierwszym przypadku

        string message = "Wyszukiwano rekordow z kategorii: ";
        string element_1 =  ComboBox1->Text.c_str();
        string element_2 =  ComboBox2->Text.c_str();

        string report = report_creator(2,message,0,element_1,element_2);

        stack.push(report);

        if(t == 0)
        {
                if (p == 0 || p == 4)
                {
                        int input;
                        stringstream in(Edit1->Text.c_str());
                        in >> input;

                        results = g->search_by(p,input,"null");
                }
                else
                {
                        string input = Edit1->Text.c_str();
                        results = g->search_by(p,0,input);
                }
         }

         else if(t == 1)
         {
                vector<Issue*> results2;

                if (p == 0 || p == 4 || p == 6)
                {
                        int input;
                        stringstream in(Edit1->Text.c_str());
                        in >> input;

                        results2 = g->search_by(p,input,"null");
                }
                else
                {
                        string input = Edit1->Text.c_str();
                        results2 = g->search_by(p,0,input);
                }

                for(int i = 0; i<results2.size(); i++)
                {
                        string type = typeid(*results2[i]).name();
                        if(type == "Book")
                        {
                                results.push_back(results2[i]);
                        }
                }
           }

         else if(t == 2)
         {
               vector<Issue*> results2;

                if (p == 0 || p == 4 || p == 6 || p == 7)
                {
                        int input;
                        stringstream in(Edit1->Text.c_str());
                        in >> input;

                        results2 = g->search_by(p,input,"null");
                }
                else
                {
                        string input = Edit1->Text.c_str();
                        results2 = g->search_by(p,0,input);
                }

                for(int i = 0; i<results2.size(); i++)
                {
                        string type = typeid(*results2[i]).name();
                        if(type == "Magazine")
                        {
                                results.push_back(results2[i]);
                        }
                }

            }

            else if(t == 3)
            {
                vector<Issue*> results2;

                if(p == 7)
                {
                        p = 8;
                }

                if (p == 0 || p == 4 || p == 6)
                {
                        int input;
                        stringstream in(Edit1->Text.c_str());
                        in >> input;

                        results2 = g->search_by(p,input,"null");
                }
                else
                {
                        string input = Edit1->Text.c_str();
                        results2 = g->search_by(p,0,input);
                }

                for(int i = 0; i<results2.size(); i++)
                {
                        string type = typeid(*results2[i]).name();
                        if(type == "ScientificWork")
                        {
                                results.push_back(results2[i]);
                        }
                }

             }

             else if(t == 4)
             {
                vector<Issue*> results2;

                if(p == 7)
                {
                        p = 9;
                }

                if (p == 0 || p == 4 || p == 6)
                {
                        int input;
                        stringstream in(Edit1->Text.c_str());
                        in >> input;

                        results2 = g->search_by(p,input,"null");
                }
                else
                {
                        string input = Edit1->Text.c_str();
                        results2 = g->search_by(p,0,input);
                }

                for(int i = 0; i<results2.size(); i++)
                {
                        string type = typeid(*results2[i]).name();
                        if(type == "Audiobook")
                        {
                                results.push_back(results2[i]);
                        }
                }

              }

        Form1->res = results;

        /// dodaje ksiazki do listy wynikow
        for(int i=0;i<Form1->res.size();i++)
        {
                ListBox1->Items->Add(Form1->res[i]->get_caption().c_str());
        }

        if(Form1->res.size() == 0)
        {
                Button3->Enabled = false;
                Button2->Enabled = false;
                Button4->Enabled = false;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit1Change(TObject *Sender)
{
        /// metoda blokujaca przycisk do szukania, gdy nie podano zadnych danych
        /// do pola tekstowego

        if(Edit1->Text=="")
        {
                Button1->Enabled = false;
        }

        else
        {
                Button1->Enabled = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
        /// przycisk do wyswietlania informacji o rekordzie

        Library* g = Library::getInstance();
        int a = ListBox1->ItemIndex;
        ShowMessage(Form1->res[a]->get_info().c_str());

        string message = "Wyswietlono informacje o egzemplarzu o sygnaturze";
        string report = report_creator(1, message, Form1->res[a]->get_id());

        stack.push(report);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
        ///przycisk pokazujacy ostatnia operacje

        ShowMessage(stack.pull().c_str());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
       /// metoda zapisujaca dane, podczas zamykania programu

       Library* g = Library::getInstance();

       g->save_to_file("data.csv");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
        /// przycisk, ktorym wypozyczamy/zwracamy ksiazke

        Library* g = Library::getInstance();

        int a = ListBox1->ItemIndex;

        Form1->res[a]->change_status();
        bool status = Form1->res[a]->get_is_available();

        Button2->Caption = status?"Wypozycz":"Zwroc";

        string message;

        if(status == false)
        {
                message = "Wypozyczono egzemplarz o sygnaturze:";
        }
        else
        {
                message = "Oddano egzemplarz o sygnaturze:";
        }

        string report = report_creator(1,message,Form1->res[a]->get_id());
        stack.push(report);

}
//---------------------------------------------------------------------------


void __fastcall TForm1::ListBox1Click(TObject *Sender)
{

        if(ListBox1->ItemIndex == -1)
        {
                Button3->Enabled = false;
                Button2->Enabled = false;
                Button4->Enabled = false;
        }

        else
        {
                Button3->Enabled = true;
                Button2->Enabled = true;
                Button4->Enabled = true;
        }

        int a = ListBox1->ItemIndex;
        bool status = Form1->res[a]->get_is_available();
        Button2->Caption = status?"Wypozycz":"Zwroc";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
        /// przycisk do wyswietlania kreatora egzemplarza

        Form3->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
        /// przycisk do wyswietlania historii operacji

        vector<string> reports = stack.read();

        AnsiString ehhh;

        ///Nie jestem dumny z tego rozwiazania, ale to byla jedyna mozliwosc
        for(int i=0;i<reports.size();i++)
        {
                ehhh += (reports[i]+"\n").c_str();
        }

        Form2->show = ehhh;

        Form2->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
        ///Przycisk do usuwania egzemplarzy
        Library* g = Library::getInstance();
        int a = ListBox1->ItemIndex;

        int id_to_delete =  res[a]->get_id();

        bool is_deleted = g->delete_id(id_to_delete);

        if(is_deleted)
        {
                ListBox1->Items->Delete(a);

                string message = "Usunieto rekord o sygnaturze:";
                string report = report_creator(1,message,id_to_delete);
                stack.push(report);
        }
        else
        {
                ShowMessage("Tsoooo???");
        }
}
//---------------------------------------------------------------------------


