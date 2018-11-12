:loop
makedata.exe
tle.exe
ans.exe
fc tle.out ac.out
if %errorlevel%==0 goto loop
pause