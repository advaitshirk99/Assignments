x = int(input("Enter the value of x:"))
y = int(input("Enter the value of y:"))

while(1):
	print("\nEnter the number of your choice of operation:\n\n1---> Add {0} and {1}\n2---> Subtract {0} from {1}\n3---> Multiply {0} with {1}\n4---> Divide {0} with {1}\n0---> Exit\n".format(x, y))
	choice = int(input())

	if choice == 0:
		break
	
	elif choice == 1:
		print("The sum of {0} and {1} is {2}.\n\n".format(x, y, x+y))

	elif choice == 2:
		print("The difference of {0} and {1} is {2}.\n\n".format(x, y, x-y))

	elif choice == 3:
		print("The product of {0} and {1} is {2}.\n\n".format(x, y, x*y))

	elif choice == 4:
		print("The quotient of {0} divided by {1} is {2}.\n\n".format(x, y, x/y))

