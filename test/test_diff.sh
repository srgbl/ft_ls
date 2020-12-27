#!/bin/bash
GREEN='\033[0;32m'
RED='\033[0;31m'
EOC='\033[0m'

ex_1="./ft_ls $@"
ex_2="ls $@"

o1="/tmp/ft_ls_out"
o2="/tmp/ls_out"
set="artsSQmi1GRlgh"
setlist=`crunch 0 3 "$set"`

compare(){
    ${ex_1} -$1 -1 | cat -e > $o1
    ${ex_2} -$1 -1 | cat -e > $o2
    DIFF=$(diff <(cat $o1) <(cat $o2))
    if [ "$DIFF" != "" ]
    then
        printf "${RED}KO${EOC}: "
        echo "${ex_1} -$1 -1"
        git diff --no-index --unified=0 $o1 $o2
        echo "\n${ex_1} -$1 -1" >> /tmp/ft_ls_err
        git diff --no-index --unified=0 $o1 $o2 >> /tmp/ft_ls_err
    else
        printf "${GREEN}OK${EOC}: "
        echo "${ex_1} -$1 -1"
    fi
}

for item in ${setlist[*]}
do
    compare "$item"
done
