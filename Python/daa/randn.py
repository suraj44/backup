import random
import time
import datetime
import math
from bisect import bisect_left
import csv
L = random.sample(range(1,100), 10)


def partition(a,l,r):
	
	i =l-1
	pivot = r
	#pivot = pseudomedian(A)
	for j in range(l,r):
		if a[j]< a[pivot]:
			i+=1
			a[i],a[j] = a[j], a[i]
	a[pivot], a[i+1] = a[i+1], a[pivot]

	return (i+1)
def quicksort(a,l,r):
	if(l<r):
		pivot = partition(a,l,r)
		quicksort(a,l,pivot-1)
		quicksort(a,pivot+1,r)


def median(A):
	l = len(A)
	m = 0
	# if(l%2!=0):
	# 	m= A[int(math.ceil(l/2))]
	# else:
	# 	m =  int((A[l/2] + A[(l/2)-1])/2)
	#print A
	#print math.ceil(l/2)
	return A[int(math.ceil(l/2))]

def pseudomedian(A):
	n = len(A)
	s = int(math.ceil(n/5.0))
	j = 0
	M = []
	for i in range(0,s):
		beg = i *5 
		end = min(len(A), beg + 5)
		tmp = A[beg:end]
		if len(tmp)==0:
			break
		tmp.sort()
		M.append(median(tmp))
	M.sort()
	return median(M)

	

def mediansort(a, k):
	#a = a[l:r+1]
	#print "full array:" , a
	pivot = pseudomedian(a)
	#print "pivot" , pivot
	#pivot = a.index(pivot)
	a_less = []
	a_equal = []
	a_great = []
	for i in a:
		#print i 
		if i < pivot:
			a_less.append(i)
		elif i > pivot:
			a_great.append(i)
		else:
			a_equal.append(i)
	#print "split:", a_less, a_equal, a_great
	#print "k:", k
	time.sleep(0.1)
	if(k<len(a_less)):
		mediansort(a_less, k)
	if (k < len(a_less) + len(a_equal)):
		return a_equal[0]
	else:
		normalized_k = k - (len(a_less) + len(a_equal))
		mediansort(a_great, normalized_k)

	# for j in range(l,r):
	# 	if a[j]<= a[pivot]:
	# 		i+=1
	# 		a[i],a[j] = a[j], a[i]
	# a[pivot], a[i+1] = a[i+1], a[pivot]
	# pivot = (i+1)
	# print a, a[pivot], r ,l 
	# if(k<=pivot-1):
	# 	mediansort(a,l,pivot-1,k)
	# elif (k <= pivot):
	# 	return a[pivot]
	# else:
	# 	return mediansort(a,pivot+1, r, k)

print L
t  = L
#t.sort()

#print t
mediansort(L,1 )

print mediansort(L,1 )




# start = time.time()
# quicksort(L,0,len(L)-1)
# end = time.time()
# print end-start
# print L

a = 10000
b = a/10


with open("hi2.csv", "w") as f:
	for i in range(1):
		print i
		#print "\n\n\n"
		a += a/2
		b += b/2
		L  = random.sample(range(0,125000000),12500000)
		start = time.time()
		quicksort(L,0,len(L)-1)
		end = time.time()
		q = end - start
		#print "quicksort:", end-start
		#print a 
		random.shuffle(L)
		e = random.randint(0, len(L))
		start = time.time()
		mediansort(L, e)
		end = time.time()
		med = end - start
		#print "median sort", end-start
		csv = str(b) + ";" + str(q) + ";" +  str(med)+ "\n"
		f.write(csv)