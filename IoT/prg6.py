print("Enter the details:\n")
person = {}

print("Enter the name of the person:")
name = input()
person["name"] = name

address = input("Enter the address of the person: \n")
person["address"] = address

gender = input("Enter the gender of the person: \n")
person["gender"] = gender

age = int(input("Enter the age of the person: \n"))
person["age"] = age

telephone = int(input("Enter the telephone number of the person: \n"))
person["telephone"] = telephone

print(person)