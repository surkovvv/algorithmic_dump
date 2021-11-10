def foo(a, k):
    if k == 0:
        return 1
    if k % 2 == 0:
        return foo(a ** 2, k / 2)
    else:
        return a * foo(a, k - 1)

a = float(input())
n = int(input())
print(foo(a, n))
