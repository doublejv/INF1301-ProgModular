@ECHO  OFF
REM  Gera todos os scripts de make

cls

pushd  .

cd ..\ferramnt

gmake /b..\composicao /cTesteLista

gmake /b..\composicao /cTesteBaralho

popd
