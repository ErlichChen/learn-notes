'''
loop
'''

count = 0
sum = 0
while count <= 100:
	sum += count
	count += 1

print("sum:", sum)

count = 0
while count < 20:
	if count%2 != 0:
		print(count)
	count += 1
	if count == 10:
		break
else:
	print("while else")

