'''
operator
'''

# arithmetic operation
a = 3
b = 2
print("%d + %d = %d" % (a, b, (a + b)))
print("%d - %d = %d" % (a, b, (a - b)))
print("%d * %d = %d" % (a, b, (a * b)))
print("%d / %d = %d" % (a, b, (a / b)))
print("%d %% %d = %d" % (a, b, (a % b)))
print("%d ** %d = %d" % (a, b, (a ** b)))
print("%d // %d = %d" % (a, b, (a // b)))

# compare operation
print("%d == %d = %s" % (a, b, (a == b)))
print("%d != %d = %s" % (a, b, (a != b)))
print("%d > %d = %s" % (a, b, (a > b)))
print("%d < %d = %s" % (a, b, (a < b)))
print("%d >= %d = %s" % (a, b, (a >= b)))
print("%d <= %d = %s" % (a, b, (a <= b)))

# logical operator

# priority (), not, and, or
print(3>4 or 4<3 and 1==1) # False