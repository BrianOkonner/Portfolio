unit Sort;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  ComCtrls, StdCtrls, Menus;

type
  TForm1 = class(TForm)
   TabControl1 : TTabControl;
    memo1:Tmemo;
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    Button5: TButton;
    Button6: TButton;
    Label1: TLabel;
    procedure Button1Click(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure TabControl1Change(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button5Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
    procedure Button6Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;
implementation

 //uses input;
{$R *.DFM}


procedure TForm1.Button1Click(Sender: TObject);
begin
  memo1.Clear;
  label1.Visible:=true;
  case tabcontrol1.TabIndex of
    0:memo1.lines.LoadFromFile('���������� ��������.txt');
    1:memo1.lines.LoadFromFile('���������� �������.txt');
    2:memo1.lines.LoadFromFile('���������� �����.txt');
    3:memo1.lines.LoadFromFile('���������� �����.txt');
    4:memo1.lines.LoadFromFile('���������� ������.txt');
    5:memo1.lines.LoadFromFile('���������� �����.txt');
    6:memo1.lines.LoadFromFile('��.txt');
    7:memo1.lines.LoadFromFile('���������� ���������.txt');
    8:memo1.lines.LoadFromFile('���������� ��������.txt');

   end;
end;

procedure TForm1.FormCreate(Sender: TObject);
begin
  memo1.Clear;
  label1.Visible:=true;
  memo1.lines.LoadFromFile('���������� ��������.txt');
end;

procedure TForm1.TabControl1Change(Sender: TObject);
begin
  memo1.Clear;
  label1.Visible:=true;
  case tabcontrol1.TabIndex of
    0:memo1.lines.LoadFromFile('���������� ��������.txt');
    1:memo1.lines.LoadFromFile('���������� �������.txt');
    2:memo1.lines.LoadFromFile('���������� �����.txt');
    3:memo1.lines.LoadFromFile('���������� �����.txt');
    4:memo1.lines.LoadFromFile('���������� ������.txt');
    5:memo1.lines.LoadFromFile('���������� �����.txt');
    6:memo1.lines.LoadFromFile('��.txt');
    7:memo1.lines.LoadFromFile('���������� ���������.txt');
    8:memo1.lines.LoadFromFile('���������� ��������.txt');
   end;

end;

procedure TForm1.Button2Click(Sender: TObject);
begin
  halt;
end;

procedure TForm1.Button5Click(Sender: TObject);
begin
  memo1.Clear;
  label1.Visible:=false;
  case tabcontrol1.TabIndex of
    0:memo1.lines.LoadFromFile('�������� ��������.txt');
    1:memo1.lines.LoadFromFile('�������� ������.txt');
    2:memo1.lines.LoadFromFile('�������� �����.txt');
    3:memo1.lines.LoadFromFile('��������  �����.txt');
    4:memo1.lines.LoadFromFile('�������� ������.txt');
    5:memo1.lines.LoadFromFile('�������� ����.txt');
    6:memo1.lines.LoadFromFile('�������� ��.txt');
    7:memo1.lines.LoadFromFile('�������� �������.txt');
    8:memo1.lines.LoadFromFile('�������� ��������.txt');
   end;
end;


procedure TForm1.Button3Click(Sender: TObject);
begin
 MessageDlg('��������� ����������    '#13#10'Version 1.00',mtInformation,[mbOK],0);
end;

procedure TForm1.Button6Click(Sender: TObject);
begin
 MessageDlg('������ ��������� ������ ������ � �������� ����            '#13#10'1 ����, 4 ������'#13#10'����: ����'#13#10'������: �������'#13#10'��������� � ��������: ���������� ����������',mtInformation,[mbOK],0);
end;

end.
