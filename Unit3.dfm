object Form3: TForm3
  Left = 503
  Top = 321
  Width = 531
  Height = 574
  Caption = 'Dodaj egzemplarz'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object LabeledEdit1: TLabeledEdit
    Left = 40
    Top = 48
    Width = 169
    Height = 21
    EditLabel.Width = 45
    EditLabel.Height = 13
    EditLabel.Caption = 'Numer ID'
    Enabled = False
    LabelPosition = lpAbove
    LabelSpacing = 3
    TabOrder = 0
  end
  object LabeledEdit2: TLabeledEdit
    Left = 40
    Top = 96
    Width = 169
    Height = 21
    EditLabel.Width = 25
    EditLabel.Height = 13
    EditLabel.Caption = 'Tytu'#322
    Enabled = False
    LabelPosition = lpAbove
    LabelSpacing = 3
    TabOrder = 1
  end
  object LabeledEdit3: TLabeledEdit
    Left = 40
    Top = 144
    Width = 169
    Height = 21
    EditLabel.Width = 52
    EditLabel.Height = 13
    EditLabel.Caption = 'Imi'#281' autora'
    Enabled = False
    LabelPosition = lpAbove
    LabelSpacing = 3
    TabOrder = 2
  end
  object LabeledEdit4: TLabeledEdit
    Left = 40
    Top = 192
    Width = 169
    Height = 21
    EditLabel.Width = 79
    EditLabel.Height = 13
    EditLabel.Caption = 'Nazwisko autora'
    Enabled = False
    LabelPosition = lpAbove
    LabelSpacing = 3
    TabOrder = 3
  end
  object LabeledEdit5: TLabeledEdit
    Left = 40
    Top = 240
    Width = 169
    Height = 21
    EditLabel.Width = 62
    EditLabel.Height = 13
    EditLabel.Caption = 'Rok wydania'
    Enabled = False
    LabelPosition = lpAbove
    LabelSpacing = 3
    TabOrder = 4
  end
  object LabeledEdit6: TLabeledEdit
    Left = 40
    Top = 432
    Width = 169
    Height = 21
    EditLabel.Width = 158
    EditLabel.Height = 13
    EditLabel.Caption = 'Liczba stron/d'#322'ugosc w minutach'
    Enabled = False
    LabelPosition = lpAbove
    LabelSpacing = 3
    TabOrder = 5
  end
  object LabeledEdit7: TLabeledEdit
    Left = 40
    Top = 336
    Width = 169
    Height = 21
    EditLabel.Width = 48
    EditLabel.Height = 13
    EditLabel.Caption = 'Wydawca'
    Enabled = False
    LabelPosition = lpAbove
    LabelSpacing = 3
    TabOrder = 6
  end
  object LabeledEdit8: TLabeledEdit
    Left = 40
    Top = 480
    Width = 169
    Height = 21
    EditLabel.Width = 32
    EditLabel.Height = 13
    EditLabel.Caption = 'Format'
    Enabled = False
    LabelPosition = lpAbove
    LabelSpacing = 3
    TabOrder = 7
  end
  object LabeledEdit9: TLabeledEdit
    Left = 40
    Top = 288
    Width = 169
    Height = 21
    EditLabel.Width = 31
    EditLabel.Height = 13
    EditLabel.Caption = 'Numer'
    Enabled = False
    LabelPosition = lpAbove
    LabelSpacing = 3
    TabOrder = 8
  end
  object LabeledEdit10: TLabeledEdit
    Left = 40
    Top = 384
    Width = 169
    Height = 21
    EditLabel.Width = 93
    EditLabel.Height = 13
    EditLabel.Caption = 'Dziedzina naukowa'
    Enabled = False
    LabelPosition = lpAbove
    LabelSpacing = 3
    TabOrder = 9
  end
  object Button1: TButton
    Left = 256
    Top = 312
    Width = 225
    Height = 113
    Caption = 'Dodaj do biblioteki'
    TabOrder = 10
  end
  object ComboBox1: TComboBox
    Left = 288
    Top = 88
    Width = 145
    Height = 21
    ItemHeight = 13
    TabOrder = 11
    Text = 'Wybierz typ'
    OnChange = ComboBox1Change
  end
end
