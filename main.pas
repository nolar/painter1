UNIT main;

INTERFACE

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  ExtCtrls, StdCtrls, Grids, Menus, CLipBrd;

type
  TMainWin = class(TForm)
    PicturePanel: TPanel;
    PaintPanel: TPanel;
    PaintBox: TPaintBox;
    PictureName: TComboBox;
    Popup: TPopupMenu;
    CopyItem: TMenuItem;
    SaveItem: TMenuItem;
    SaveDialog: TSaveDialog;
    procedure FormCreate(Sender: TObject);
    procedure PaintBoxPaint(Sender: TObject);
    procedure PictureNameChange(Sender: TObject);
    procedure FormResize(Sender: TObject);
    procedure CopyItemClick(Sender: TObject);
    procedure SaveItemClick(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
    procedure drawPaintBox;
  end;

var
  MainWin: TMainWin;

function minabs(a,b:extended):extended;
function maxabs(a,b:extended):extended;
function tan(x:extended):extended;
function ctan(x:extended):extended;
function sign(x:extended):extended;
function pow(x,p:extended):extended;


IMPLEMENTATION


type
  TSymmetry=(symNone,symVertical,symHorizontal,symZero);
  TBorderAction=(baFrac,baCut);
  TCalculateProc=procedure(x,y,a,d:extended; var r,g,b:extended);
const
  M=1e-4;
{$I func.inc}
{$I list.inc}

function minabs(a,b:extended):extended;
 begin if(abs(a)<abs(b))then result:=a else result:=b end;
function maxabs(a,b:extended):extended;
 begin if(abs(a)>abs(b))then result:=a else result:=b end;
function tan(x:extended):extended;
 begin result:=sin(x)/cos(x) end;
function ctan(x:extended):extended;
 begin result:=cos(x)/sin(x) end;
function sign(x:extended):extended;
 begin if(x<>0)then result:=x/abs(x) else result:=0 end;
function pow(x,p:extended):extended;
 begin result:=exp(p*ln(x)) end;

{$R *.DFM}

procedure TMainWin.drawPaintBox;
var sym:TSymmetry;
    ba:TBorderAction;
    cx,cy,sx,sy,x,y,i:integer;
    xc,yc,rc,gc,bc:extended;
    tc:TColor;
begin
 i:=PictureName.itemIndex+1;
 if(i=0)then exit;
 caption:=PicturesName[i]+' - Художник';
 cx:=PaintBox.width div 2;
 cy:=PaintBox.height div 2;

 sym:=PicturesSymmetry[i]; ba:=PicturesBorder[i];
 sx:=0; sy:=0;
 case(sym)of
  symHorizontal:sy:=cy;
  symVertical:sx:=cx;
  symZero:begin
           sx:=cx;
           sy:=cy;
          end;
 end;

 for x:=sx to PaintBox.width-1 do
  for y:=sy to PaintBox.height-1 do
   begin
    xc:=maxabs((x-cx)/cx,M); yc:=maxabs((y-cy)/cy,M);
    rc:=0; gc:=0; bc:=0;
    if(@PicturesCalculate[i]<>nil)then PicturesCalculate[i](xc,yc,maxabs(arctan(yc/xc),M),sqrt((sqr(xc)+sqr(yc))/2) , rc,gc,bc);
    case(ba)of
     baFrac:begin
             rc:=abs(frac(rc));
             gc:=abs(frac(gc));
             bc:=abs(frac(bc));
            end;
     baCut:begin
            if(rc>1)then rc:=1;
            if(rc<0)then rc:=0;
            if(gc>1)then gc:=1;
            if(gc<0)then gc:=0;
            if(bc>1)then bc:=1;
            if(bc<0)then bc:=0;
           end;
    end;
    tc:=rgb(trunc(rc*$ff),trunc(gc*$ff),trunc(bc*$ff));
    PaintBox.canvas.pixels[x,y]:=tc;
    case(sym)of
     symHorizontal   :PaintBox.canvas.pixels[     x,2*cy-y]:=tc;
     symVertical     :PaintBox.canvas.pixels[2*cx-x,     y]:=tc;
     symZero         :begin
                       PaintBox.canvas.pixels[     x,2*cy-y]:=tc;
                       PaintBox.canvas.pixels[2*cx-x,     y]:=tc;
                       PaintBox.canvas.pixels[2*cx-x,2*cy-y]:=tc;
                      end;
    end;
   end;
end;


procedure TMainWin.FormCreate(Sender: TObject);
var i:integer;
begin
 for i:=1 to PicturesCount do
  PictureName.items.add(PicturesName[i]);
 PictureName.itemIndex:=PicturesDefault-1;
end;

procedure TMainWin.PaintBoxPaint(Sender: TObject);
begin
 drawPaintBox;
end;

procedure TMainWin.PictureNameChange(Sender: TObject);
begin
 PaintBox.invalidate;
end;

procedure TMainWin.FormResize(Sender: TObject);
begin
 PictureName.width:=PicturePanel.width-10-PictureName.left;
end;

procedure TMainWin.CopyItemClick(Sender: TObject);
var b:TBitmap;
    r:TRect;
begin
 b:=TBitmap.create;
 b.width:=PaintBox.width;
 b.height:=PaintBox.height;

 r.left:=0;
 r.top:=0;
 r.right:=PaintBox.width;
 r.bottom:=PaintBox.height;
 b.canvas.copyrect(r,PaintBox.canvas,r);

 clipboard.assign(b);

 b.free;
end;

procedure TMainWin.SaveItemClick(Sender: TObject);
var b:TBitmap;
    r:TRect;
begin
 if(SaveDialog.execute)then
  begin
   b:=TBitmap.create;
   b.width:=PaintBox.width;
   b.height:=PaintBox.height;

   r.left:=0;
   r.top:=0;
   r.right:=PaintBox.width;
   r.bottom:=PaintBox.height;
   b.canvas.copyrect(r,PaintBox.canvas,r);

   b.savetofile(SaveDialog.filename);

   b.free;
  end;
end;

end.
