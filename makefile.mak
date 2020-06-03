CC       = bcc32
RC       = brcc32
AS       = tasm32

C_FLAGS = -tW -c -q -w-par -w-rvl

DEF =
DFM = Unit1.dfm Unit2.dfm Unit3.dfm
SRC = application.cpp elements.cpp Project1.cpp
SRCU =  Unit1.cpp Unit2.cpp Unit3.cpp

.cpp.obj:
 $(CC) $(CFLAGS) $(SRC)

Unit1.obj: Unit1.h Unit1.cpp Unit1.dfm
 $(CC) $(CFLAGS) Unit1.cpp

Unit2.obj:
 $(CC) $(CFLAGS) Unit1.cpp Unit1.dfm

.cpp.obj:
 $(CC) $(CFLAGS) $(SRCU) $(DFM)

Project1.res: Project1.rc
 $(RC) Project1.res


Project1.exe: Project1.obj
 ILINK32 /aa /Tpe /Gk /t /q -w-dup c0w32.obj $(SRC:.cpp=.obj), Project1.exe,,\
cw32.lib import32.lib vcl.lib rtl.lib,$(DEF),Project1.res