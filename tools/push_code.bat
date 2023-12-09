:: Usage:
:: push_code.bat "[add] add a tool of pushing code"
set REPO_LINK=%1
REM set BRANCHES=%2
REM set COMMENTS=%3

:: git clone https://github.com/shangguocan/Learning_Boost.git
git clone %REPO_LINK%

echo %REPO_LINK%~n0

REM git checkout -b %BRANCHES%
REM git status
REM git add .
REM git commit -m %COMMENTS%
REM git push
REM git pull
