:loop
makedata.exe
ac.exe
sol.exe
fc ac.out wa.out
if %errorlevel%==0 goto loop
pause