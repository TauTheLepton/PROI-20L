//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
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
