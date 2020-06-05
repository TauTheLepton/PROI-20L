CC       = bcc32
RC       = brcc32
AS       = tasm32

C_FLAGS = -tW -c -q -w-par -w-rvl

DEF =
DFM = Unit1.dfm Unit2.dfm Unit3.dfm
SRC = application.cpp elements.cpp Project1.cpp Unit1.cpp Unit2.cpp Unit3.cpp

unit_test.exe: unit_test.obj test.obj application.obj elements.obj
 $(CC) $(CFLAGS) unit_test.obj test.obj application.obj elements.obj -o unit_test

application.obj: application.h application.cpp
 $(CC) $(CFLAGS) -c application.cpp

elements.obj: elements.h elements.cpp
 $(CC) $(CFLAGS) -c elements.cpp

test.obj: test.h test.cpp
 $(CC) $(CFLAGS) -c test.cpp

clean:
 rm -f core *.obj main


#.cpp.obj:
# $(CC) $(CFLAGS) $(SRC)



#Project1.res: Project1.rc
# $(RC) Project1.res


#Project1.exe: Project1.obj $(SRC:.cpp=.obj) $(DFM)
# ILINK32 /aa /Tpe /Gk /t /q -w-dup c0w32.obj $(SRC:.cpp=.obj), Project1.exe,,\
#cw32.lib import32.lib vcl.lib rtl.lib,$(DEF),Project1.res