object Form1: TForm1
  Left = 489
  Top = 288
  Width = 964
  Height = 679
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Scaled = False
  Visible = True
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object ComboBox1: TComboBox
    Left = 288
    Top = 176
    Width = 145
    Height = 21
    ItemHeight = 13
    TabOrder = 0
    Text = 'Wybierz typ rekordu'
    OnChange = ComboBox1Change
  end
  object ComboBox2: TComboBox
    Left = 288
    Top = 232
    Width = 145
    Height = 21
    ItemHeight = 13
    TabOrder = 1
    Text = 'Parametr wyszukiwania'
    OnChange = ComboBox2Change
  end
  object Button1: TButton
    Left = 168
    Top = 280
    Width = 177
    Height = 73
    Caption = 'Szukaj'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button3: TButton
    Left = 744
    Top = 496
    Width = 75
    Height = 25
    Caption = 'Usu'#324
    TabOrder = 3
  end
  object Button2: TButton
    Left = 632
    Top = 496
    Width = 75
    Height = 25
    Caption = 'Wypo'#380'ycz'
    TabOrder = 4
    OnClick = Button2Click
  end
  object Button4: TButton
    Left = 520
    Top = 496
    Width = 75
    Height = 25
    Caption = 'Poka'#380
    TabOrder = 5
    OnClick = Button4Click
  end
  object Edit1: TEdit
    Left = 128
    Top = 232
    Width = 121
    Height = 21
    TabOrder = 6
    OnChange = Edit1Change
  end
  object ListBox1: TListBox
    Left = 488
    Top = 104
    Width = 361
    Height = 353
    ItemHeight = 13
    TabOrder = 7
    OnClick = ListBox1Click
  end
  object Button5: TButton
    Left = 168
    Top = 384
    Width = 177
    Height = 73
    Caption = 'Poka'#380' wszystkie rekordy'
    TabOrder = 8
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 64
    Top = 552
    Width = 201
    Height = 57
    Caption = 'Ostatnia operacja'
    TabOrder = 9
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 584
    Top = 544
    Width = 177
    Height = 57
    Caption = 'Dodaj egzemplarz'
    TabOrder = 10
    OnClick = Button7Click
  end
  object Button8: TButton
    Left = 280
    Top = 552
    Width = 201
    Height = 57
    Caption = 'Wyswietl ca'#322#261' histori'#281
    TabOrder = 11
    OnClick = Button8Click
  end
end
