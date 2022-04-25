from tkinter import *
import tkinter.messagebox as box
from tkinter.ttk import *
from math import *


# прямая и треугольники
def click(event):
    global clicks
    global circles
    if clicks % 2 == 0:
        coords.append([event.x, event.y])
    else:
        coords[len(coords) - 1].append(int(sqrt((event.x - coords[len(coords) - 1][0]) ** 2 +
                                                (event.y - coords[len(coords) - 1][1]) ** 2)))
        canv.create_oval(coords[len(coords) - 1][0] - coords[len(coords) - 1][2],
                         coords[len(coords) - 1][1] - coords[len(coords) - 1][2],
                         coords[len(coords) - 1][0] + coords[len(coords) - 1][2],
                         coords[len(coords) - 1][1] + coords[len(coords) - 1][2])
        circles += 1
    clicks += 1


def find():
    global res
    global circles
    res = []
    canv.delete("all")
    if circles == 0:
        box.showwarning("Error", "No coordinates were entered")
    for i in range(circles):
        canv.create_oval(coords[i][0] - coords[i][2], coords[i][1] - coords[i][2],
                         coords[i][0] + coords[i][2], coords[i][1] + coords[i][2])
    gmax = 0
    for i in range(circles):
        tmax = 0
        for j in range(circles):
            s = sqrt((coords[i][0] - coords[j][0]) ** 2 + (coords[i][1] - coords[j][1]) ** 2)
            if coords[i][2] + coords[j][2] > s > abs(coords[i][2] - coords[j][2]):
                tmax += 1
        if tmax >= gmax:
            if tmax > gmax:
                gmax = tmax
                res = []
            res.append(coords[i])
    for i in res:
        canv.create_oval(i[0] - i[2], i[1] - i[2], i[0] + i[2], i[1] + i[2], outline="#f11", width=2)


def clear(event):
    global circles
    global clicks
    ent1.delete(0, len(ent1.get()))
    ent2.delete(0, len(ent2.get()))
    ent3.delete(0, len(ent3.get()))
    coords.clear()
    res.clear()
    circles = 0
    clicks = 0
    canv.delete("all")


def about():
    box.showinfo("About", "In short, no one will read it anyway. I'm wondering why towels require washing if only clean"
                          " hands should be wiped with them?")


def add(num):
    global clicks
    global circles
    if clicks % 2 == 1:
        clicks -= 1
        coords.pop(len(coords) - 1)
    try:
        if 800 < float(ent1.get()) < 0 and 650 < float(ent2.get()) < 0 and float(ent3.get()) < 0:
            raise ValueError
        coords.append([float(ent1.get()), float(ent2.get()), float(ent3.get())])
        canv.create_oval(float(ent1.get()) - float(ent3.get()), float(ent2.get()) - float(ent3.get()),
                         float(ent1.get()) + float(ent3.get()), float(ent2.get()) + float(ent3.get()))
        circles += 1
    except ValueError:
        box.showwarning("Error", "There is some wrong values")


def del_last():
    global clicks
    global circles
    if clicks % 2 == 1:
        clicks -= 1
        coords.pop(len(coords) - 1)
    if len(coords) > 0:
        coords.pop(len(coords) - 1)
    for i in coords:
        canv.create_oval(i[0] - i[2], i[1] - i[2], i[0] + i[2], i[1] + i[2])


clicks = 0
circles = 0
coords = []
res = []
window = Tk()
window.title('Circles')
window.geometry('1100x650+50+100')

enter = Label(window, text="X-coordinate of center:")
enter.grid(row=0, column=0)
ent1 = Entry(width=20)
ent1.grid(row=0, column=1)

enter = Label(window, text="Y-coordinate of center:")
enter.grid(row=1, column=0)
ent2 = Entry(width=20)
ent2.grid(row=1, column=1)

enter = Label(window, text="Radius of circle:")
enter.grid(row=2, column=0)
ent3 = Entry(width=20)
ent3.grid(row=2, column=1)

add_b = Button(window, text='Add coordinates')
add_b.grid(row=3, column=0, pady=10, padx=30)
add_b.bind('<Button-1>', add)

find_b = Button(window, text='Find circle', command=find)
find_b.grid(row=3, column=1, pady=10, padx=30)

canv = Canvas(bg='white', width=1000, height=1000)
canv.grid(row=0, column=2, rowspan=100, columnspan=100)
canv.bind('<Button-1>', click)

window.bind('<Alt-c>', clear)

mmenu = Menu(window)
fmenu = Menu(mmenu)
fmenu.add_command(label='Quit (Alt+F4)', command=window.quit)
mmenu.add_cascade(label='File', menu=fmenu)
emenu = Menu(mmenu)
emenu.add_command(label='Find circle (Alt+F)', command=clear)
emenu.add_separator()
emenu.add_command(label='Clear all fields (Alt+C)', command=clear)
mmenu.add_cascade(label='Edit', menu=emenu)
hmenu = Menu(mmenu)
hmenu.add_command(label='About', command=about)
mmenu.add_cascade(label='Help', menu=hmenu)

window.config(menu=mmenu)

clear_all_btn = Button(window, text="Clear all", width=7)
clear_all_btn.grid(row=4, column=0, columnspan=2)
clear_all_btn.bind('<Button-1>', clear)

ent1.insert(0, "100")
ent2.insert(0, "50")
ent3.insert(0, "10")

window.mainloop()
