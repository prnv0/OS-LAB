function summarize()
{
cd $1
result=${PWD##*/}
echo "Name of directory : $result"
files=$(find . -type f | wc -l)
echo -e "number of files : $files \n"
extensions=$(find . -type f | perl -ne ’print $1 if m/\.([^.\/]+)$/’ | sort -u)
echo "List of all extensions of files present in directory :-"
echo "$extensions"
echo
echo "Extension and corresponding numbers "
for x in $extensions;do
length=$(find . -name "*.$x"| wc -l)
echo "number of $x files : $length"
done
}