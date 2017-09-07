def recursion(a):
	if(len(a)<=1):
		return a
	else:
		return recursion(a[1:]) + a[0]

print ("Enter a string")
s = raw_input("")
print recursion(s)