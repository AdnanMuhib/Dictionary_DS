Dictionary of JSON Files Using Linked Lists
Dictionary using linked list of list in c++ Data Structures

Current Progress
1-	take input from the user as a word and its possible meanings 
	and Add them to the Dictionary as Word Object
2-	read from the JSON file and Created Dictionary
3-	Write the loaded dictionary to a JSON File
4-	Read Words and meaning from a comma seperated text file and
	then add them to the dictionary
	current file can be found in project folder as A-Z.txt
	the file contains comma seperated words and their meaning
	First Word of each line is Term or Word and 
	remaining words in the same line are the meanings or definations of the first word
	File has almost 4901 words with their definition

5-	file can be found in the project folder as jsonfile.json
6-	type a particular word to search it's meanings from the loaded dictionary from the file
	the user types a word if the word is found in the Dictionary then user can see all the definitions/ meanings of the word 
7-	Friend Function to Convert a string to upper case
8-	Friend Function to convert a string to lower case
9-	Friend Function to remove Double Quotes from the first and last index of a term  read from the JSON file
10-	Friend Function to remove a space at the frist index of a word
NOTE: 
all the words/meanings/definitions of the dictionary are converted to lower case before storing or loading 
and if a user wants to search a particular word's meaning , that word is also converted to same case. in this way searching something from dictionary will not be case sensitive any more .

Things to be Done
## Binary file read/write
## Extend the Wordlist for Different Subjects
## Iterators to make the Dictionary Searching Word Fast
## Binary Searching
## and whatever betterment can be done


Dictionary Words Collected From
https://www.easypacelearning.com/english-books/the-big-list-of-a-to-z-of-words