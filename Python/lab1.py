from tkinter import *
import conversion
import tkinter.messagebox as box


def to_four(event):
    try:
        res.config(text=conversion.forward(float(ent1.get()))[:15])
    except ValueError:
        box.showwarning("Error", "There is wrong value")



def to_ten(event):
    try:
        res.config(text="{:8g}".format(float(conversion.backward(float(ent1.get())))))
    except ValueError:
        box.showwarning("Error", "There is wrong value")


def clear_enter(event):
    ent1.delete(0, len(ent1.get()))


def clear_res(event):
    res.config(text="")


def clear(event):
    clear_res(event)
    clear_enter(event)


def about():
    box.showinfo("About", "The program converts numbers from decimal to quaternary and vice versa. Program author "
                          "Andrey Dubov")


def add(num):
    ent1.insert(ent1.index(INSERT), str(num))


window = Tk()
window.title('Conversion')
window.geometry('400x480+100+200')

enter = Label(window, text="Enter your number:")
enter.grid(row=0, column=0)
ent1 = Entry(width=20)
ent1.grid(row=0, column=1)
clear_enter_btn = Button(window, text="Clear entry field")
clear_enter_btn.grid(row=0, column=2)
clear_enter_btn.bind('<Button-1>', clear_enter)

forward = Button(window, text='transfer to 4')
forward.grid(row=1, column=0, pady=10, padx=30)
backward = Button(window, text='transfer to 10')
backward.grid(row=1, column=1, pady=10, padx=30)
clear_all_btn = Button(window, text="Clear all fields")
clear_all_btn.grid(row=1, column=2)
clear_all_btn.bind('<Button-1>', clear)
forward.bind('<Button-1>', to_four)
backward.bind('<Button-1>', to_ten)

res_label = Label(window, text="Result:")
res_label.grid(row=2, column=0)
res_label.bind('<Button-1>', about)
res = Label(window, text="", anchor=CENTER, relief=SUNKEN, width=17)
res.grid(row=2, column=1)
clear_enter_btn = Button(window, text="Clear result field")
clear_enter_btn.grid(row=2, column=2)
clear_enter_btn.bind('<Button-1>', clear_res)

window.bind('<Alt-c>', clear)
window.bind('<Alt-r>', clear_res)
window.bind('<Alt-e>', clear_enter)
window.bind('<Alt-f>', to_four)
window.bind('<Alt-t>', to_ten)

mmenu = Menu(window)
fmenu = Menu(mmenu)
fmenu.add_command(label='Quit (Alt+F4)', command=window.quit)
mmenu.add_cascade(label='File', menu=fmenu)
emenu = Menu(mmenu)
emenu.add_command(label='Transfer to 4 (Alt+F)', command=to_four)
emenu.add_command(label='Transfer to 10 (Alt+T)', command=to_ten)
emenu.add_separator()
emenu.add_command(label='Clear all fields (Alt+C)', command=clear)
emenu.add_command(label='Clear result field (Alt+R)', command=clear_res)
emenu.add_command(label='Clear enter field (Alt+T)', command=clear_enter)
mmenu.add_cascade(label='Edit', menu=emenu)
hmenu = Menu(mmenu)
hmenu.add_command(label='About', command=about)
mmenu.add_cascade(label='Help', menu=hmenu)

window.config(menu=mmenu)

one = Button(window, text='1', command=lambda: add(1), width=15, height=4)
one.grid(row=3, column=0, pady=(20, 0))
two = Button(window, text='2', command=lambda: add(2), width=15, height=4)
two.grid(row=3, column=1, pady=(20, 0))
three = Button(window, text='3', command=lambda: add(3), width=15, height=4)
three.grid(row=3, column=2, pady=(20, 0))
four = Button(window, text='4', command=lambda: add(4), width=15, height=4)
four.grid(row=4, column=0, pady=(20, 0))
five = Button(window, text='5', command=lambda: add(5), width=15, height=4)
five.grid(row=4, column=1, pady=(20, 0))
six = Button(window, text='6', command=lambda: add(6), width=15, height=4)
six.grid(row=4, column=2, pady=(20, 0))
seven = Button(window, text='7', command=lambda: add(7), width=15, height=4)
seven.grid(row=5, column=0, pady=(20, 0))
eight = Button(window, text='8', command=lambda: add(8), width=15, height=4)
eight.grid(row=5, column=1, pady=(20, 0))
nine = Button(window, text='9', command=lambda: add(9), width=15, height=4)
nine.grid(row=5, column=2, pady=(20, 0))
zero = Button(window, text='0', command=lambda: add(0), width=15, height=4)
zero.grid(row=6, column=1, pady=(20, 0))


window.mainloop()
