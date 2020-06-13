//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <vector>
#include <string>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
        /// etykieta
        TLabel *Label1;
        void __fastcall FormShow(TObject *Sender);
private:	// User declarations

public:		// User declarations
        __fastcall TForm2(TComponent* Owner);
        AnsiString show; /// zmienna potrebna do komunikacji miedzy Unit1, a Unit2

};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
