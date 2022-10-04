print("Enter two numbers")
x = int(input())
y = int(input())

#Sum function
sum = x + y
print("Sum of {0} and {1} is: {2}".format(x, y, sum))

#Difference function
difference = x - y
print("Difference of {0} and {1} is {2}".format(x, y, difference))

#Product function
product = x*y
print("Product of {0} and {1} is {2}".format(x, y, product))

#Quotient function
quotient = x/y
print("Quotient of {0} divided by {1} is {2}".format(x, y, quotient))

#Modulous function
mod = x % y
print("Remainder of {0} divided by {1} is {2}".format(x, y, mod))

#Floor division
f_div = x // y
print("Floor division of {0} divided by {1} is {2}".format(x, y, f_div))

#Exponential 
exp = x ** y
print("Power of {0} to {1} is {2}".format(x, y, exp))