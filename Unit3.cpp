//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "application.h"
#include "elements.h"
#include <ctype.h>
#include <string>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
OperationStack stack3;
//---------------------------------------------------------------------------

bool is_num(AnsiString s)
{
        /// funkcja pomocnicza do sprawdzania, czy wartość tekstowa jest liczbą

        for(int i=1;i<=s.Length();i++)
        {
              if (!isdigit(s[i]))
              {
                      return false;
              }
        }
        return true;
}

//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
        : TForm(Owner)
{
        ComboBox1->Items->Add("Ksi¹¿ka");
        ComboBox1->Items->Add("Czasopismo");
        ComboBox1->Items->Add("Praca naukowa");
        ComboBox1->Items->Add("Audiobook");
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------

void __fastcall TForm3::ComboBox1Change(TObject *Sender)
{
        /// kod wykonujacy sie, gdy zmieniamy pozycje w liscie rozwijanej

        LabeledEdit1->Enabled = true;
        LabeledEdit2->Enabled = true;
        LabeledEdit3->Enabled = true;
        LabeledEdit4->Enabled = true;
        LabeledEdit5->Enabled = true;
        LabeledEdit6->Enabled = true;
        LabeledEdit7->Enabled = true;
        LabeledEdit8->Enabled = false;
        LabeledEdit9->Enabled = false;
        LabeledEdit10->Enabled = false;
        int a = ComboBox1->ItemIndex;

        if(a == 1)
        {
                LabeledEdit9->Enabled = true;
        }
        else if(a == 2)
        {
                LabeledEdit10->Enabled = true;
        }
        else if(a == 3)
        {
                LabeledEdit8->Enabled = true;
        }
}
//---------------------------------------------------------------------------


void __fastcall TForm3::Button1Click(TObject *Sender)
{
        Library* lib = Library::getInstance();

        /// zapisuje dane wpisane w polach tekstowych

        AnsiString id = LabeledEdit1->Text;
        AnsiString title = LabeledEdit2->Text;
        AnsiString name = LabeledEdit3->Text;
        AnsiString surname = LabeledEdit4->Text;
        AnsiString year = LabeledEdit5->Text;
        AnsiString number = LabeledEdit9->Text;
        AnsiString publisher = LabeledEdit7->Text;
        AnsiString discipline = LabeledEdit10->Text;
        AnsiString pages = LabeledEdit6->Text;
        AnsiString format = LabeledEdit8->Text;

        /// sprawdzam obecnie wybrana pozycje w liscie rozwijanej
        /// (sprawdzam wybrany typ danych)
        int a = ComboBox1->ItemIndex;

        /// zmienne, ktore sygnalizuja, czy podane dane liczbowe sa poprawne
        bool id_c = is_num(id);
        bool year_c = is_num(year);
        bool pages_c = is_num(pages);
        bool number_c = is_num(number);

        /// sprawdzam, czy odpowiednie pola sa wypelnione
        if(a==0 && id!="" && title!="" && name!="" && surname!="" && year!="" && publisher!="" && pages!="")
        {
             /// sprawdzam, czy ponizsze wartosci sa liczbami, jesli tak, procedura bedzie kontynuowana
             if(id_c && year_c && pages_c)
             {
                        /// teraz sprawdzamy, czy numer ID jest unikalny

                        int id_ = atoi(id.c_str());
                        if(lib->is_unique_id(id_))
                        {
                                int year_ = atoi(year.c_str());
                                int pages_ = atoi(pages.c_str());

                                Book* b = new Book(id_,title.c_str(),name.c_str(),surname.c_str(),year_,pages_,publisher.c_str(),true);
                                lib->add_to_library(b);

                                string message = "Dodano do biblioteki egzemplarz o sygnaturze: ";
                                string report = report_creator(1, message, id_);

                                stack3.push(report);

                                Form3->Close();
                        }
                        else
                        {
                                ShowMessage("ID nie jest unikalne!");
                        }
             }
             else
             {
                        ShowMessage("Podano nieprawidlowe dane liczbowe!");
             }
        }
        else if(a==1 && id!="" && title!="" && name!="" && surname!="" && year!="" && publisher!="" && pages!="" && number!="")
        {
             /// sprawdzam, czy ponizsze wartosci sa liczbami, jesli tak, procedura bedzie kontynuowana
             if(id_c && year_c && pages_c && number_c)
             {

                        /// teraz sprawdzamy, czy numer ID jest unikalny

                        int id_ = atoi(id.c_str());
                        if(lib->is_unique_id(id_))
                        {
                                int year_ = atoi(year.c_str());
                                int pages_ = atoi(pages.c_str());
                                int number_ = atoi(number.c_str());

                                Magazine* m = new Magazine(id_,title.c_str(),name.c_str(),surname.c_str(),year_,pages_,publisher.c_str(),number_,true);
                                lib->add_to_library(m);

                                string message = "Dodano do biblioteki egzemplarz o sygnaturze: ";
                                string report = report_creator(1, message, id_);

                                stack3.push(report);

                                Form3->Close();
                        }
                        else
                        {
                                ShowMessage("ID nie jest unikalne!");
                        }
             }
             else
             {
                        ShowMessage("Podano nieprawidlowe dane liczbowe!");
             }
        }
        else if(a==2 && id!="" && title!="" && name!="" && surname!="" && year!="" && publisher!="" && pages!="" && discipline!="")
        {
             /// sprawdzam, czy ponizsze wartosci sa liczbami, jesli tak, procedura bedzie kontynuowana
             if(id_c && year_c && pages_c)
             {
                        /// teraz sprawdzamy, czy numer ID jest unikalny

                        int id_ = atoi(id.c_str());
                        if(lib->is_unique_id(id_))
                        {
                                int year_ = atoi(year.c_str());
                                int pages_ = atoi(pages.c_str());

                                ScientificWork* s = new ScientificWork(id_,title.c_str(),name.c_str(),surname.c_str(),year_,pages_,publisher.c_str(),discipline.c_str(),true);
                                lib->add_to_library(s);

                                string message = "Dodano do biblioteki egzemplarz o sygnaturze: ";
                                string report = report_creator(1, message, id_);

                                stack3.push(report);

                                Form3->Close();
                        }
                        else
                        {
                                ShowMessage("ID nie jest unikalne!");
                        }
             }
             else
             {
                        ShowMessage("Podano nieprawidlowe dane liczbowe!");
             }
        }
        else if(a==3 && id!="" && title!="" && name!="" && surname!="" && year!="" && publisher!="" && pages!="" && format!="")
        {
             /// sprawdzam, czy ponizsze wartosci sa liczbami, jesli tak, procedura bedzie kontynuowana
             if(id_c && year_c && pages_c)
             {
                        /// teraz sprawdzamy, czy numer ID jest unikalny

                        int id_ = atoi(id.c_str());
                        if(lib->is_unique_id(id_))
                        {
                                int year_ = atoi(year.c_str());
                                int pages_ = atoi(pages.c_str());

                                Audiobook* au = new Audiobook(id_,title.c_str(),name.c_str(),surname.c_str(),year_,pages_,publisher.c_str(),format.c_str(),true);
                                lib->add_to_library(au);

                                string message = "Dodano do biblioteki egzemplarz o sygnaturze: ";
                                string report = report_creator(1, message, id_);

                                stack3.push(report);

                                Form3->Close();
                        }
                        else
                        {
                                ShowMessage("ID nie jest unikalne!");
                        }
             }
             else
             {
                        ShowMessage("Podano nieprawidlowe dane liczbowe!");
             }
        }
        else
        {
                ShowMessage("Niektore pole wciaz sa puste!");
        }




}
//---------------------------------------------------------------------------

