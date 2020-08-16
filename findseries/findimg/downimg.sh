#!/bin/bash
# this script may need sudo priveleges to run properly when creating files
LOC=$(locate /findseries/findimg | head -1)
TMP=$(pwd)

cd $LOC
rm userinput.txt
touch userinput.txt
echo "paste html here a word will be said if the program finds any images" > userinput.txt
nano userinput.txt
./a.out
rm -R imagesfound
mkdir imagesfound
LEN1="$(wc -l $LOC/storage/imgout.txt)"


for i in $(seq 1 ${#LEN1})
do
    if [[ "${LEN1:i-1:1}" = " " ]]
    then
        POS="$i"
        break
    fi
done

LEN1=$(( "${LEN1:0:POS}" ))

COUNTER=0


echo "enter a FULL location (pwd) to store the images (press enter and the program will put images in your working directory)"
read DIR
if [[ ${#DIR} -eq 0 ]]
then
    mkdir "$TMP/images/"
    DIR="$TMP/images/"
fi
for C in $(seq 1 $LEN1)
do

    LINE1=$(head -$C "$LOC/storage/imgout.txt" | tail -1)
    LINE2=$(head -$C "$LOC/storage/imgname.txt" | tail -1)

    curl "$LINE1" > "$LOC/imagesfound/$LINE2"
    mv $LOC/imagesfound/$LINE2 "$DIR"
    COUNTER=$(( $COUNTER + 1 ))
done



rm -R $LOC/imagesfound
echo "$COUNTER images were found, as long as there were no issues from curl you should have that many in your folder"
