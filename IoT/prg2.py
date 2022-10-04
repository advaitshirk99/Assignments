print("Enter the number who's factorial is to be found:")
num = x = int(input())
factorial = 1

if(x == 1): print("Facotrial of {0} is 1".format(num))
else:
	while (x != 0):
		factorial *= x
		x -= 1
	print("Factorial of {0} is {1}".format(num, factorial))
