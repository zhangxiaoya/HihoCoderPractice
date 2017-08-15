# 然而沼跃鱼早就看透了一切

题目地址在[http://hihocoder.com/problemset/problem/1082](http://hihocoder.com/problemset/problem/1082)

## 题目描述

fjxmlhx每天都在被沼跃鱼刷屏，因此他急切的找到了你希望你写一个程序屏蔽所有句子中的沼跃鱼(“marshtomp”，不区分大小写)。为了使句子不缺少成分，统一换成 “fjxmlhx” 。

## 输入
输入包括多行。

每行是一个字符串，长度不超过200。

一行的末尾与下一行的开头没有关系。

## 输出
输出包含多行，为输入按照描述中变换的结果。

## 样例输入
```
The Marshtomp has seen it all before.
marshTomp is beaten by fjxmlhx!
AmarshtompB
```
## 样例输出
```
The fjxmlhx has seen it all before.
fjxmlhx is beaten by fjxmlhx!
AfjxmlhxB
```

## 思路
这个比较简单，就是字符串替换，有点挑战的是忽略大小写比较，直接的思路就是用一个全部拷贝，转换成小写，进行比较，然后另外一个做结果，不过两个字符串都需要做替换，因为替换后的字符串的长度不一致。

必要容易出现问题的就是替换后的长度不一样，导致位置计算出错，还有下一个查找位置的偏移也是新的替换字符串的长度。

给的测试用例不全，可以自己写一个多个目标字符串的用例试一下，就能发现代码有问题。