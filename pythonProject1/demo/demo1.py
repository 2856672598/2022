# name = input('输入你的姓名')
# print(name)


# a = input('输入一个整数')
# b = input('输入一个整数')
# # 默认获取的是字符串
# print(int(a)+int(b))

# print(11 / 5)
# print(11 // 5)  # 整除运算
# print(2 ** 3)  # 8 ** 乘方运算
#
# print(9 // -4)  # 整除时一正一负向下取整
# print(9 // 4)
#
# print(9 % 4)  # 1
# print(9 % -4)  # 一正一负进行取余时要使用公式  余数= 被除数-除数*商
# # 9-(-4)*(-3) = 9-12 = -3
#
# a = b = c = d = 20  # 链式赋值 它们的id相同
# print(a, id(a))
# print(b, id(b))
# print(c, id(c))
# print(d, id(d))
#
# a = 30
# print(a, id(a))

# # 解包赋值  左边和右面必需一一对应
# a, b, c, d = 20, 30, 40, 'hello'
# print(a, b, c, d)
#
# print('------交换两个变量的值---------')
# print('交换前啊', a, b)
# a, b = b, a
# print('交换后', a, b)
#
# # == 比较的是值 ，is is not比较的标识
#
# print(a is b)
# a, b = 10, 10
# print(a, id(a))
# print(b, id(b))
# print(a is b)
# print(a is not b)
#
# list1 = [1, 2, 3]
# list2 = [1, 2, 3]
# print(list1 == list2)
# print(list1 is list2)
# print('list1[0]', id(list1[0]))
# print('list2[0]', id(list2[0]))
# print(list1[0] is list2[0])
#
# print('------------not 对bool类型的操作数进行取反-----------')
# f = True
# f2 = False
# print(not f)
# print(not f2)
#
# print('--------------对象的bool值--------------')
# print(1, bool(1))
# print(True, bool(True))
# print(0, bool(0))
# print({}, bool({}))


# # 分支语句
# money = 10000
# s = int(input('输入取款金额'))
#
# if s <= money:
#     money -= s
#     print('取款成功,余额为', money)
# else:
#     print('余额不足，剩余余额为', money)

# # 多分支结构
#
# score = int(input('输入您的分数'))
#
# if score >= 90:
#     print('成绩优秀')
# elif score >= 70:
#     print('成绩良好')
# elif score >= 60:
#     print('成绩一般')
# else:
#     print('成绩较差')

# # 条件表达式
# a = int(input('输入一个整数'))
# b = int(input('输入一个整数'))
# print(a if a <= b else b) # 条件成立输出前面，失败输出后面


# # pass什么语句都不做，只是一个占位符
#
# ch = input('您是会员吗Y/N')
# if ch == 'Y':
#     pass  # 占位作用，使用程序正常运行起来。
# else:
#     print('你是不会员')

#
# a, b = 10, 20
# c = a if a < b else b
# print(c)


# # range 函数生成一个整数序列
#
# a = range(10)  # 默认从0开始步长为1
# b = range(1, 5)  # 从1 开始到5结束
# c = range(0, 10, 2)  # 从0开始到10结束，步长为2
#
# # 不管range 对象表示的整数序列有多长，所有的range对象占用的内存空间都是相同的，只有将用到range对象时，才会去计算序列中的相关元素
# print(a, type(a))
#
# print(list(a))
# print(list(b))
# print(list(c))
# print(6 in c)


# a = 1
# while a != 10:
#     print(a)
#     a += 1
#
# a = 1
# count = 0
# for i in range(10):
#     count += i
# print(count)

# sum = 0
# i = 0
# while i <= 100:
#     if i % 2 == 0:
#         sum += i
#     i += 1
# print(sum)

# for in 循环
""" fot 自定义变量 in 可迭代对象:
    迭代体
"""
nums = {1, 2, 3, 4, 5}
for i in nums:
    print(i)
# 如果在循环体中不需要使用自定义变量，可以将变量定义为'_'
for _ in range(10):
    print('人生苦短我用Python')

# sum = 0
# for i in range(101):
#     if i % 2 == 0:
#         sum += i
# print(sum)


# # 100 - 999之间的水仙花数
# for i in range(100, 1000):
#     tmp = i
#     sum = 0
#     while tmp:
#         sum += (tmp % 10) ** 3
#         tmp //= 10
#     # print(i,sum)
#     if sum == i:
#         print(sum)

# for i in range(1,1000):
#     if i == 100:
#         break
#     print(i)
#

