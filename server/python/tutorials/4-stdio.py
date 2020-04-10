'''
standard input and output
'''

name = input("Your name:")
age  = input("Your age:")
job  = input("Your job:")

info = '''
------------ info of %s -----------
Name : %s
Age  : %d
Job  : %s
------------- end -----------------
''' % (name, name, int(age), job)

print(info)

num = 4
s = "The cat have %d legs" % (num)
print(s)

print("%s learned 100%% Python" % "I")
