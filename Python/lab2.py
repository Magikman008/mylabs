import numpy as np
import roots
from tkinter import *
import tkinter.messagebox as box
from tkinter.ttk import *
from math import *

import matplotlib

matplotlib.use("TkAgg")
from matplotlib.figure import Figure
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg


def find_roots(event):
    table.delete(*table.get_children())
    try:
        result = roots.finder(ent1.get(), float(ent2.get()), float(ent3.get()), float(ent4.get()), float(ent5.get()),
                              float(ent6.get()))
        for i in result:
            if i[5] == 1:
                table.insert(parent='', index='end', text='',
                             values=(i[0], i[1], i[2], i[3], i[4], i[5]))
            else:
                table.insert(parent='', index='end', text='',
                             values=(i[0], i[1], "{:5g}".format(float(i[2])), "{:.2g}".format(float(i[3])), i[4], i[5]))
        figure.clear(True)
        plt = figure.add_subplot(1, 1, 1)
        xx = np.linspace(float(ent2.get()), float(ent3.get()), 100)
        y = []
        for i in xx:
            y.append(eval(ent1.get(), globals(), {"x": i}))
        plt.plot(xx, y, 'r', label='$' + ent1.get() + '$')
        plt.grid(True)
        plt.axhline(y=0)
        plt.axvline(x=0)
        tmpx = []
        tmpy = []
        for i in result:
            if i[5] == 0:
                tmpx.append(i[2])
                tmpy.append(i[3])
        xr, yr, xr2, yr2 = roots.derivative(ent1.get(), float(ent2.get()), float(ent3.get()), float(ent4.get()),
                                  float(ent5.get()), float(ent6.get()))
        plt.plot(tmpx, tmpy, 'go', label="Roots")
        plt.plot(xr, yr, 'bo', label="Extremums")
        plt.plot(xr2, yr2, 'mo', label="Inflections")
        plt.legend()
        canvas = FigureCanvasTkAgg(figure, window)
        canvas.get_tk_widget().grid(row=4, column=8, rowspan=60)
    except ValueError:
        box.showwarning("Error", "There is some wrong values")


def clear(event):
    ent1.delete(0, len(ent1.get()))
    ent2.delete(0, len(ent2.get()))
    ent3.delete(0, len(ent3.get()))
    ent4.delete(0, len(ent4.get()))
    ent5.delete(0, len(ent5.get()))
    ent6.delete(0, len(ent6.get()))
    table.delete(*table.get_children())
    figure.clear(True)
    canvas = FigureCanvasTkAgg(figure, window)
    canvas.get_tk_widget().grid(row=4, column=8, rowspan=60)


def on_focus(evt):
    global current_entry
    current_entry = evt.widget


def about():
    box.showinfo("About", "The program converts numbers from decimal to quaternary and vice versa. Program author "
                          "Andrey Dubov")


def add(num):
    if current_entry is not None:
        current_entry.insert(current_entry.index(INSERT), str(num))


def dell(event):
    if current_entry is not None:
        current_entry.delete(current_entry.index(INSERT) - 1, current_entry.index(INSERT))


current_entry = None
window = Tk()
window.title('Conversion')
window.geometry('1100x650+50+100')

enter = Label(window, text="Enter your expression:")
enter.grid(row=0, column=0)
ent1 = Entry(width=20)
ent1.bind('<FocusIn>', on_focus)
ent1.grid(row=0, column=1)

enter = Label(window, text="Enter your left limit:")
enter.grid(row=1, column=0)
ent2 = Entry(width=20)
ent2.bind('<FocusIn>', on_focus)
ent2.grid(row=1, column=1)

enter = Label(window, text="Enter your right limit:")
enter.grid(row=2, column=0)
ent3 = Entry(width=20)
ent3.bind('<FocusIn>', on_focus)
ent3.grid(row=2, column=1)

enter = Label(window, text="Enter your step:")
enter.grid(row=3, column=0)
ent4 = Entry(width=20)
ent4.bind('<FocusIn>', on_focus)
ent4.grid(row=3, column=1)

enter = Label(window, text="Enter your maximum \nnumber of iterations:")
enter.grid(row=4, column=0)
ent5 = Entry(width=20)
ent5.bind('<FocusIn>', on_focus)
ent5.grid(row=4, column=1)

enter = Label(window, text="Enter your epsilon:")
enter.grid(row=5, column=0)
ent6 = Entry(width=20)
ent6.bind('<FocusIn>', on_focus)
ent6.grid(row=5, column=1)

find = Button(window, text='Find roots')
find.grid(row=6, column=0, pady=10, padx=30, columnspan=2)
find.bind('<Button-1>', find_roots)

errors = Label(window, text="0 - no errors\n1 - too many iterations")
errors.grid(row=7, column=0, padx=30, columnspan=2)

