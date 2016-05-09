#set VERSION=sgdk094.1
set VERSION=sgdk095

set GDK=D:/MDDev/SGDK/%VERSION%
set GDK_WIN=D:\MDDev\SGDK\%VERSION%

set PATH=%PATH%;%GDK%;%GDK_WIN%

rescomp -convert 
pause
cmd