touch ../week01/file.txt
link ../week01/file.txt _ex2.txt >> ex2.txt
find ../week01/file.txt -inum 1967389 >> ex2.txt
find ../week01/file.txt -inum 1967389 -exec rm {} \; >> ex2.txt
rm _ex2.txt
