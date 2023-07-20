@echo off

2>nul (del smw_assets.dat)
python assets/restool.py
IF NOT ERRORLEVEL 0 goto ERROR

IF NOT EXIST "smw_assets.dat" (
  ECHO ERROR: The python program didn't generate smw_assets.dat successfully.
  goto ERROR  
) ELSE (
  REM
)

goto DONE


:ERROR
ECHO:
ECHO ERROR: Asset extraction failed!
pause
EXIT /B 1

:DONE
echo Complete!
pause