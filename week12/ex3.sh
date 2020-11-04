touch a
echo file size is 10 MiB >> ex3.txt
dd if=/dev/zero of=a bs=10MiB count=1

echo >> ex3.txt

echo -DBUF_SIZE=10 >> ex3.txt
gcc copy.c -o copy -DBUF_SIZE=10
time -o ex3.txt -a -f "\t%E real,\t%U user,\t%S sys" ./copy a b
rm b

echo >> ex3.txt

echo -DBUF_SIZE=10 -D_SYNC=1 >> ex3.txt
gcc copy.c -o copy -DBUF_SIZE=10 -D_SYNC=1
time -o ex3.txt -a -f "\t%E real,\t%U user,\t%S sys" ./copy a b
rm b

echo >> ex3.txt

echo -DBUF_SIZE=100 >> ex3.txt
gcc copy.c -o copy -DBUF_SIZE=100
time -o ex3.txt -a -f "\t%E real,\t%U user,\t%S sys" ./copy a b
rm b

echo >> ex3.txt


echo file size is 50 MiB >> ex3.txt
rm a
dd if=/dev/zero of=a bs=50MiB count=1

echo >> ex3.txt

echo -DBUF_SIZE=10 >> ex3.txt
gcc copy.c -o copy -DBUF_SIZE=10
time -o ex3.txt -a -f "\t%E real,\t%U user,\t%S sys" ./copy a b
rm b

echo >> ex3.txt

echo -DBUF_SIZE=10 -D_SYNC=1 >> ex3.txt
gcc copy.c -o copy -DBUF_SIZE=10 -D_SYNC=1
time -o ex3.txt -a -f "\t%E real,\t%U user,\t%S sys" ./copy a b
rm b

echo >> ex3.txt

echo -DBUF_SIZE=100 >> ex3.txt
gcc copy.c -o copy -DBUF_SIZE=100
time -o ex3.txt -a -f "\t%E real,\t%U user,\t%S sys" ./copy a b
rm b

rm a

