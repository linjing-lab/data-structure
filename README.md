# 数据结构与算法

参考书籍：清华大学计算机系列课程 数据结构（C语言版） 严蔚敏著
> 学习顺序：绪论（√） → 线性表（√） → 栈与队列（√） → 串（√） → 数组和广义表 → 树和二叉树 → 图 → （动态存储管理） → 查找 → 内排序（外排序） → 文件

![](https://img.shields.io/badge/Editor-Sublime_Text-informational?style=flat&logo=sublime-text&logoColor=white&color=2bbc8a)&emsp;![](https://img.shields.io/badge/Tool-Git-informational?style=flat&logo=git&logoColor=white&color=2bbc8a)&emsp;![](https://img.shields.io/badge/Code-C-informational?style=flat&logo=c&logoColor=white&color=2bbc8a)

## 第一章：绪论
|抽象数据类型或算法|代码|
|--|--|
|三元组|[triplet](./preface/triplet.cpp)|
|复数|[complex](./preface/complex.cpp)|
|有理数|[rational_number.cpp](./preface/rational_number.cpp)|
|三元素最大值|[max3](./preface/max3.cpp)|
|降序排序三元素|[descend3](./preface/descend3.cpp)|

### 1.1 [基本概念和术语](./preface/基本概念与术语.md)
### 1.2 [抽象数据类型的表示与实现](./preface/抽象数据类型的表示与实现.md)
### 1.3 [算法和算法分析](./preface/算法和算法分析.md)
### 1.4 [习题与解答](./preface/习题与解答.md)

## 第二章：线性表
|抽象数据类型或算法|代码|
|--|--|
|顺序表|[SqList](./linear-list/sq_list.cpp)|
|单链表|[LinkList](./linear-list/link_list.cpp)|
|集合运算的算法|[SLinkList](./linear-list/slink_list.cpp)|
|一元多项式|[Polynomial](./linear-list/polynomial.cpp)|

### 2.1 [线性表的类型定义](./linear-list/线性表的类型定义.md)
### 2.2 [线性表的顺序表示和实现](./linear-list/线性表的顺序表示和实现.md)
### 2.3 [线性表的链式表示和实现](./linear-list/线性表的链式表示和实现.md)
### 2.4 [习题与解答](./linear-list/习题与解答.md)

## 第三章：栈
|抽象数据类型或算法|代码|
|--|--|
|顺序存储结构|[SqStack](./stack/sq_stack.cpp)|
|链式存储结构|[LinkStack](./stack/link_stack.cpp)|
|数制转换|[conversion](./stack/conversion.cpp)|
|括号匹配|[Parenthesis_Match](./stack/parenthesis_match.cpp)|
|hanoi的递归实现|[hanoi](./stack/hanoi.cpp)|

### 3.1 [抽象数据类型的定义](./stack/抽象数据类型栈的定义.md)
### 3.2 [栈与递归的实现](./stack/栈与递归的实现.md)
### 3.3 [习题与解答](./stack/习题与解答.md)

## 第四章：队列
|抽象数据类型或算法|代码|
|--|--|
|单链队列|[LinkQueue](./queue/link_queue.cpp)|
|循环队列|[Circular_Queue](./queue/circular_queue.cpp)|

### 4.1 [抽象数据类型队列的定义](./queue/抽象数据类型队列的定义.md)
### 4.2 [循环队列-队列的顺序表示和实现](./queue/循环队列-队列的顺序表示和实现.md)
### 4.3 [习题与解答](./queue/习题与解答.md)

## 第五章：串