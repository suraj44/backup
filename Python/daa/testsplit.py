import math
def splt(L):
	l = len(L)
	l = int(math.ceil(l*0.1))
	return L[l:-l]
a = eval(raw_input("enter:"))
print a
print splt(a)