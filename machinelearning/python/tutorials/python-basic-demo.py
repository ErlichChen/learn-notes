'''
	Learn Python
	demo
'''

# 输入与输出
name = input("What's your name?")
sum = 100 + 100
print('hello, %s' %name)
print('sum = %d' %sum)

# if ... else ...
score = 90
if score >= 99:
	print('Excellent')
else:
	if score < 60:
		print('Fail')
	else:
		print('Good Job')

# for...in
sum = 0
for num in range(11):
	sum += num
print(sum)

# while
sum = 0
num = 1
while num < 11:
	sum += num
	num += 1
print(sum)

# 列表 []
lists = ['a', 'b', 'c']
lists.append('d')
print(lists)
print(len(lists))
lists.insert(0, 'mm')
lists.pop()
print(lists)

# 元组 tuple
tuples = ('tupleA','tupleB')
print(tuples[0])

# dictionary
score = {'guanyu':95,'zhangfei':96}
score['zhaoyun'] = 98
print(score)
score.pop('zhangfei')
print('guanyu' in score)
print(score.get('guanyu'))
print(score.get('yase',99))

# set
s = set(['a', 'b', 'c'])
s.add('d')
s.remove('b')
print(s)
print('c' in s)

# import
# 导入一个模块
import model_name
# 导入多个模块
import module_name1, module_name2
# 导入包中指定模块
from package_name import moudule_name
# 导入包中所有模块
from package_name import *

# def
def addone(score):
   return score + 1
print addone(99)