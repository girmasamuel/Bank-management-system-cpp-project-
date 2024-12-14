#variables.........................................................
compiler = g++ # compiler

#src codes/dependencies
main_s = src/main.cpp
graphics_s = src/graphic/graphics.cpp

#bank systems
admin_s = src/bank-system/admin.cpp
bank_account_s = src/bank-system/bank_account.cpp
data_base_s = src/bank-system/database.cpp

#objects files/excutables
main_o = build/bin/main.o
graphics_o = build/bin/graphics.o

admin_o = build/bin/admin.o
bank_account_o = build/bin/bank_account.o
data_base_o = build/bin/database.o

#------------------------------------------------------------------------
EXECUTABLE = build/start_system #excutable files linked as one

#all excutable files/dependencies
OBJECTS = $(main_o) $(graphics_o) $(admin_o) $(bank_account_o) $(data_base_o)
#.....................................................................

#linker to one excutable file
$(EXECUTABLE):$(OBJECTS)
	$(compiler) -o $(EXECUTABLE) $(OBJECTS) 

# --------------compile each soutce code-------------------
#------------------------- main ---------------------------
$(main_o): $(main_s)
	$(compiler) -c $(main_s) -o $(main_o)

#---------------graphics/banners and colors ---------------
$(graphics_o): $(graphics_s)
	$(compiler) -c $(graphics_s) -o $(graphics_o)


#---------------admin --------------------------------------
$(admin_o): $(admin_s)
	$(compiler) -c $(admin_s) -o $(admin_o)
#---------------bank account ---------------
$(bank_account_o): $(bank_account_s)
	$(compiler) -c $(bank_account_s) -o $(bank_account_o)
#--------------- database -----------------------------------
$(data_base_o): $(data_base_s)
	$(compiler) -c $(data_base_s) -o $(data_base_o)
	
#.................................................................
#commands
clean:
	rm -f $(OBJECTS)