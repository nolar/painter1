//================================================================
//  Здесь описываются функции, по которым рисуются картины
//  При добавлении новой функции не забудьте изменить Pictures*
//----------------------------------------------------------------
//    Способ такой:
// 1. Регистрация процедуры: задается тип симметрии и способ обработки
//    выходов за пределы промежутка цвета
// 2. Описание процедыры: по декартовым и полярным координатам
//    возвращаются процентные значения красного, зеденого и синего
//----------------------------------------------------------------
//    Типы симметрии:
// - Относительно центра (symZero)
// - Относительно Ox (symHorizontal)
// - Относительно Oy (symVertical)
// + Никакой симметрии (symNone)
//----------------------------------------------------------------
//    Обработка выходов за края [0..1]:
// + Брать дробные части (baFractal)
// - Обрезать к 0 или 1 - к ближнему (baCut)
//================================================================
const D=M;

const f1c='Красно-синие обхватывающие друг друга полосы с элементами эротики';
      f1s=symZero; f1b=baCut;
procedure f1p(x,y,a,d:extended;var r,g,b:extended);
begin
 if(abs(x- sqr(ln(abs(cos(d*pi*1.1))+M)) )<D)then
  r:=1 else
  r:=0;
 if(abs(y- sqr(ln(abs(sin(d*pi*1.5))+M)) )<D)then
  b:=1 else
  b:=0;
 g:=(r+b)/2;
end;

const f2c='Муть. Просто, к тому же бесплатно :-)';
      f2s=symZero; f2b=baCut;
procedure f2p(x,y,a,d:extended;var r,g,b:extended);
begin
 r:=random*abs(sin(d*4*pi+0*pi/3));
 g:=random*abs(sin(d*4*pi+1*pi/3));
 b:=random*abs(sin(d*4*pi+2*pi/3));
end;

const f3c='Блики в центре и красно-синие окресности. Похоже на рождающуюся Вселенную';
      f3s=symZero; f3b=baCut;
procedure f3p(x,y,a,d:extended;var r,g,b:extended);
begin
 r:=pow(x/3,d);
 g:=1-d*2;
 b:=pow(y/3,d);
end;

const f4c='Синусоидоподобные линии. Ерунда многоцветная';
      f4s=symZero; f4b=baCut;
procedure f4p(x,y,a,d:extended;var r,g,b:extended);
begin
 g:=1-abs(x - sin(y*pi)/2);
 b:=1-abs(y - sin(x*pi)/2);
 r:=((1-b)+(1-g))/2;
end;

const f5c='Синяя четырехугольная звезда на красно-зеленых сочетаниях';
      f5s=symZero; f5b=baCut;
procedure f5p(x,y,a,d:extended;var r,g,b:extended);
const K=0.005;                    {Размер звезды пропорционален K}
begin
 r:=x*d;
 g:=y*d;
 b:=K/r/g;
end;

const f6c='Четырехлепестковый синий цветок';
      f6s=symZero; f6b=baCut;
procedure f6p(x,y,a,d:extended;var r,g,b:extended);
begin
 r:=x*d/y;
 g:=y*d/x;
 b:=((1-r)+(1-g))/2;
end;

const f7c='Так себе';
      f7s=symZero; f7b=baCut;
procedure f7p(x,y,a,d:extended;var r,g,b:extended);
begin
 r:=pow(x*2*d,y/d);
 g:=1-pow(y*2*d,x/d);
 b:=((1-r)+(1-g))/2;
end;

const f8c='Windows 99. Ромбовидное окно';
      f8s=symZero; f8b=baCut;
procedure f8p(x,y,a,d:extended;var r,g,b:extended);
begin
 r:=sin(x*y*pi*2)/d;
 g:=cos(x*y*pi*2)/d;
 b:=ln(abs(1-r-g)+M)/d;
end;

const f9c='Желтые блики';
      f9s=symZero; f9b=baCut;
procedure f9p(x,y,a,d:extended;var r,g,b:extended);
begin
 r:=pow(d/x*y,x*y);
 g:=pow(d/y*x,x*y);
 b:=sin(d*pi*4);
end;

const f10c='Волшебный цветочек. Может аленький';
      f10s=symZero; f10b=baCut;
procedure f10p(x,y,a,d:extended;var r,g,b:extended);
begin
 r:=pow(d/x*y,ln(x*y)/exp(x)/exp(y));
 g:=pow(d/y*x,ln(x*y)/exp(x)/exp(y));
 b:=sin(d*pi*4)/cos(d*pi*4);
end;

const f11c='Цветовые кресты';
      f11s=symZero; f11b=baCut;
procedure f11p(x,y,a,d:extended;var r,g,b:extended);
begin
 g:=y*x/d;
 b:=sqr(1-d);
 r:=1-g-b;
end;

const f12c='Многоцветик';
      f12s=symZero; f12b=baCut;
procedure f12p(x,y,a,d:extended;var r,g,b:extended);
begin
 g:=sqr(1-d)/y*x;
 b:=sqr(1-d)/x*y;
 r:=1-(g+b)/2;
end;

const f13c='Синий глаз';
      f13s=symZero; f13b=baCut;
procedure f13p(x,y,a,d:extended;var r,g,b:extended);
begin
 if(abs(y - 0.5/(x*2))<D)then
  r:=d else
  r:=1-d;
 g:=ln(x)*sin(r*pi);
 b:=ln(y)*cos(r*pi);
end;

const f14c='Точковатость';
      f14s=symZero; f14b=baCut;
procedure f14p(x,y,a,d:extended;var r,g,b:extended);
begin
 r:=d*abs(y - 0.5/(x/2));
 g:=y/exp(x)*sin(r*pi)/ln(y);
 b:=x/exp(y)*cos(r*pi)/ln(x);
