:loop
makedata.exe

ac.exe
temp.exe
fc ac.out wa.out
if %errorlevel%==0 goto loop
pause