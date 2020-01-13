'''
	Learn Python
	python Pandas
'''

# Pandas 提供的基础数据 结构 DataFrame 与 json 的契合度很高，转换起来就很方便
# 核心数据结构: Series 和 DataFrame

import pandas as pd
from pandas import Series, DataFrame
x1 = Series([1, 2, 3, 4])
x2 = Series(data = [1, 2, 3, 4], index = ['a', 'b', 'c', 'd'])
print(x1)
print(x2)