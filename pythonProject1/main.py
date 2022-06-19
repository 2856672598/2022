print("hello")
arr = [1, 2, 3, 4, 'hello', 'world']
for w in arr:
    print(w)
# 遍历数组
for i in range(len(arr)):
    print(i, arr[i])

# 0+1+2+3+4
print(sum(range(4)))

for i in range(10):
    if i % 2 == 0:
        print(i, '是偶数')
    else:
        print(i, "是奇数")

ret = 0
for i in range(10):
    if i % 2 == 0:
        ret += i
print(ret)

for i in range(10):
    if i == 5:
        break
    else:
        print(i)


# 函数的关键字是 def 函数名 (参数):

def Add(a, b):
    return a + b


print(Add(10, 20))


# match 函数 _被称为通配符必定会比配成功 相当于C++中的 default
def http_error(status):
    match status:
        case 400:
            return "Bad request"
        case 404:
            return "No found"
        case _:
            return "未知错误"


print(http_error(400))
print(http_error(4))

c = 10


def fun(a, b=[]):
    b.append(a)
    return b


print(fun(1))
print(fun(2))
print(fun(3))


def foo(name, **kwds):
    return name in kwds


print(foo('hello', **{'hello': 1}))

str4 = '王康宁'
print('id', id(str4))
print('类型', type(str4))
print('值', str4)
str4 = '孙尚香'
print('id', id(str4))

num = 0b101

print(num)
print(num,type(num))
print(1.1+2.2)
print(True+True,type(True+True)) # 2

# 三个引号可以换行
str1 ='人生苦短，我用python'
str2 ="人生苦短，我用python"
str3 = """人生苦短，
我用python"""
print(str1,type(str1))
print(str2,type(str2))
print(str3,type(str3))

print('hello'+'world')

i = 10
print(str(i), type(str(i)))
print(float(i), type(float(i)))

# 单行注释

'''我是多行注释哦
哈哈
'''

