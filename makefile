#variables.........................................................
compiler = g++ # compiler

#src codes/dependencies
search_s = src/algorithm/searching_algorithm.cpp
sort_s = src/algorithm/sorting_algorithm.cpp

account_s = src/data-structure/account.cpp
customer_s = src/data-structure/customer.cpp
transaction_s = src/data-structure/transaction.cpp
linkedList_s = src/data-structure/linked_list.cpp
qeuee_s = src/data-structure/qeuee.cpp
stack_s = src/data-structure/stack.cpp

main_s = src/main.cpp

#objects files/excutables
search_o = build/searching_algorithm.o
sort_o =  build/sorting_algorithm.o

account_o = build/account.o
customer_o =  build/customer.o
transaction_o =  build/transaction.o
linkedList_o =  build/linked_list.o
qeuee_o =  build/qeuee.o
stack_o =  build/stack.o

main_o = build/main.o
#------------------------------------------------------------------------
EXECUTABLE = build/start_system #excutable files linked as one
#all excutable files/dependencies
OBJECTS = $(search_o) $(main_o) $(sort_o) $(account_o) $(customer_o) $(transaction_o) $(linkedList_o) $(qeuee_o) $(stack_o) 

#.....................................................................

#linker to one excutable file
$(EXECUTABLE):$(OBJECTS)
	$(compiler) -o $(EXECUTABLE) $(OBJECTS) 

#compile each soutce code
#--------------------------------------------
# algorithms
$(search_o): $(search_s)
	$(compiler) -c $(search_s) -o $(search_o)

$(sort_o): $(sort_s)
	$(compiler) -c $(sort_s) -o $(sort_o)

 # data structures
 #--------------------- account ----------------------------------
$(account_o): $(account_s)
	$(compiler) -c $(account_s) -o $(account_o)

 #--------------------- customer ----------------------------------
$(customer_o): $(customer_s)
	$(compiler) -c $(customer_s) -o $(customer_o)

 #--------------------- transaction ----------------------------------
$(transaction_o): $(transaction_s)
	$(compiler) -c $(transaction_s) -o $(transaction_o)

#--------------------- linked list ----------------------------------
$(linkedList_o): $(linkedList_s)
	$(compiler) -c $(linkedList_s) -o $(linkedList_o)

#------------------------ qeuee ------------------------------------
$(qeuee_o): $(qeuee_s)
	$(compiler) -c $(qeuee_s) -o $(qeuee_o)

#-------------------------- stack ----------------------------------
$(stack_o): $(stack_s)
	$(compiler) -c $(stack_s) -o $(stack_o)

#----------------- main ---------------------------------------------
$(main_o): $(main_s)
	$(compiler) -c $(main_s) -o $(main_o)

#.................................................................
#commands
clean:
	rm -f $(OBJECTS)