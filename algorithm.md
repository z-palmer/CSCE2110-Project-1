Project 1 Algorithm Documentation

Main.cpp:
	load():
1.	Read file to get Driver data
2.	Create Driver objects
3.	Insert Drivers into search database
4.	Insert Drivers into ordered database
displayMenu():
1.	Display text options for menu
2.	Await use input for menu choice
3.	If 1 chosen, call insertDriver()
4.	If 2 chosen, call searchDriver()
5.	If 3 chosen, call retreiveRecent()
6.	If 4 chosen, call retreiveOldest()
7.	If 5 chosen, call moveInactive()
8.	If 6 chosen, call displayDrivers()
9.	If 7 chosen, call exit()
10. Ask user if they would like to chose another action
insertDriver():
1.	Prompt user for driver data
2.	Create a new Driver object with data and insert into both databases
searchDriver():
1.	Prompt user for search criteria
2.	Call search() member function of search database using criteria
3.	If driver exists, print driver data
4.	If driver does not exist, return feedback message
retreiveRecent():
1.	Prompt user for n number of desired entries
2.	Call popBack() n number of user specified Drivers
3.	Create a dynamic array with n entries
4.	Display array contents
retreiveOldest():
1.	Prompt user for n number of desired entries
2.	Call popFront() n number of user specified Drivers
3.	Create a dynamic array with n entries
4.	Display array contents
moveInactive():
1.	Prompt user for inactive criteria
2.	Call makeInactive() for search database using criteria
3.	Call makeInactive() for ordered database using criteria
4.	Call insert() for inactive database using criteria
5.	Display confirmation message
displayDrivers():
1.	Ask user for number entries to be displayed
2.	Display n number of entries from ordered database
exit():
1.	Free all allocated memory
2.	Exit main()

SearchDatabase.hpp:
hash():
1.	Initialize A sum to 1
2.	Initialize B sum to 0
3.	Add key bytes to A
4.	Add these sums to B
5.	Continue this until key has no more bytes
6.	Multiply B by 65536 (bitwise) and bitwise add A
7.	Return this number as table index
insert():
1.	Take in new Driver data
2.	Call hash() and insert new Driver at returned index
pushFront():
1.	Take in new Driver data
2.	If data at index 0, create new node in database and set next to current head
3.	Change new node to current head
pushBack():
1.	Take in new Driver data
2.	If data at index size, create new node in database and set tail next to new node
3.	Set new node as current tail
search():
1.	Create a new Driver pointer
2.	Call hash() using user specified data
3.	Use hash() returned index to find specified Driver and set point to this reference
4.	Return new Driver pointer
makeInactive():
1.	Use hash() to find Driver at index, data matches user specified data, then delete node, else check next node at index

OrderedDatabase.hpp:
push():
1.	Take in new Driver data
2.	Create new node in database and set next to current head
3.	Chane new node to head
first():
1.	Return head
last():
1.	Return tail
popFront():
1.	Create new node and make it head
2.	Store current head’s next
3.	Deallocate current head
4.	Set old head’s next to current head
5.	Return new node
popBack():
1.	Create new node and make it tail
2.	Store current tail’s previous
3.	Deallocate current tail
4.	Set old tail’s next to current tail
5.	Return new node
makeInactive():
1.	Use user data to find Driver based on date
2.	Save node’s previous and node’s next into two variables
3.	Deallocate node
4.	Set previous node’s next to next of deallocated node
5.	Display confirmation message

InactiveDriverDatabase.hpp:
hash():
1.	Initialize A sum to 1
2.	Initialize B sum to 0
3.	Add key bytes to A
4.	Add these sums to B
5.	Continue this until key has no more bytes
6.	Multiply B by 65536 (bitwise) and bitwise add A
7.	Return this number as table index
insert():
1.	Take in new Driver data
2.	Call hash() and insert new Driver at returned index
search():
1.	Create a new Driver pointer
2.	Call hash() using user specified data
3.	Use hash() returned index to find specified Driver and set point to this reference
4.	Return new Driver pointer
