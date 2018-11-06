#!/usr/bin/python3

def myfunc(a,b) :
    print(a, b)

class student:
    self.myname = 'pipi'
    self.age = 0
    def get_age():
        return self.age
    
    def get_name():
        return self.myname

print("Hello world!")

a = 5;

if a > 3:
    print("switch a")
elif a == 3:
    print("switch b")
else :
    print("switch c")

while a < 100 :
    print("a =", a)
    a+=1
else :
    print("while loop end!")

import os

print(os.getcwd())

os.system("cat test.py")

os.chdir("../../")

filelist = os.listdir()

for filename in filelist :
    print(filename)

kk = 'test a'
ss = 'test b'
myfunc(kk, ss)

my_stu = student()

my_stu.name = 'xixi'
my_stu.age = 4

#print(my_stu.get_name())
print(my_stu.get_age())
