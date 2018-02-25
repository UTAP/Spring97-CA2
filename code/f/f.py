#!/usr/bin/env python3


def m(a):
    m.coef *= -1
    return a * m.coef
m.coef = -1


def main():
    int(input())
    print(sum([m(int(i)) for i in input().split()]))


if __name__ == '__main__':
    main()
