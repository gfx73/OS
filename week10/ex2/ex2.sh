touch ../week01/file.txt
link ../week01/file.txt _ex2.txt >> ex2.txt
find ../week01/file.txt -inum 1966857 >> ex2.txt
find ../week01/file.txt -inum 1966857 -exec rm {} \; >> ex2.txt
find _ex2.txt -inum 1966857 >> ex2.txt
find _ex2.txt -inum 1966857 -exec rm {} \; >> ex2.txt
