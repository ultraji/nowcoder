#!/usr/bin/python3

import os
import re

keyword_url = {
    'map':'',
    '字符串':'',
    '完全二叉树':'',
    'AVL树':'',
    '动态规划':'',
    '贪心':'',
    '背包问题':'',
    '并查集':'',
    'BST':'',
    '前中后序遍历':'',
    'hash数组':'',
    '层序遍历':'', 
    '快排':'',
    'DFS':'',
    'BFS':'',
    'Dijkstra算法':'https://ultraji.xyz/2019/06/algorithm_dijkstra.html'
}

## 查找目录中的代码文件（按文件名排序）
# @param    path    代码文件目录
# @return   代码文件的迭代对象
def _find_code_file(path):
    fname_rules = r'.*?\.(h|c|hh|cpp|java)$'
    files = os.listdir(path)
    files.sort()
    for name in files:
        if re.match(fname_rules, name):
            tmp = os.path.join(path, name)
            yield tmp

## 创建表格一行
# @param    path    解题CPP文件路径
# @return   markdown格式的一行表格
def _creat_table_row(path):
    row_str = ""
    with open(path, 'r', encoding='utf8') as tmp:
        id_title = str(tmp.readline())
        keywords = str(tmp.readline())
    id, title = id_title[3:7],id_title[8:-1]
    row_str = "| "+ id + " | " + title + " | " + "[Accepted](" + path + ")" + " | "
    if keywords.find("keywords:") != -1:
        for keyword in keywords[13:-1].split('、'):
            print(keyword)
            if not keyword in keyword_url:
                keyword_url[keyword] = " "
            row_str += "[" + keyword + "](" + keyword_url[keyword] + ")" + "、"
    row_str +=  " |\n"
    return row_str

## 创建4栏表格
# @param    path    文件夹路径
# @return   void
def _creat_table(table_name, table_tab, path):
    readme = open("README.md", 'a', encoding='utf8')
    readme.write("## " + table_name + "\n\n")
    for tab in table_tab:
        readme.write("| " + tab + " ")        
    readme.write("|\n")
    readme.write("|---|---|---|---|\n")    
    for fp in _find_code_file(path):
        readme.write( _creat_table_row(fp) )
    readme.write("\n")
    readme.close()



if __name__ == '__main__':
    with open("README.md", 'w', encoding='utf8') as readme:
        readme.write("# 牛客网题解\n\n只为写一份简单易懂的代码。\n\n")
    _creat_table("华为", ["ID","Title","C/C++","Keywords"], "huawei")