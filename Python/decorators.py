# def a():
# 	def b():
# 		return "Hello"
# 	return b
# print a
# c = a()2
# print c()

# def compose_greet_func():
#     def get_message():
#         return "Hello there!"

#     return get_message

# greet = compose_greet_func()
# print greet()



# def dec(func):
# 	def lol(nam):
# 		return func(nam)  + " Have a nice day!"
# 	return lol





# @dec
# def inn(nam):
# 	return "Psych scene, " + nam

# print inn("Suraj")

import timeit
start_time = timeit.default_timer()
# code you want to evaluate



def memory(func):

	cache = {}
	def inner(n):
		cache[n] = func(n)
		return cache[n]

	return inner
@memory

def fact(n):
	if n==0:
		return 1
	return n*fact(n-1)

print fact(49)
elapsed = timeit.default_timer() - start_time
print elapsed