# for i in range(1, 100):
#     if i % 2 != 0:
#         continue
#     print(i)


# # else 搭配 除了 if else 还可以和 while else 和 for else 搭配使用 没有遇到break时在结束循环后执行else
# for i in range(3):
#     pwd = input('请输入密码')
#     if pwd == '9999':
#         print('密码正确')
#         break;
#     else:
#         print('密码错误')
# else:
#     print('密码连续三次输入错误')


# # 嵌套循环
# for i in range(1, 10):
#     for j in range(1, 10):
#         if j > i:
#             break
#         print(str(i) + '*' + str(j) + '=' + str(i * j), end='\t')
#     print()

# # 列表 [],调用内置函数list()
#
# nums = ['hello', 'left', 100]
# arr = list(['hello', 'left', 100])
#
# print(nums[1], type(nums[1]))
# print(nums[1], id(nums[1]))
# print(arr[1], id(arr[1]))  # 相同的两个变量 id值相等
#
# # 获取元素的索引 index 只返回第一个所在的位置 不存在时抛异常
# print(nums.index('hello'))

# # 切片  列表[开始:结束:步长]
# nums = [1, 2, 3, 4, 5, 6]
# print(nums[0::])  # 从0开始 到结尾 步长默认为1
# print(nums[0:5:2])  # 从0开始 到5结束 步长为2
# # 当步长为负数时是倒着走的
# print(nums[::-1])
# print(nums[3:1:-1])
#
# # in 判断是够存在 not in判断是否存在
# print(5 in nums)
# print(5 not in nums)

# # 向列表中添加一个元素 append()向列表的末尾添加
# # extent
# nums = [1, 2, 3, 4, 5, 6, 7, 2]
# nums.append(9)
# print(nums)
# name = ['李四', '张三']
# # nums.append(name) # 会作为一个整体添加进去
# nums.extend(name)
# print(nums)
# # 在任意位置添加至少一个元素
# list1 = ['left', 'right', 90]
# nums[1:1] = list1
# print(nums)
#
# # 列表删除元素 -- 移除列表中第一个匹配的元素。
# nums.remove(2)
# print(nums)
#
# # pop通过索引删除 不指定索引删除列表最后一个元素,索引超出范围抛异常
# nums.pop()
# nums.pop(0)
# print(nums)
#
# nums = [1, 2, 3, 4, 5]
# # 通过切片删除
# nums[1:4] = []
# print(nums)
#
# # clear() 清空列表所有内容
# nums.clear()
# print(nums)
# # del表示将对象删除
# del nums

# # 列表元素的修改
# nums = [1, 2, 3, 4, 5]
# nums[1] = 100
# print(nums)
# # 通过切片
# nums[1:4] = [200, 300, 400]
# print(nums)
#
# arr = [6, 5, 2, 89, 1, 3]
# print('排序前的列表', arr, id(arr))
# # 排序 不会创建新的列表对象
# arr.sort()
# print('排序后的列表', arr, id(arr))
#
# # 通过制定关键字对排序进行降序
# arr.sort(reverse=True)
# print(arr)
#
# print('使用内置函数sorted()对列表进行排序，将产生新的列表对象')
# new_list = sorted(arr)
# print(new_list)
#
# # 使用关键字实现降序排序
# new_list = sorted(arr, reverse=True)
# print(new_list)

# # 列表生成式[表示列表元素的表达式 for i in range()]
# # 产生 0- 9
# nums = [i for i in range(10)]
# print(nums)
# nums = [i for i in range(2, 11, 2)]
# print(nums)
# nums = [i * 2 for i in range(1, 6)]
# print(nums)

# # 创建字典
#
# nums = {'left': '左边', 'apple': '苹果'}
# print(nums)
#
# nums1 = dict({'left': '左边', 'right': '右面'})
# print(nums1)
#
# nums2 = dict(left='左边', apple='右面')
# print(nums2)
#
# # 使用[]时当键值不存在时会抛异常,get 方法返回None
# print(nums['left'])
# print(nums.get('left'))
# print(nums.get('zhangsan', '不存在'))  # 不存在时可以使用默认值
# # 使用 in not in  判断键值是否存在
#
# # 使用del删除指定键值对
# del nums2['left']
# print(nums2)
#
# '''
# 获取字典的视图
# keys()获取所有的键值
# values()获取所有的值
# items()获取所有的键值对
# '''
# print(nums.keys())
# print(nums.values())
# print(nums.items())
# li = nums.items()
# print(li, type(li))
#
# # 字典的遍历
# for i in nums:
#     print(i, nums[i], nums.get(i))
#
# '''
# 字典生成式
# {key:value for key,value in zip()}
# '''
# key = ['left', 'right', 'apple']
# values = ['左边', '右面', '苹果']
#
# arr = {key: value for key, value in zip(key, values)}
# print(arr)

