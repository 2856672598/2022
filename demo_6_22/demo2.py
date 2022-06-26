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

# # 遍历
# import requests
# from bs4 import  BeautifulSoup
# url = 'https://www.baidu.com/'
#
# r = requests.get(url)
# r.raise_for_status()
# r.encoding = r.apparent_encoding
# demo = r.text
#
# soup = BeautifulSoup(demo,'html.parser')
#
# for item in soup.head.next_siblings:
#     print(item.name)
# for item in soup.body.previous_siblings:
#     print(item.name)

# # 正则表达式
# import re
#
# # match = re.search(r'[1-9]\d{5}','北京市 123981')
# # if match:
# #     print(match.group(0))
#
# #math = re.match(r'[1-9]\d{5}','123981hello')
# #match = re.findall(r'[1-9]\d{5}','123981hello 123456')
# #match = re.split(r'[1-9]\d{5}','123981hello123456')
# # if match:
# #     print(match)
#
# # match = re.finditer(r'[1-9]\d{5}','123981hello123456')
# # for item in match:
# #     print(item.group(0))
#
# math = re.sub(r'[1-9]\d{5}','1111','123981hello123456')
# print(math)

# import re
#
# s = """
# <div class = '孙悟空'><span id = '1'>孙悟空</span></div>
# <div class = '猪八戒'><span id = '2'>猪八戒</span></div>
# <div class = '唐僧'><span id = '3'>唐僧</span></div>
# <div class = '沙悟净'><span id = '1'>沙悟净</span></div>
# """
#
# # match = re.finditer(r"<div class = '.*?'><span id = '\d+'>.*?</span></div>", s)
# # for it in match:
# #     print(it.group(0))
#
# match = re.finditer(r"<div class = '.*?'><span id = '\d+'>(?P<name>.*?)</span></div>", s)
# for it in match:
#     print(it.group('name'))

# import re
# import requests
#
# try:
#     url = 'https://movie.douban.com/chart'
#     header = {
#         'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) '
#                       'Chrome/102.0.0.0 Safari/537.36 '
#     }
#     r = requests.get(url, headers=header)
#     r.raise_for_status()
#     r.encoding = r.apparent_encoding
#     demo = r.text
#     match = re.finditer(r'<div class="pl2">.*?'
#                         r' <a href=.*? class="">(?P<name>.*?)(/|<).*?'
#                         r'<span class="rating_nums">(?P<score>.*?)</span>.*?'
#                         r'<span class="pl">(?P<evaluation>.*?)</span>', demo, re.S)
#     for it in match:
#         dic = it.groupdict()
#         dic['name'] = dic['name'].strip()
#         print(dic)
#     r.close()
# except:
#     print('爬取失败')
import tempfile
import textwrap

import requests
import re

# try:
#     goods = '手机'
#     url = 'https://search.jd.com/Search?keyword=' + goods
#     header = {
#         'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) '
#                       'Chrome/102.0.0.0 Safari/537.36 '
#     }
#     r = requests.get(url, headers=header)
#     r.raise_for_status()
#     print(r.request.url)
#     r.encoding = r.apparent_encoding
#     demo = r.text
#     match = re.finditer(r'<li data-sku=.*? data-spu=.*? ware-type="10"   class="gl-item">.*?'
#                         r'<div class="p-name p-name-type-2">.*?'
#                         r'<em>(?P<name>.*?)<', demo, re.S)
#     for it in match:
#         print(it.group('name').strip())
#     with open('code.txt','w',encoding='utf-8') as file:
#         file.write(demo)
# except:
#     print('爬取失败')

# import requests
# import re
#
# try:
#     child_url_list = []
#     domain = 'https://www.dy2018.com/'
#     r = requests.get(domain)
#     r.raise_for_status()
#     r.encoding = r.apparent_encoding
#     demo = r.text
#     obj1 = re.compile(r'2022必看热片.*?<ul>(?P<ul>.*?)</ul>', re.S)
#     obj2 = re.compile(r'<li><a href=\'(?P<child_url>.*?)\' title', re.S)
#     obj3 = re.compile(r'◎片　　名(?P<name>.*?)<br />'
#                       r'.*?<td style="WORD-WRAP: break-word" bgcolor="#fdfddf"><a href="(?P<down>.*?)">', re.S)
#     r1 = obj1.finditer(demo)
#     for item in r1:
#         # 提取子页面的链接
#         ul = item.group('ul')
#         child = obj2.finditer(ul)
#         for url in child:
#             child_url_list.append(domain + url.group('child_url'))
#
#     # 对子页面进行爬取
#     for item in child_url_list:
#         r = requests.get(item)
#         r.raise_for_status()
#         r.encoding = r.apparent_encoding
#         r2 = obj3.search(r.text)
#         print(r2.group('name'))
#         print(r2.group('down'))
# except:
#     print('爬取失败')

# 解析数据
# find(标签，属性=值)
# find_all(标签，属性=值)

# import requests
# import bs4
#
# try:
#     domain = 'https://www.umei.cc/'
#     url = 'https://www.umei.cc/bizhitupian/fengjingbizhi'
#     r = requests.get(url)
#     r.raise_for_status()
#     r.encoding = r.apparent_encoding
#     soup = bs4.BeautifulSoup(r.text, 'html.parser')
#     li = soup.find('div', class_='swiper-wrapper after').findAll('a')
#     child_url_list = []
#     for item in li:
#         child_url = domain + item.get('href')
#         child_response = requests.get(child_url)
#         child_response.raise_for_status()
#         child_response.encoding = child_response.apparent_encoding
#         page = bs4.BeautifulSoup(child_response.text, 'html.parser')
#         li = page.find('section', class_='img-content').find('img')
#         down = li.get('src')
#         print(down)
#         # 下载图片
#         img_response = requests.get(down)
#         img_response.raise_for_status()
#         file_name = down.split('/')[-1]
#         print(file_name)
#         with open(file_name, mode='wb') as file:
#             file.write(img_response.content)
# except:
#     print('爬取失败')

'''
xpath
'''

xml = """
<book>
    <p>野花遍地香</p>
    <price>1.23</price>
    <nick>臭豆腐</nick>
    <author>
        <nick id = '10086'>周大强</nick>
        <nick id = '10010'>周芷若</nick>
        <nick class = 'joy'>周杰伦</nick>
        <nick class = 'join'>蔡依林</nick>
        <div>
            <nick> hello world </nick>
        </div>
        <span> hello python </span>
    </author>
</book>
"""
from lxml import etree

tree = etree.XML(xml)
# result = tree.xpath("/book")
# result = tree.xpath("/book/p/text()") # text()用于获取文本
result = tree.xpath("/book/author/nick/text()")
result = tree.xpath("/book/author//nick/text()")  # //后代
result = tree.xpath("/book/author/*/nick/text()")  # /*/ 匹配任意节点，通配符
result = tree.xpath("/book//nick/text()")
print(result)
