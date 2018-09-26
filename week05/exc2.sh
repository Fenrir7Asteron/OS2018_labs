CURRENT_DIRECTORY=$(pwd)
FILE_NAME="/ex2.txt"
FILE="$CURRENT_DIRECTORY$FILE_NAME"

tempfile=$(mktemp ./lock.XXXX)
lockfile=./lockfile
while !(ln $tempfile $lockfile 2>/dev/null)
do
    true
done

NUMBER_SEQUENCE=$(cat $FILE)
echo "\nRead sequence"
echo $NUMBER_SEQUENCE

i=1
for VARIABLE in $NUMBER_SEQUENCE
do
i=`expr $i + 1`
done

echo $NUMBER_SEQUENCE $i > $FILE
echo "\nWrite sequence\n"
cat $FILE

rm $lockfile
rm $tempfile


