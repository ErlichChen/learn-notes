'''
	Learn Python
	python Pandas
'''

# Pandas 提供的基础数据 结构 DataFrame 与 json 的契合度很高，转换起来就很方便
# 核心数据结构: Series 和 DataFrame

import numpy as np
import pandas as pd
from pandasql import sqldf, load_meat, load_births
from pandas import Series, DataFrame

x1 = Series([1, 2, 3, 4])
x2 = Series(data = [1, 2, 3, 4], index = ['a', 'b', 'c', 'd'])
print(x1)
print(x2)

d = {'a': 1, 'b': 2, 'c': 3, 'd': 4}
x3 = Series(d)
print(x3)

# DataFrame 类型数据结构类似数据库表
data = {'Chinese': [66, 95, 93, 90,80],'English': [65, 85, 92, 88, 90],'Math': [30, 98, 96, 77, 90]}
df1= DataFrame(data)
df2 = DataFrame(data, index=['ZhangFei', 'GuanYu', 'ZhaoYun', 'HuangZhong', 'DianWei'], columns=['English', 'Math', 'Chinese'])
print(df1)
print(df2)

# 数据导入和输出
score = DataFrame(pd.read_excel('test.xlsx'))
score.to_excel('test1.xlsx')
print(score)

# 数据清洗
data = {'Chinese': [66, 95, 93, 90,80],'English': [65, 85, 92, 88, 90],'Math': [30, 98, 96, 77, 90]}
df2 = DataFrame(data, index=['ZhangFei', 'GuanYu', 'ZhaoYun', 'HuangZhong', 'DianWei'], columns=['English', 'Math', 'Chinese'])
# 1.删除 DataFrame 中的不必要的列或行
# df2 = df2.drop(columns=['Chinese'])
df2 = df2.drop(index=['ZhangFei'])
print(df2)
# 2.重命名列名 columns，让列表名更容易识别
df2.rename(columns={'Chinese': 'YuWen', 'English': 'Yingyu'}, inplace = True)
print(df2)
# 3.去重复的值
df2 = df2.drop_duplicates()
print(df2)
# 4.格式问题
# 更改数据格式
# df2 = df2['YuWen'].astype('str')
# df2['YuWen'].astype(np.int64)
# 数据间的空格
# 删除左右两边空格
# df2['YuWen'] = df2['YuWen'].map(str.strip)
# # 删除左边空格
# df2['YuWen'] = df2['YuWen'].map(str.lstrip)
# # 删除右边空格
# df2['YuWen'] = df2['YuWen'].map(str.rstrip)
# df2['YuWen'] = df2['YuWen'].str.strip('$')

# 大小写转换
# 全部大写
df2.columns = df2.columns.str.upper()
# 全部小写
df2.columns = df2.columns.str.lower()
# 首字母大写
df2.columns = df2.columns.str.title()
# 查找空值
df2.isnull()

df2.isnull().any()

# 使用apply函数对数据进行清洗

# 数据统计

# 数据表合并
df1 = DataFrame({'name':['ZhangFei', 'GuanYu', 'a', 'b', 'c'], 'data1':range(5)})
df2 = DataFrame({'name':['ZhangFei', 'GuanYu', 'A', 'B', 'C'], 'data2':range(5)})

# 1.基于指定列进行连接
df3 = pd.merge(df1, df2, on='name')
print(df3)

# 2.inner 内连接
df3 = pd.merge(df1, df2, how='inner')
print(df3)

# 3.left 左连接
df3 = pd.merge(df1, df2, how='left')
print(df3)

# 4.right 右连接
df3 = pd.merge(df1, df2, how='right')
print(df3)

# 5.outer 外连接
df3 = pd.merge(df1, df2, how='outer')
print(df3)

# 如何用 SQL 方式打开 Pandas
df1 = DataFrame({'name':['ZhangFei', 'GuanYu', 'a', 'b', 'c'], 'data1':range(5)})
pysqldf = lambda sql: sqldf(sql, globals())
sql = "select * from df1 where name ='ZhangFei'"
print(pysqldf(sql))

