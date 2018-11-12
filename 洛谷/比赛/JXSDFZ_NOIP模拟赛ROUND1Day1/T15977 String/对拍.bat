:loop
makedata.exe
T15977String.exe
T15977StringAC.exe
fc WAout.out ACout.out
if %errorlevel%==0 goto loop
pause