@echo off
:quick
rem Quick install section
rem This will automatically use the variables below to install the world database without prompting then optimize them and exit
rem To use: Set your environment variables below and change 'set quick=off' to 'set quick=on' 
set quick=off
if %quick% == off goto standard
echo (( SDB Quick Installer ))
rem -- Change the values below to match your server --
set svr=localhost
set user=root
set pass=
set port=3306
set wdb=world
rem -- Don't change past this point --
set yesno=y
goto install

:standard
rem Standard install section
color 3
echo.
set /p svr=What is your MySQL host name?           [localhost]      : 
if %svr%. == . set svr=localhost
set /p user=What is your MySQL user name?          [strawberry]	    : 
if %user%. == . set user=strawberry
set /p pass=What is your MySQL password?           [strawberry]	    : 
if %pass%. == . set pass= 
set /p port=What is your MySQL port?               [3306]           : 
if %port%. == . set port=3306
set /p wdb=What is your World database name?       [WorldDB]        : 
if %wdb%. == . set wdb=WorldDB

:install
set dbpath=FULL_DB
set mysql=.

:checkpaths
if not exist %dbpath% then goto patherror
if not exist %mysql%\mysql.exe then goto patherror
goto world

:patherror
echo Cannot find required files, please ensure you have done a fully
echo recursive checkout from the Git Repo.
pause
goto :eof

:world
if %quick% == off echo.
if %quick% == off echo This will wipe out your current World database and replace it.
if %quick% == off set /p yesno=Do you wish to continue? (y/n) 
if %quick% == off if %yesno% neq y if %yesno% neq Y goto done

echo.
echo Importing World database

for %%i in (%dbpath%\*.sql) do if %%i neq %dbpath%\*.sql) if %%i neq %dbpath%\*.sql) if %%i neq %dbpath%\*.sql) echo %%i & %mysql%\mysql -q -s -h %svr% --user=%user% --password=%pass% --port=%port% --max_allowed_packet=4096M %wdb% < %%i

if %quick% neq off goto :eof

:done
echo.
echo Done =)
echo.
pause