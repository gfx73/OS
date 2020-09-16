#Two processes are appending numbers simulteniously 
#now there is no repetitions of numbers
if ln filename.txt filename.txt.lock
then
	echo 1 > filename.txt.lock
	rm filename.txt.lock
fi
i=2
while [ $i -le 1000 ]
do
	if ln filename.txt filename.txt.lock
	then
		LASTNUM=$(grep -Eo '^[0-9]+$' filename.txt.lock | tail -1)
		NEXTNUM=$((LASTNUM+1))
		echo $NEXTNUM >> filename.txt.lock
		rm filename.txt.lock
	else
		i=$(($i-1))
	fi
	i=$(($i+1))
done

