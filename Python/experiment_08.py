from tkinter import *
from tkinter import messagebox, filedialog

# Functions

def save_file():
    '''saves the file in a .txt format'''
    f = filedialog.asksaveasfile(mode='w', defaultextension=".txt")
    if f is None: # asksaveasfile return `None` if dialog closed with "cancel".
        return
    text2save = str(text.get(1.0, END)) 
    f.write(text2save)
    f.close()

    # Shows info box if file saved;
    return messagebox.showinfo("Saved", "File Saved Successfully")

def clear_file():
    '''clears the input field '''
    name_var.set("")
    text.delete(1.0, END)

def print_in_cmd():
    '''prints the file in terminal'''
    print("Title:", name_var.get())

    print(str(text.get(1.0, END)))

    # Shows info box if file printed in the terminal;
    return messagebox.showinfo("Printed", "File Printed Successfully")

def donothing():
    pass


# create root window
root = Tk()
# root window title and dimension
root.title("Welcome to File Editor")
# Set geometry (widthxheight)
root.geometry('1200x550')

name_var=StringVar()
# creating a label for TITLE using widget Label
Label(root, text = 'TITLE', font=('calibre',14, 'bold')).place(x=30, y=70)
Entry(root, textvariable = name_var, font=('calibre',13,'normal')).place(x=30, y=110)

# Text Input
text=Text(root, x=30, y=40, padx = 10, pady = 10, wrap=WORD)
text.pack()

# adding a label to the root window
lbl = Label(root, text = "File Editor")

# Text to display where to enter text
Label(root, text="Enter Text: ", font=('calibre', 15, 'bold')).place(x=180, y=220, anchor="center")


# button widget with blue color text inside
btn = Button(root, text = "Update", fg = "blue", command=save_file)
btn.place(x = 350, y = 450)

# button widget with blue color text inside
btn = Button(root, text = "Print", fg = "blue", command=print_in_cmd)
btn.place(x = 475, y = 450)

# button widget with blue color text inside
btn = Button(root, text = "Clear", fg = "blue", command=clear_file)
btn.place(x = 600, y = 450)

# button widget with blue color text inside
btn = Button(root, text = "Delete", fg = "red", command=clear_file)
btn.place(x = 725, y = 450)

# menu bar at the top
menubar=Menu(root)

filemenu=Menu(menubar,tearoff=0)
filemenu.add_command(label="New", command=clear_file)
filemenu.add_command(label="Open", command=donothing)
filemenu.add_command(label="Save", command=save_file)
filemenu.add_command(label="Save as...", command=save_file)
filemenu.add_separator()
filemenu.add_command(label="Exit", command=root.quit)
# Adding cascade
menubar.add_cascade(label="File", menu=filemenu)


editmenu=Menu(menubar,tearoff=0)
editmenu.add_command(label="Undo", command=donothing)
editmenu.add_command(label="Copy", command=donothing)
editmenu.add_command(label="Paste", command=donothing)
# Adding cascade
menubar.add_cascade(label="Edit", menu=editmenu)


helpmenu=Menu(menubar,tearoff=0)
helpmenu.add_command(label="Help",command=donothing)
# Adding cascade
menubar.add_cascade(label="Help",menu=helpmenu)

# configuring the root menu
root.config(menu=menubar)

# Execute Tkinter
root.mainloop()