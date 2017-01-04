Format the input file as follows, make sure event or concessions is appended to the front of each line

For event objects:

event, "name", "description","event time" (8:10, etc), price, duration, seats available


For concession objects:

#I have it set up so that there is a stock for all three sizes, so set a size to 0 if there is no stock #for an item of that size.

#The type parameter is just to ease sorting in the concessions menu (0 for food item, 1 for drink item).

concessions, "name", "description", stock sm, stock md, stock lg, price sm, price md, price lg, type 



