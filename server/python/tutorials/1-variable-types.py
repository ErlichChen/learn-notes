'''
variable types
'''
print("Hello Python!")

counter = 100      # An integer assignment
print(counter)
miles   = 1000.0   # A floating point
print(miles)
name    = "John"   # A string
print(name)
__ = "alex"
print(__)

# no constant variable in Python, just delcare it and don't change it
PI = 3.1415926
PI = 3.5
print(PI)

# data type
a = 128
print(type(a))
s = "type"
print(type(s))
b = False
print(type(b))

# compare number
b = 2 > 1
print(b)
print(type(b))

# stdout a single, array and multi-comment
print("test", end="\n")
print("test1", "test2", sep=" - ", end="\n")
print("""\
	Usage: thingy [OPTIONS]
     -a  a options
     -b  b options
	""")

# string joint
s1 = "s1"
s2 = "s2"
s3 = "s3"
s4 = s1 + s2 + s3
print(s4)

# string repeat
a = 1
print("a=", a, "a*3=", a*3)
s = "test"
print("s=", s, "s*3=", s*3)

# stdin
s = input("Please type it: ")
print("get: ", s)
print(type(s))

num1 = input("type a number:")
num1 = int(num1)
num2 = input("type another number")
num2 = int(num2)
print(num1 + num2)
