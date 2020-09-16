#crirical region is filename
#race condition may occure anytime
echo 1 > filename
for i in ` seq 0 1000`; do
	LASTNUM=`tail -1 filename`
	NEXTNUM=$((LASTNUM+1))
	echo $NEXTNUM >> filename
done

