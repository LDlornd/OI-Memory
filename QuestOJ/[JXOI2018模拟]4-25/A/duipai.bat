:loop
makedata.exe
A.exe
baoli.exe
fc A.out baoli.out
if %errorlevel%==0 goto loop
pause