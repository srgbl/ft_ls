#!/bin/bash
GREEN='\033[0;32m'
RED='\033[0;31m'
EOC='\033[0m'

ex_1="./ft_ls"
ex_2="ls"

${ex_1} $@ -1 | cat -e > o1
${ex_2} $@ -1 | cat -e > o2
DIFF=$(diff <(cat o1) <(cat o2))
if [ "$DIFF" != "" ]
then
    printf "${RED}KO${EOC}: "
    echo "${ex_1} $@ $ARGS"
    git diff --no-index --unified=0 o1 o2
else
    printf "${GREEN}OK${EOC}: "
    echo "${ex_1} $@ $ARGS"
fi
