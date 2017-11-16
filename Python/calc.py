from Tkinter import *
import sys

#######################################

def clear():
	display.delete(0,END)
	return















#######################################

root = Tk()
frame = Frame(root)
frame.pack()

root.title("Calculator")

n1 = StringVar()

topframe = Frame(root)
topframe.pack(side = TOP)

display= Entry(frame,textvariable = n1, bd = 20, insertwidth = 1, font = 30)
display.pack(side= TOP)


b1 = Button(topframe, padx = 16, pady = 16 , bd = 8, text = "7", fg = "black")
b1.pack(side = LEFT)
b2 = Button(topframe, padx = 16, pady = 16 , bd = 8, text = "8", fg = "black")
b2.pack(side = LEFT)
b3 = Button(topframe, padx = 16, pady = 16 , bd = 8, text = "9", fg = "black")
b3.pack(side = LEFT)
b4 = Button(topframe, padx = 16, pady = 16 , bd = 8, text = "/", fg = "black")
b4.pack(side = LEFT)



f1 = Frame(root)
f1.pack(side =TOP)


b1 = Button(f1, padx = 16, pady = 16 , bd = 8, text = "4", fg = "black")
b1.pack(side = LEFT)
b2 = Button(f1, padx = 16, pady = 16 , bd = 8, text = "5", fg = "black")
b2.pack(side = LEFT)
b3 = Button(f1, padx = 16, pady = 16 , bd = 8, text = "6", fg = "black")
b3.pack(side = LEFT)
b4 = Button(f1, padx = 16, pady = 16 , bd = 8, text = "*", fg = "black")
b4.pack(side = LEFT)



f2 = Frame(root)
f2.pack(side =TOP)

b1 = Button(f2, padx = 16, pady = 16 , bd = 8, text = "1", fg = "black")
b1.pack(side = LEFT)
b2 = Button(f2, padx = 16, pady = 16 , bd = 8, text = "2", fg = "black")
b2.pack(side = LEFT)
b3 = Button(f2, padx = 16, pady = 16 , bd = 8, text = "3", fg = "black")
b3.pack(side = LEFT)
b4 = Button(f2, padx = 16, pady = 16 , bd = 8, text = "-", fg = "black")
b4.pack(side = LEFT)

f3 = Frame(root)
f3.pack(side =TOP)

b1 = Button(f3, padx = 16, pady = 16 , bd = 8, text = "0", fg = "black")
b1.pack(side = LEFT)
b2 = Button(f3, padx = 16, pady = 16 , bd = 8, text = "C", fg = "black", command = clear)
b2.pack(side = LEFT)
b3 = Button(f3, padx = 16, pady = 16 , bd = 8, text = "+", fg = "black")
b3.pack(side = LEFT)
b4 = Button(f3, padx = 16, pady = 16 , bd = 8, text = "=", fg = "blue")
b4.pack(side = LEFT)

root.mainloop()
