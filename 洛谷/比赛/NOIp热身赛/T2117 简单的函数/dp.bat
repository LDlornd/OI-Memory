:loop
makedata.exe
ans.exe
tle.exe
fc ans.out tle.out
if %errorlevel%==0 goto loop
pause