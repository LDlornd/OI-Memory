:loop
makedata.exe
tle.exe
sol.exe
fc wa.out tle.out
if %errorlevel%==0 goto loop
pause