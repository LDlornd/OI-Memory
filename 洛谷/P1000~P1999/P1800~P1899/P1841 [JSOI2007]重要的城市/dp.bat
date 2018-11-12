:loop
makedata.exe
sol.exe
ans.exe
fc wa.out ans.out
if %errorlevel%==0 goto loop
pause