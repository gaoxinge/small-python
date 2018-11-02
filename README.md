# small-python

## platform

- win10
- mingw

## usage

```
> g++ -o main main.cc Objects/PyTypeObject.cc Objects/PyDictObject.cc Objects/PyIntObject.cc Objects/PyStrObject.cc -I Include
> main
********** Python Research **********
>>> a = 1
>>> b = 2
>>> c = a+b
>>> print c
3
>>> s1 = "Robert "
>>> s2 = "Python"
>>> s3 = s1+s2
>>> print s3
Robert Python
>>>
```

## reference

- [Python源码剖析](https://book.douban.com/subject/3117898/)
- [（Python学习6）Small Python](https://blog.csdn.net/efeics/article/details/9249455)