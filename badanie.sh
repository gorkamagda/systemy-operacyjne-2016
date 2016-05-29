#!/bin/bash

if [ -e wiadomosc.txt ]

then

a=`cat wiadomosc.txt | aspell -d pl -a | grep '^*' | wc -l`

if [ $a = 1 ] 
then
	echo "Slowo jest poprawnym wyrazem w jezyku polskim"

else
	
echo "Slowo nie jest poprawnym wyrazem w jezyku polskim"


fi
rm wiadomosc.txt

fi
