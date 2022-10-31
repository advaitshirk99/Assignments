def factorial(num):
	if (num==1):
		return 1

	return num * factorial(num-1)


print("Factorial of 5 is:", factorial(5))
print("Factorial of 6 is:", factorial(6))