# # 元组 是一个不可变序列
# nums = (1, 2, 3, 4)
# print(nums, type(nums))  # 括号可以省略
# nums1 = tuple((1, 2, 3, 4, 5))
# nums2 = 1, 2, 3, 4, 5
# print(nums1, type(nums1))
# print(nums2, type(nums2))
#
# # 如果元组只有一个元素时需要使用逗号和小括号
# nums3 = ('hello',)
# print(nums3, type(nums3))
#
# # 空元组的创建
# nums4 = ()
# nums5 = {}  # 空字典的创建
# nums6 = []  # 空列表的创建
# print(nums4, type(nums4))
# print(nums5, type(nums5))
# print(nums6, type(nums6))
#
# nums = (1, [2, 3], 4)
# nums[1].append(9)
# print(nums[0], type(nums[0]))
# print(nums[1], type(nums[1]))
#
# for i in nums:
#     print(i)

# '''
# 集合 属于可变类型的序列  自动去重
# 使用{}创建 或者 set()
# '''
#
# s = {'left', 'right', 'apple'}
# for i in s:
#     print(i)
# # s = {i for i in range(10)}
# # print(s)
#
# s.add('red')
# print(s)
# # 一次添加多个 可以是列表、元组
# s.update({'blue', '西瓜'})
# print(s)
#
# # 删除操作
# s.remove('left')  # 删除的元素不存在时抛异常
# s.discard('left')  # 存在时删除
#
# s.pop()  # 随机删除一个
# print(s)
#
#
# class Solution:
#     def removeDuplicates(self, nums: List[int]) -> int:
#         slow, fast = 0, 1
#         while fast < len(nums):
#             if nums[slow] != nums[fast]:
#                 slow += 1
#                 nums[slow] = nums[fast]
#             fast += 1
#         return slow + 1

# '''
# 判断两个集合是否相等可以使用== !=
# 子集判断可以使用 issubset
# 超集可以使用 issupperset判断
# 是否没有集合使用 isdisjoint
# '''
#
# nums1 ={1,2,3,4}
# nums2 ={4,3,2,1}
# nums3 ={1,2}
# print(nums1.issubset(nums2))
# print(nums1 == nums2)
#
# print(nums1.issuperset(nums3))
# print(nums1.isdisjoint(nums3))

# '''
# 集合的数学操作
# 求两个集合的交集 nums1 & nums2 或者 intersection
# 并集 | 或者 union
# 差集 difference -
# 对称差集
# '''
#
# nums1 = {10, 20, 30, 40}
# nums2 = {30, 40, 50, 60}
# print(nums1 & nums2)
# print(nums1.intersection((nums2)))
# # 并集
# print(nums1 | nums2)
# print(nums1.union(nums2))
# # 差集
# print(nums1.difference(nums2))
# print(nums2 - nums1)
# # 对称差集
# print(nums2 ^ nums1)
# print(nums1.symmetric_difference(nums2))
#
# # 集合生成式
# nums = {i for i in range(10)}
# print(nums)

