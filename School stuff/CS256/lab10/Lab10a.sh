x=(`ls`)  # store the results of ls in a list
echo practice: shell command and array
echo list all directories and files in current directory: ${x[*]}
echo total number of files and directories: ${#x[*]}  # number of elements in a list
echo the first element in this list: $x
echo all elements in this list:
for i in ${x[*]}
	do
		echo $i
	done

