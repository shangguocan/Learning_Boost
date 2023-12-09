
set COMMENTS=%1

git status
git add .
git commit -m %COMMENTS%
git push
git pull