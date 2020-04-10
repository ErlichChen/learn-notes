'''
control flow
'''

num = input("Please input a number: ")
print(type(num))
print(type(int(num)))
if int(num) < 0:
	print("The number is less than zero.")
elif int(num) == 0:
	print("The number is equal zero.")
else:
	print("The number is greater than zero.")