end;

const f15c='Мишень';
      f15s=symZero; f15b=baCut;
procedure f15p(x,y,a,d:extended;var r,g,b:extended);
begin
 r:=cos(pi*sin(pi*x*y));
 g:=cos(pi*sin(pi/x/y));
 b:=tan(pi/2*ctan(pi/2*d));
end;

const f16c='Распятие';
      f16s=symZero; f16b=baCut;
procedure f16p(x,y,a,d:extended;var r,g,b:extended);
begin
 r:=x*y/d;
 g:=x*y/d;
 b:=(r*g)/d;
end;

const f17c='By Sergius';
      f17s=symZero; f17b=baFrac;
procedure f17p(x,y,a,d:extended;var r,g,b:extended);
begin
 r:=sin(exp(sin(x*y)*cos(x)))/d;
 g:=exp(sin(exp(sin(exp(cos(x*y)/(sin(x+y)))))))/d;
 b:=cos(exp(sin(r*g)))/d;
end;

const f18c='By Sergius';
      f18s=symZero; f18b=baFrac;
procedure f18p(x,y,a,d:extended;var r,g,b:extended);
begin
 r:=exp(sin(x*y)*cos(x))/d;
 g:=sin(exp(sin(exp(cos(x*y)/(sin(x+y))))))/d;
 b:=cos(exp(sin(r*g)))/d;
end;

const f19c='By Sergius бабочка-1';
      f19s=symZero; f19b=baFrac;
procedure f19p(x,y,a,d:extended;var r,g,b:extended);
begin
 r:=arctan(x*pi*exp(x)/ln(pi*x*y))*cos(y*ln(x)*10/cos(x/sin(y)));
 g:=sin(x*y/y)*exp(sin(x*sin(y)))*sqr(arctan(x/y));
 b:=-sqrt(sin(sqr(sin(x))));
end;

const f20c='By Sergius бабочка-2';
      f20s=symZero; f20b=baFrac;
procedure f20p(x,y,a,d:extended;var r,g,b:extended);
begin
 r:=arctan(x*pi*exp(x)/ln(pi*x*y))*cos(y*ln(x/10*y/arctan(x*y))*10/cos(x/sin(y)));
 g:=sin(x*y/y)*exp(sin(x*sin(y)))*sqr(arctan(x/y));
 b:=-sqrt(sin(sqr(sin(x))));
end;

const f21c='By Sergius';
      f21s=symZero; f21b=baFrac;
procedure f21p(x,y,a,d:extended;var r,g,b:extended);
begin
 r:=-arctan(x*pi*exp(x)/ln(pi*x*y))*cos(y*ln(x/10*y/arctan(x*y))*10/cos(x/sin(y)));
 g:=cos(x*y/y)*exp(sin(x*sin(y/ln(x*18/(sin(x*y)*20*exp(x))))))*sqr(arctan(x/y));
 b:=-sin(x*y/ln(10*x/exp(y)))+sqrt(sin(sqr(sin(x)*cos(y/(sin(10/x*pi)*sin(x*pi/23))))));
end;

const f22c='By Sergius';
      f22s=symZero; f22b=baFrac;
procedure f22p(x,y,a,d:extended;var r,g,b:extended);
begin
    r:=sin(x/y)*sin(y/x);
    g:=cos(exp(sin(x*pi+y*d)))*sin(d*x*y);
    b:=sqr(sin(x*pi))+tan(sqr(sin(y*pi))+sin(12*d*y*x));
end;

const f23c='By Sergius';
      f23s=symZero; f23b=baFrac;
procedure f23p(x,y,a,d:extended;var r,g,b:extended);
begin
    g:=sin(ln(d+x)*pi*(tan(d*cos(1/x*arctan(d*y)+(tan(-cos(x/y/d)-sin(y/x/d)*y/sin(x)*exp(d*cos(d)*x)*d))*sin(x)/cos(d)/d*x))));
end;

const f24c='By Sergius';
      f24s=symZero; f24b=baFrac;
procedure f24p(x,y,a,d:extended;var r,g,b:extended);
begin
 r:=sin(ln(d+x)*pi*(tan(d*cos(1/x*arctan(d*y)+(tan(-cos(x/y/d)-sin(y/x/d)*y/sin(x)*exp(d*cos(d)*x)*d))*sin(x)/cos(d)/d*x))));
 g:=sin(-sqr(x*12)*sqr(y*12));
 b:=r/sin(d*x);
end;

const f25c='By Sergius';
      f25s=symZero; f25b=baFrac;
procedure f25p(x,y,a,d:extended;var r,g,b:extended);
begin
 r:=cos(y*exp(x/d))/cos(x*exp(y/d));
 g:=arctan(sin(cos(sqr(x*7))+sqr(y*12)));
 b:=x*exp(d)*sqr(y*4)-y*exp(d)*sqr(x*4);
end;

const f26c='By Sergius';
      f26s=symZero; f26b=baFrac;
procedure f26p(x,y,a,d:extended;var r,g,b:extended);
begin
 r:=sin(cos(y*exp(x/d))/cos(d*exp(d)/cos(d)));
 g:=exp(sin(x*pi+y*d))*sin(d*x*y);
 b:=d*x/sin(pow(y,y)/d)*sin(exp(sin(x/sin(x*y))));
end;

const f27c='Лохматые X-Wings';
      f27s=symZero; f27b=baFrac;
procedure f27p(x,y,a,d:extended;var r,g,b:extended);
var i:integer;
begin
 r:=1;
 for i:=1 to trunc(d*100) do
  r:=r*a/x/y;
end;

