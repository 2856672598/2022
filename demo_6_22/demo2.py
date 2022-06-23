# import requests
# '''
# response 对象的属性
# r.status_code: 请求的返回状态
# r.text         响应内容的字符串形式
# r.encoding     从HTTP中猜测的响应内容编码方式
# r.apparent_encoding  从内容中分析出的响应内容编码方式
# e.content         响应内容的二进制形式
# '''
# r = requests.get('http://www.baidu.com')
# print(r.status_code)
# print(r.headers)
# print(r.text)
# print(r.encoding)
# print(r.apparent_encoding)
# # timeout 超时时间
# # proxies 设置代理服务器
# print(requests.request('get','http://www.baidu.com'))

# import requests
# # url = 'https://www.hbdfxy.cn/information/detail/0/0/5631'
# url = 'https://www.amazon.cn/dp/B092N63YJS/ref=lp_2346073071_1_1?s=specialty-aps'
# kv = {'user-agent': 'Mozilla/5.0'}
# try:
#     r = requests.get(url, headers=kv)
#     r.raise_for_status()
#     r.encoding = r.apparent_encoding
#     print(r.text[:2000])
# except:
#     print('爬取失败')

# import requests
#
# url = 'https://www.so.com/s'
# kv = {'q': 'python'}
# try:
#     r = requests.get(url,kv)
#     print(r.status_code)
#     print(r.request.url)
#     r.raise_for_status() #状态码不为200抛异常
#     print(r.text)
# except:
#     print('爬取失败')

# import requests
# from bs4 import BeautifulSoup
#
# try:
#     url = 'https://www.hbdfxy.cn/'
#     r = requests.get(url)
#     r.raise_for_status()
#     demo = r.text
#     # BeautifulSoup(解析的内容，解析器)
#     '''
#     bs4的HTML解析器 'html.paeser'
#     lxml的HTML解析器 'lxml'
#     lxml的XML解析器 'xml'
#     html5lib的解析器 'html5lib'
#     '''
#     soup = BeautifulSoup(demo,'html.parser')
#     print(soup.prettify())
#     print(soup.title)
#     tag = soup.div
#     print(type(tag.attrs))#是一个字典
#     print(tag.attrs)#标签的属性
#     print(tag['href'])
#     print(soup.p.string)
# except:
#     print('爬取失败')

# from bs4 import  BeautifulSoup
# import requests
#
# url = 'https://www.bootcss.com/links/'
# r = requests.get(url)
# demp = r.text
# encodings = r.apparent_encoding
# soup = BeautifulSoup(demp,'html.parser')
# # print(soup.prettify())
# for link in soup.findAll('a'):
#     print(link)

# import requests
# import bs4
#
# url = 'https://www.shanghairanking.cn/rankings/bcur/2022'
# r = requests.get(url)
# r.raise_for_status()
# r.encoding = r.apparent_encoding
# soup = bs4.BeautifulSoup(r.text, 'html.parser')
# li = []
# for tr in soup.find('tbody').children:
#     if isinstance(tr, bs4.element.Tag):
#         tmp = tr('td')
#         # print(tmp[2].text) #当td标签中还嵌套其他标签时使用string会产生None
#         li.append([tmp[0].string, tmp[1].text.strip(), tmp[2].text])
#
# for item in li:
#     print(item[0], item[1], item[2])


# import requests
# import bs4
#
# try:
#     url = 'http://ww.baidu.com'
#     r = requests.get(url)
#     r.raise_for_status()
#     r.encoding = r.apparent_encoding
#     demo = r.text
#     sup = bs4.BeautifulSoup(demo, 'html.parser')
#     # 获取a标签
#     print(sup.a)
#     # 标签的名字
#     print(sup.a.name)
#     # 标签的属性
#     print(sup.a.attrs)
#     # NavigableString
#     print(sup.a.string)
# except:
#     print('爬取失败')


# import bs4
# sup = bs4.BeautifulSoup('<b><!--This is  a  comment--></b><p>This is a not comment</p>','html.parser')
# print(sup.b.string)
# print(type(sup.b.string))
# print(sup.p.string)
# print(type(sup.p.string))

# import bs4
# import requests
#
# url = 'https://www.baidu.com'
# r = requests.get(url)
# r.raise_for_status()
# r.encoding = r.apparent_encoding
# demo = r.text
# soup = bs4.BeautifulSoup(demo,'html.parser')
# li = soup.html.contents
# for item in li:
#     print(item)
#
# li = soup.html.children
# for item in li:
#     print(item)
# print('-------------------------------------')
# li = soup.html.descendants
# for item in li:
#     print(item)

# import requests
# from bs4 import BeautifulSoup
#
# try:
#     url = 'https://www.baidu.com/'
#     r = requests.get(url)
#     r.raise_for_status()
#     r.encoding = r.apparent_encoding
#     demo = r.text
#     soup = BeautifulSoup(demo, 'html.parser')
#
#     for item in soup.body.parents:
#         print(item.name)
# except:
#     print('爬取失败')

# 遍历
import requests
from bs4 import  BeautifulSoup
url = 'https://www.baidu.com/'

r = requests.get(url)
r.raise_for_status()
r.encoding = r.apparent_encoding
demo = r.text

soup = BeautifulSoup(demo,'html.parser')

for item in soup.head.next_siblings:
    print(item.name)
for item in soup.body.previous_siblings:
    print(item.name)