# '''
# 字符串是一个不可变的字符序列
# 字符串驻留机制: 仅保存一份相同且不可变字符串的方法，不同的值被存放在字符串的驻留池中，在Pthon中
# 驻留机制对相同的字符串只保留一份拷贝，后序在创建相同的字符串时不会开辟新的空间
#
# 驻留机制的几种情况（交互模式下）
# 字符串长度为0或者为1时
# 符合标识符的字符串
# 字符串只在编译是进行驻留，而非运行时
# [-5,256]之间的整数数字
#
# sys中的intern方法强制2个字符串指向同一个对象
# '''
#
# a = "Python"
# b = 'Python'
# c = '''Python'''
# print(a, id(a))
# print(b, id(b))
# print(c, id(c))
#
# s1 = 'hello'
# s2 = 'hello'
# print(s1 is s2)
# s1 = 'abc%'
# s2 = 'abc%'
# print(s1 is s2)  # 编译器对这里进行了优化，进行了驻留
#
# s1 = -6
# s2 = -6
# print(s1 is s2)
#
# '''
# 字符串的查询
# index()子串第一次出现的位置，不存在抛异常
# rindex()子串最后一次出现的位置，不存在抛异常
# find() 正向查找，不存在时返回-1
# rfind()反向查找，不存在返回-1
#
# upper 转成大写
# lower 转成小写
# swapcase 大写转小写 小写转大写
# capitalize 将第一个字符串转大写，其余字符转小写
# title 每个单词的第一个字符转大写，其余字符转小写
# '''
# s1 = 'hello'
# print(s1.index('lo'))
# print(s1.rindex('lo'))
# print(s1.find('p'))
#
# s1 = 'hello world'
# print(s1.upper())
# print(s1.lower())
# print(s1.title())
# print(s1.capitalize())
#
# '''居中对齐'''
# print(s1.center(20, '*'))
# '''左对齐 宽度为20 宽度不够时默认用空格补齐'''
# print(s1.ljust(20, '*'))
# '''右对齐'''
# print(s1.rjust(20, '*'))
# ''' 右对齐 使用0进行填充'''
# print(s1.zfill(20))
#
# '''字符串的分隔'''
#
# arr = 'hello world python nihao'
# print(arr.split())  # 默认按照空格进行分隔
# arr = 'hello|world|python|nihao'
# print(arr.split('|'))  # 使用 | 作为分隔符
# print(arr.split('|', 2))  # 使用| 分隔 最多分2个
#
# #rsplit 从结尾开始分隔

# '''字符串替换'''
# s1 = 'hello python python python'
# print(s1.replace('python', 'Java'))
# print(s1.replace('python', 'Java', 1))  # 指定最大替换次数
#
# # 字符串的合并  调用该方法的字符串将作为元素之间的分隔。
# print('|'.join(['string', 'left', 'right']))
#
# '''字符串的比较'''
# s1 = 'hello'
# s2 = 'apple'
# print(s1 > s2)
# print(s1 < s2)
# print(ord('王'))  # ord获取原始值
#
# '''格式化字符串 % 占位符'''
# name = '张三'
# age = 20
# print('我叫%s，今年%d岁了' % (name, age))
#
# print('我叫{0}，今年{1}岁了'.format(name, age))
#
# print(f'我叫{name},今年{age}岁了')
#
# s = '离离原上草'
# # 编码
# print(s.encode(encoding='GBK'))
# byte = s.encode(encoding='GBK')
# print(s.encode(encoding='UTF-8'))
# # 解码
# print(byte.decode(encoding='GBK'))

# '''
# 函数的创建
# def 函数名 (参数):
#     函数体
# '''
#
#
# def add(a, b):
#     return a + b
#
#
# print(add(10, 20))  # 位置实参 根据形参对应的位置进行实参传递
# print(add(b=10, a=30))  # 关键字实参 根据形参名称进行实参传递
#
#
# def swap(x, y):
#     x, y = y, x
#
#
# x, y = 10, 20
# print('x', x)
# print('y', y)
# swap(x, y)
# print(x, y)

# # * 个数可变的位置参数 个数可变的位置参数只能有一个
# def fun(*args):
#     print(args)
#
#
# fun('hello', 'left', 'apple')
#
#
# # ** 可变的关键字参数 字典 个数可变的关键字参数只能有一个
# def fun(**args):
#     print(args)
#
#
# fun(a=10, b=20, c=30)
#
#
# # 以下情况报错
# # def fun2(*args1,*args2):
# #     pass
# # def fun3(**args1,**args2):
# #     pass
# # def fun4(**args1,*args2):
# #     pass
#
# # 当一个函数中存在 位置可变参数 和 关键字可变参数时，位置可变参数必须放在关键字可变参数的前面
# def fun5(*aged1, **ages4):
#     pass

# def fib(n):
#     if n < 3:
#         return 1
#     return fib(n - 1) + fib(n - 2)
#
# print(fib(6))
#
# for i in range(1,10):
#     print(fib(i))

# class Solution:
#     def removeElement(self, nums: List[int], val: int) -> int:
#         fast,slow = 0,0
#         while  fast < len(nums):
#             if nums[fast] != val:
#                 nums[slow] = nums[fast]
#                 slow+=1
#             fast += 1
#         return slow

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        index = 0
        maxindex = 1E9
        for i in range(0,len(strs)):
            maxindex = min(maxindex,len(strs[i]))
        ret = ''
        for i in range(0,maxindex):
            for j in range(0,len(strs)):
                if strs[j][i] != strs[0][i]:
                    return  ret
            ret += strs[0][i]
        return ret