window.bind('<Alt-c>', clear)
window.bind('<Alt-f>', find_roots)

mmenu = Menu(window)
fmenu = Menu(mmenu)
fmenu.add_command(label='Quit (Alt+F4)', command=window.quit)
mmenu.add_cascade(label='File', menu=fmenu)
emenu = Menu(mmenu)
emenu.add_command(label='Show results (Alt+F)', command=find_roots)
emenu.add_separator()
emenu.add_command(label='Clear all fields (Alt+C)', command=clear)
mmenu.add_cascade(label='Edit', menu=emenu)
hmenu = Menu(mmenu)
hmenu.add_command(label='About', command=about)
mmenu.add_cascade(label='Help', menu=hmenu)

window.config(menu=mmenu)

one = Button(window, text='1', command=lambda: add(1), width=7)
one.grid(row=0, column=4, pady=(10, 10))
two = Button(window, text='2', command=lambda: add(2), width=7)
two.grid(row=0, column=5, pady=(10, 10))
three = Button(window, text='3', command=lambda: add(3), width=7)
three.grid(row=0, column=6, pady=(10, 10))
devide = Button(window, text='\\', command=lambda: add("\\"), width=7)
devide.grid(row=0, column=7, pady=(10, 10))

four = Button(window, text='4', command=lambda: add(4), width=7)
four.grid(row=1, column=4, pady=(10, 10))
five = Button(window, text='5', command=lambda: add(5), width=7)
five.grid(row=1, column=5, pady=(10, 10))
six = Button(window, text='6', command=lambda: add(6), width=7)
six.grid(row=1, column=6, pady=(10, 10))
mult = Button(window, text='*', command=lambda: add("*"), width=7)
mult.grid(row=1, column=7, pady=(10, 10))

seven = Button(window, text='7', command=lambda: add(7), width=7)
seven.grid(row=2, column=4, pady=(10, 10))
eight = Button(window, text='8', command=lambda: add(8), width=7)
eight.grid(row=2, column=5, pady=(10, 10))
nine = Button(window, text='9', command=lambda: add(9), width=7)
nine.grid(row=2, column=6, pady=(10, 10))
mult = Button(window, text='-', command=lambda: add("-"), width=7)
mult.grid(row=2, column=7, pady=(10, 10))

x = Button(window, text='x', command=lambda: add("x"), width=7)
x.grid(row=3, column=4, pady=(10, 10))
zero = Button(window, text='0', command=lambda: add(0), width=7)
zero.grid(row=3, column=5, pady=(10, 10))
dot = Button(window, text='.', command=lambda: add("."), width=7)
dot.grid(row=3, column=6, pady=(10, 10))
mult = Button(window, text='+', command=lambda: add("+"), width=7)
mult.grid(row=3, column=7, pady=(10, 10))

clear_all_btn = Button(window, text="AC", width=7)
clear_all_btn.grid(row=4, column=4, pady=(10, 10), columnspan=2)
clear_all_btn.bind('<Button-1>', clear)
clear_last = Button(window, text="<x]", width=7)
clear_last.grid(row=4, column=6, pady=(10, 10), columnspan=2)
clear_last.bind('<Button-1>', dell)

table_frame = Frame(window)
table_frame.grid(row=0, column=8, columnspan=2, rowspan=4)

table_scroll = Scrollbar(table_frame)
table_scroll.pack(side=RIGHT, fill=Y)

table = Treeview(table_frame, yscrollcommand=table_scroll.set)

table.pack()

table_scroll.config(command=table.yview)
table_scroll.config(command=table.xview)

table['columns'] = ('#', 'section', 'x', 'fx', 'Iterations', 'Code')

table.column("#0", width=0, stretch=NO)
table.column("#", anchor=CENTER, width=80)
table.column("section", anchor=CENTER, width=80)
table.column("x", anchor=CENTER, width=80)
table.column("fx", anchor=CENTER, width=80)
table.column("Iterations", anchor=CENTER, width=80)
table.column("Code", anchor=CENTER, width=50)

table.heading("#0", text="", anchor=CENTER)
table.heading("#", text="#", anchor=CENTER)
table.heading("section", text="section", anchor=CENTER)
table.heading("x", text="x", anchor=CENTER)
table.heading("fx", text="fx", anchor=CENTER)
table.heading("Iterations", text="Iterations", anchor=CENTER)
table.heading("Code", text="Code", anchor=CENTER)
table.pack()

figure = Figure(figsize=(5, 4))
canvas = FigureCanvasTkAgg(figure, window)
canvas.get_tk_widget().grid(row=4, column=8, rowspan=60)

ent1.insert(0, "(x+2)**2*(x-1) + 0.3")
ent2.insert(0, "-3")
ent3.insert(0, "1.5")
ent4.insert(0, "1")
ent5.insert(0, "100")
ent6.insert(0, "0.001")


window.mainloop()
