print("Enter the details:\n")
person = {}

name = input("Enter the name of the person: ")
address = input("Enter the address of the person: ")
gender = input("Enter the gender of the person: ")
age = int(input("Enter the age of the person: "))
telephone = int(input("Enter the telephone number of the person: "))

person["name"] = name
person["address"] = address
person["gender"] = gender
person["age"] = age
person["telephone"] = telephone

print("Name:", person["name"], "Telephone:", person["telephone"])