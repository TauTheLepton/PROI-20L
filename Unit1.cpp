//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
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
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
        //
        Library* g = Library::getInstance();
        g->read_from_file();

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

        ListBox1->Clear();

        vector <Issue*> issues = g->getIssues();

        for(int x = 0; x<issues.size(); x++)
        {
                ListBox1->Items->Add(issues[x]->get_title().c_str());
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        Library* g = Library::getInstance();

        vector<Issue*> results;
        ListBox1->Clear();

        int t = ComboBox1->ItemIndex; ///w tej zmiennej zapisuje ktora opcje
                                      ///wybralem w pierwszym checkboxie
        int p = ComboBox2->ItemIndex; ///analogicznie jak w pierwszym przypadku

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

        for(int w = 0; w<results.size(); w++)
        {
                ListBox1->Items->Add(results[w]->get_title().c_str());
        }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit1Change(TObject *Sender)
{
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

