#!/bin/bash
INPUT=$1
EXPORT=$2

Color_Off='\033[0m'       # Text Reset

Black='\033[0;30m'        # Black
Red='\033[0;31m'          # Red
Green='\033[0;32m'        # Green
Yellow='\033[0;33m'       # Yellow
Blue='\033[0;34m'         # Blue
Purple='\033[0;35m'       # Purple
Cyan='\033[0;36m'         # Cyan
White='\033[0;37m'        # White

BBlack='\033[1;30m'       # Black
BRed='\033[1;31m'         # Red
BGreen='\033[1;32m'       # Green
BYellow='\033[1;33m'      # Yellow
BBlue='\033[1;34m'        # Blue
BPurple='\033[1;35m'      # Purple
BCyan='\033[1;36m'        # Cyan
BWhite='\033[1;37m'       # White

UBlack='\033[4;30m'       # Black
URed='\033[4;31m'         # Red
UGreen='\033[4;32m'       # Green
UYellow='\033[4;33m'      # Yellow
UBlue='\033[4;34m'        # Blue
UPurple='\033[4;35m'      # Purple
UCyan='\033[4;36m'        # Cyan
UWhite='\033[4;37m'       # White

if [ $# -eq 1 ]
then
    echo -e "${Yellow}Missing output name! Setting to a.exe${White}"
    `g++ -Wall -pedantic $INPUT -O2 -o a.exe`
else
    `g++ -Wall -pedantic $INPUT -O2 -o $EXPORT` 
fi

if [ $? -eq 0 ]
then
    echo -e "${BGreen}Compilation succesfull!${White}"
else 
    echo -e "${BRed}Compilation failed!${White}"
fi
if [ $# -gt 3 ]
then   
    if [ $3 == "TEST" ]
    then
        echo -e "${CYAN}Test initialized:"
        echo -e "${NC}"
        for IN_FILE in $TEST/*$4_in.txt
            do    
            REF_FILE=`echo  $IN_FILE | sed -e 's/_in\(.*\)$/_out_win\1/'`
            $PROG < $IN_FILE > out.txt
            if ! diff $REF_FILE out.txt
            then        
                echo -e "${RED}Fail: ${OR}$IN_FILE | $REF_FILE";
            else
                echo -e "${GREEN}OK ${GR}$IN_FILE";
            fi
            rm "out.txt"
        done
    else
        echo "No testing parameter"
        echo -e "${NC}"
    fi


    if [ $3 == "RUN" ]
    then
        echo "Running compiled program"
        `$2`
    fi
fi


