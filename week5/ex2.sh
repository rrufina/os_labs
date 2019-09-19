#!/bin/bash 

#create the numbers file                                                   
if test ! -f file
then
    echo 0 > file
fi


if ln file file.lock
	then                                                                    
	#Repeat 100 times
	for i in `seq 1 100`;
	do
		#Read and increase last number
		LASTNUMBER=`tail -1 file`
		LASTNUMBER=$((LASTNUMBER+1))

		echo $LASTNUMBER >> file
	done

	#Unlock
	rm file.lock
fi
