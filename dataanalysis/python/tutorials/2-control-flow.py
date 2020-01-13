# gender = input("你是个男的还是女的?")

# if语句 ==表示判断
'''
if gender == '男的':
	print("滚蛋!")
print("吓死我了")



if gender == '女的':
	print("请进. 欢迎光临!")
else:	# 否则
	print("滚蛋")



if gender == '女的':
	age = input("你多大了啊?") # 年龄大于60就不开门了. 小于60可以考虑
	if int(age) < 60:
		print("请进")
	else:
		print("大妈您去隔壁看看金老板")
else:
	print("滚蛋!")



# 输入你兜里的钱
# 如果你的钱大于500块. 和啤酒吃炸鸡. 生活美滋滋
# 如果你兜里的钱 小于500 大于300. 吃个盖浇饭. 生活乐无边
# 如果你都里的前 小于300 大于50. 吃个方便面. 开心
# 如果你兜里的钱 小于50. 今天减肥.

money = input("请输入你兜里的钱:")
if int(money) > 500:
	print("和啤酒吃炸鸡. 生活美滋滋")
else:
	# 小于500
	if int(money) > 300:
		print("盖浇饭走起")
	else:
		if int(money) > 50:
			print("方便面走起")
		else:
			print("减肥")


money = int(input("请输入你兜里的钱:"))

if money > 500:
	print("和啤酒吃炸鸡. 生活美滋滋")
elif money > 50:
	print("方便面走起")
elif money > 300:
	print("盖浇饭走起")
else:
	print("减肥走起")
'''

'''
a = 10
b = 3
print(a%b)	# xxx是否可以被xxxx整除


num = input("请输入一个数:")
num = int(num)
if num % 3 == 0:
	print("是三的倍数")
else:
	print("不是三的倍数")

'''
a = 10
b = 3
print(a//b)	# 取整