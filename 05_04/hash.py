#!/Library/Frameworks/Python.framework/Versions/3.5/bin/python3
# -*- codeing:utf-8 -*-
# from math import sqrt, floor


def hash(string):
    if len(string) == 1:
        string = ' ' + string
    # sum_0 = 0
    # sum_1 = 0
    # sum_2 = 0

    # for i in xrange(len(string) - 1):
    #     sum_0 += floor(sqrt(ord(string[i]) + ord(string[i + 1])))
    #     sum_1 += (ord(string[i]) ** 2 / 2) + ord(string[i + 1]) ** 2
    #     sum_2 += ord(string[i]) ** 3 + ord(string[i + 1]) ** 3

    # return floor(sum_0 ** 2 + sum_1 ** 2 + sum_2 ** 2)
    return string[0] #+ string[1]


if __name__ == '__main__':
    freq = {}
    f = open('/usr/share/dict/words', 'rb')
    words = f.read()
    f.close()
    words = words.split('\n')
    max_key = 0
    collide = 0
    print 'tested on ' + str(len(words)) + ' words'

    for i in words[:-1]:
        key = hash(i)
        if key in freq:
            freq[key] += 1
            if freq[key] >= 1:
                print 'clide on ' + i
                collide += 1
        else:
            freq[key] = 0
        if max_key < freq[key]:
            max_key = freq[key]

    print freq
    print 'collide ' + str(collide) + ' times'
    print 'maximun is ' + str(max_key)
