from tkinter.filedialog import *
import encoder
from tkinter import *
import tkinter.messagebox as box
from tkinter.ttk import *
import os

# картинку ищем пиксель наиболее близкий к белому


def open_file(event):
    global file_path
    file = askopenfile(mode='r', filetypes=[('Image', '*.bmp')])
    if file is not None:
        file_path = str(file.name)
        encode_b['state'] = 'enabled'
        decode_b['state'] = 'enabled'
        open_pic_b['state'] = 'enabled'


def encode():
    encoder.encode(ent2.get(), file_path)
    box.showinfo("Info", "Your phrase was successfully encoded")


def decode():
    ent2.delete(0, len(ent2.get()))
    ent2.insert(0, encoder.decode(file_path))


def show():
    os.startfile(file_path)


def about():
    about_window = Toplevel(window)
    about_window.title('Conversion')
    about_window.geometry('270x150')
    label = Label(about_window, text="The program is designed to encode text into an\nimage in bmp format, as well as "
                                     "decode a phrase\nrecorded in a file of the same format. The author\n"
                                     "of the program is Dubov Andrey IU7-23B.", anchor=CENTER)

    label.pack(fill=Y, expand=True)


window = Tk()
window.title('Encoder')
window.geometry('430x70')

file_path = None

open_b = Button(window, text='Open file')
open_b.grid(row=2, column=0)
open_b.bind('<Button-1>', open_file)

phrase_result = Label(window, text="Encoded or decoded phrase:")
phrase_result.grid(row=1, column=0, pady=10, padx=10)
ent2 = Entry(width=40)
ent2.grid(row=1, column=1, columnspan=3)

encode_b = Button(window, text='Encode', command=encode)
encode_b.grid(row=2, column=1)
encode_b['state'] = 'disabled'

decode_b = Button(window, text='Decode', command=decode)
decode_b.grid(row=2, column=2)
decode_b['state'] = 'disabled'

open_pic_b = Button(window, text='Show picture', command=show)
open_pic_b.grid(row=2, column=3)
open_pic_b['state'] = 'disabled'


window.bind('<Alt-e>', encode)
window.bind('<Alt-d>', decode)

mmenu = Menu(window)
fmenu = Menu(mmenu)
fmenu.add_command(label='Quit (Alt+F4)', command=window.quit)
mmenu.add_cascade(label='File', menu=fmenu)
emenu = Menu(mmenu)
emenu.add_command(label='Encode (Alt+E)', command=encode)
emenu.add_command(label='Decode (Alt+D)', command=decode)
mmenu.add_cascade(label='Edit', menu=emenu)
hmenu = Menu(mmenu)
hmenu.add_command(label='About', command=about)
mmenu.add_cascade(label='Help', menu=hmenu)

window.config(menu=mmenu)

ent2.insert(0, "Some text")

window.iconphoto(False, PhotoImage(file='ico_encoder.png'))
window.mainloop()
