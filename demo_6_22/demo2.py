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

import requests

# url = 'https://www.hbdfxy.cn/information/detail/0/0/5631'
url = 'https://www.amazon.cn/dp/B092N63YJS/ref=lp_2346073071_1_1?s=specialty-aps'
kv = {'user-agent': 'Mozilla/5.0'}
try:
    r = requests.get(url, headers=kv)
    r.raise_for_status()
    r.encoding = r.apparent_encoding
    print(r.text[:2000])
except:
    print('爬取失败')
