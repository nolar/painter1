program painter;

uses
  Forms,
  main in 'main.pas' {MainWin};

{$R *.RES}

begin
  Application.Initialize;
  Application.CreateForm(TMainWin, MainWin);
  Application.Run;
end.
