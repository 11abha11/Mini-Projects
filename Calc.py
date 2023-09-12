import tkinter as tk
c=tk.Tk()
c.geometry('331x346')
c.resizable(0,0)        #to prevent the window from resizing
c.title('CALCULATOR')


############     functions     ############


exp = ""
input_text = tk.StringVar()                  #instance of input field


def btn_click(item):                                     #updates the input string
    global exp
    exp = exp + str(item)
    input_text.set(exp)
    

def btn_clear():
    global exp
    exp = ""
    input_text.set("")

def btn_equal():
    global exp
    result = str(eval(exp))
    input_text.set(result)
    exp = ""


##############    widgets     ############


#creating a frame for the input field

input_frame = tk.Frame(c , width=312, height=50 , highlightcolor="black", highlightbackground="black", highlightthickness=1.5)
input_frame.pack(side="top")


#creating an input field in the formed frame

input_field = tk.Entry(input_frame, font=('arial',18,'bold'), textvariable=input_text, width=50, justify="right")
input_field.grid(row=0, column=0)
input_field.pack(ipady=10)      #internal padding to increase the height of the input field



#creating a frame for all the buttons 

btns_frame = tk.Frame(c, width=312, height=272, bg="grey") 
btns_frame.pack()


#first row

clear = tk.Button(btns_frame, text="CLR", fg="black", width=34, height=3, bg = "#eee", cursor="hand2" , command = lambda : btn_clear()).grid(row=0, column=0, columnspan=3, padx = 1, pady = 1)
divide = tk.Button(btns_frame, text = "/", fg = "black", width = 10, height = 3, bg = "#eee", cursor = "hand2", command = lambda: btn_click("/")).grid(row = 0, column = 3, padx = 1, pady = 1)


# second row
 
seven = tk.Button(btns_frame, text = "7", fg = "black", width = 10, height = 3, bg = "#fff", cursor = "hand2", command = lambda: btn_click(7)).grid(row = 1, column = 0, padx = 1, pady = 1)
eight = tk.Button(btns_frame, text = "8", fg = "black", width = 10, height = 3, bg = "#fff", cursor = "hand2", command = lambda: btn_click(8)).grid(row = 1, column = 1, padx = 1, pady = 1)
nine = tk.Button(btns_frame, text = "9", fg = "black", width = 10, height = 3, bg = "#fff", cursor = "hand2", command = lambda: btn_click(9)).grid(row = 1, column = 2, padx = 1, pady = 1)
multiply = tk.Button(btns_frame, text = "*", fg = "black", width = 10, height = 3, bg = "#eee", cursor = "hand2", command = lambda: btn_click("*")).grid(row = 1, column = 3, padx = 1, pady = 1)
 
# third row
 
four = tk.Button(btns_frame, text = "4", fg = "black", width = 10, height = 3, bg = "#fff", cursor = "hand2", command = lambda: btn_click(4)).grid(row = 2, column = 0, padx = 1, pady = 1)
five = tk.Button(btns_frame, text = "5", fg = "black", width = 10, height = 3, bg = "#fff", cursor = "hand2", command = lambda: btn_click(5)).grid(row = 2, column = 1, padx = 1, pady = 1)
six = tk.Button(btns_frame, text = "6", fg = "black", width = 10, height = 3, bg = "#fff", cursor = "hand2", command = lambda: btn_click(6)).grid(row = 2, column = 2, padx = 1, pady = 1)
minus = tk.Button(btns_frame, text = "-", fg = "black", width = 10, height = 3, bg = "#eee", cursor = "hand2", command = lambda: btn_click("-")).grid(row = 2, column = 3, padx = 1, pady = 1)
 
# fourth row
 
one = tk.Button(btns_frame, text = "1", fg = "black", width = 10, height = 3, bg = "#fff", cursor = "hand2", command = lambda: btn_click(1)).grid(row = 3, column = 0, padx = 1, pady = 1)
two = tk.Button(btns_frame, text = "2", fg = "black", width = 10, height = 3, bg = "#fff", cursor = "hand2", command = lambda: btn_click(2)).grid(row = 3, column = 1, padx = 1, pady = 1)
three = tk.Button(btns_frame, text = "3", fg = "black", width = 10, height = 3, bg = "#fff", cursor = "hand2", command = lambda: btn_click(3)).grid(row = 3, column = 2, padx = 1, pady = 1)
plus = tk.Button(btns_frame, text = "+", fg = "black", width = 10, height = 3, bg = "#eee", cursor = "hand2", command = lambda: btn_click("+")).grid(row = 3, column = 3, padx = 1, pady = 1)
 
# fifth row
 
zero = tk.Button(btns_frame, text = "0", fg = "black", width = 22, height = 3, bg = "#fff", cursor = "hand2", command = lambda: btn_click(0)).grid(row = 4, column = 0, columnspan = 2, padx = 1, pady = 1)
period = tk.Button(btns_frame, text = ".", fg = "black", width = 10, height = 3, bg = "#eee", cursor = "hand2", command = lambda: btn_click(".")).grid(row = 4, column = 2, padx = 1, pady = 1)
equal = tk.Button(btns_frame, text = "=", fg = "black", width = 10, height = 3, bg = "#eee", cursor = "hand2", command = lambda: btn_equal()).grid(row = 4, column = 3, padx = 1, pady = 1)



c.mainloop()
