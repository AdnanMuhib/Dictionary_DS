# Dictionary of JSON Files Using Linked Lists
Dictionary using linked list of list in c++ Data Structures
## Current Progress
### take input from the user as a word and its possible meanings and Add them to the Dictionary as Word Object
### Read Words and meaning from a comma seperated text file and then add them to the dictionary
### read from the JSON file and Created Dictionary
### Write Created Dictionary to a JSON File
current file can be found in project folder as wordlist.txt
the file contains comma seperated words and their meaning
First Word of each line is Term or Word and remaining words in the same line are the meanings or definations of the first word
### Write the loaded dictionary to a JSON File
file can be found in the project folder as jsonfile.json
### type a particular word to search it's meanings from the loaded dictionary from the file
the user types a word if the word is found in the Dictionary then user can see all the definitions/ meanings of the word 

# note 
all the words/meanings/definitions of the dictionary are converted to upper case before storing or loading 
and if a user wants to search a particular word's meaning , that word is also converted to same case. in this way searching something from dictionary will not be case sensitive any more .
# Things to be Done

## Binary file read/write
## Extend the Wordlist for Different Subjects
## Iterators to make the Dictionary Searching Word Fast
## hashing to make it more fast 
