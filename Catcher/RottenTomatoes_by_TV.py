#!/usr/bin/env python
# -*- coding=utf-8 -*-
import sys
import os
import urllib
from bs4 import BeautifulSoup
reload(sys)
sys.setdefaultencoding('utf-8')
def get_html(url):  #通过url获取网页内容
    result = urllib.urlopen(url)
    return result.read()
    # save_file(result.read(), 'thefile.txt')
def get_movie_all(html):     #通过soup提取到每个电影的全部信息，以list返回
    soup = BeautifulSoup(html,"html.parser")
    movie_1 = soup.find_all('ul', class_="content-meta info")
    movie_2=soup.find_all('title')
    movie_3=soup.find_all('div', class_="castSection ")
    movie_4=soup.find_all('div', id="scoreStats" ,class_="hidden-xs")
    movie_5=soup.find_all('span', class_="meter-value superPageFontColor")
    movie_6=soup.find_all('img',class_="posterImage")
    movie_str=str(movie_1[0])+str(movie_2[0])+str(movie_3[0])+str(movie_4[0])+str(movie_5[0])+str(movie_6[0])
    movie=[movie_str]
    return movie
def get_movie_one(movie,name):
    result = []  # 用于存储提取出来的电影信息
    soup_all = BeautifulSoup(str(movie),"html.parser")
    title = soup_all.find_all('title')
    soup_title = BeautifulSoup(str(title[0]),"html.parser")
    for line in soup_title.stripped_strings:  # 对获取到的<a>里的内容进行提取
        result.append(line)
    result_str=" | Fresh: "

    fresh=soup_all.find_all('span', class_="meter-value superPageFontColor")
    soup_fresh=BeautifulSoup(str(fresh[0]),"html.parser")
    for line in soup_fresh.stripped_strings:
        result_str=result_str+line

    rating=soup_all.find_all('div', class_="superPageFontColor")
    soup_rating=BeautifulSoup(str(rating[0]),"html.parser")
    for line in soup_rating.stripped_strings:
        result_str=result_str+line
    result_str=result_str+" | Actor: "

    actor=soup_all.find_all('a', class_="unstyled articleLink")
    for it_actor in actor:
        soup_actor = BeautifulSoup(str(it_actor),"html.parser")
        for line in soup_actor.stripped_strings:
            result_str = result_str + line + " "

    info=soup_all.find_all('li' ,class_="meta-row clearfix")
    for it_info in info:
        soup_info=BeautifulSoup(str(it_info),"html.parser")
        for line in soup_info.stripped_strings:
            result_str=result_str+line+" "

    os.chdir(os.path.join(os.getcwd(), '改路径'))
    
    post = soup_all.find('img',class_="posterImage")
    if(post!=None):
        pic_name = name.replace(' ','_') + str(0) + '.jpg'
        link = post.get('src')

        urllib.urlretrieve(link, pic_name)



    os.chdir(r'改路径啊！！！')
    result.append(result_str)



    return result  #返回获取到的结果
def save_file(text, filename):  #保存网页到文件
    f= open(filename,'ab')
    f.write(bytes(text))
    f.close()
def read_file(filename):  #读取文件
    f = open(filename,'r')
    text = f.read()
    f.close()
    return text
def work():
    try:
        f = open('/home/monell/qtcode/build-InfoCS-Desktop_Qt_5_10_1_GCC_64bit-Debug/RottenTomatoes_by_TV.txt', 'r')

        content=f.read()
        name=content[0:-1]
        name=name.rstrip().replace(' ','_')
        i=content[-1]
    finally:
        if f:
            f.close()
            w = open('/home/monell/qtcode/build-InfoCS-Desktop_Qt_5_10_1_GCC_64bit-Debug/RottenTomatoes_by_TV.txt', 'w')
            w.truncate()
            w.close()
        url = 'https://www.rottentomatoes.com/tv/'+name+'/s0'+str(i)
        html = get_html(url)
        movie_list = get_movie_all(html)
        for movie in movie_list:  # 将每一页中的每个电影信息放入函数中提取
            result = get_movie_one(movie,name)
            text = '' + 'TV：' + str(result[0])  + str(result[1]) + '\n' + '\t'
            save_file(text, '/home/monell/qtcode/build-InfoCS-Desktop_Qt_5_10_1_GCC_64bit-Debug/RottenTomatoes_by_TV.txt')


if __name__=='__main__':
   work()
