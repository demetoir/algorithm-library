unit graph;

interface
uses
    forms, graphics, types;

procedure initGraph();    
procedure run;
procedure process;
procedure clear;
procedure waitForKey;


type
  TForm1 = class(TForm)
    procedure FormKeyPress(Sender: TObject; var Key: Char);
  end;

var
    form: tForm1;
    canvas: tCanvas;
    rect: tRect;

implementation
{$R graph.dfm}

var
    isKeyPressed: boolean;

procedure TForm1.FormKeyPress(Sender: TObject; var Key: Char);
begin    
    isKeyPressed := true;
end;

procedure waitForKey;
begin
    isKeyPressed := false;
    while (not isKeyPressed) do begin
        process;
    end;
end;

procedure initGraph();
begin
    Application.Initialize;
    Application.CreateForm(TForm1, form);

    form.left := 0;
    form.top := 0;
    form.width := screen.width;
    form.height := screen.height; 
    form.show();

    canvas := form.canvas;
    rect.left := 0;
    rect.top := 0;
    rect.right := form.width;
    rect.bottom := form.height;

    canvas.Brush.Color := clBlack;
    canvas.FillRect(rect);

    canvas.pen.Color := clYellow;
    canvas.LineTo(100, 100);

    Application.processMessages;
end;

procedure run;
begin   
    application.run;
end;

procedure process;
begin   
    application.processmessages;
end;

procedure clear;
var
    color: Tcolor;
begin   
    color := canvas.Brush.Color;
    canvas.Brush.Color := $000000;
    canvas.FillRect(rect);
    canvas.Brush.Color := color;
end;

begin
end.
