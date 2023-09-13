from tkinter import *
from datetime import date
from tkinter import messagebox as mb


# for resetting the field entry values

def reset_values():
    day_entry.delete(0,END)
    month_entry.delete(0,END)
    year_entry.delete(0,END)
    name_entry.delete(0,END)


# to check for empty fields

def check_errors():
    if(name.get()=="" or day.get()=="" or month.get()=="" or year.get()==0):
        return False
    
    return True


# for calculating the age of the user

def calc_age():
    if(check_errors()):
        try:
            day1=int(day.get())                 # using get() method since variables 
            month1=int(month.get())             # are not declared globally
            year1=int(year.get())

            dob=date(year1,month1,day1)
            num = date.today() - dob
            num1 = int(abs(num.total_seconds())/(365.25*24*3600))   # calculation
            age.set("The calculated age is : " + str(num1))         # appending to the age string

            greet.set("Hi "+str(name.get()) + "!")     # appending to greet string

        except ValueError:
            mb.showerror("ERROR!", "Data entered is out of range!")    # error for invalid data
    else:
        mb.showerror("ERROR!", "Enter all the fields!")         # error for empty fields
        reset_values()


if __name__ == "__main__":

    win=Tk()                               # creating the window
    win.geometry('400x320')
    win.config(bg="#8DEEEE")
    win.resizable(0,0)                     # to avoid resizing of the window

    win.title('AGE CALCULATOR')



    # for fetching the user's name

    name=StringVar()
    name.set("")

    name_label = Label(
        win,
        text = "Enter your name : ",
        bg="#8DEEEE",
        font=('arial narrow',12,'bold','italic')
        ).place(x=20,y=27)
    
    name_entry = Entry(
        win,
        width=30,
        textvariable=name)
    
    name_entry.place(x=180,y=30)


    # for fetching the user's date of birth

    date_label = Label(
        win,
        text = "Enter your birthday : ",
        bg="#8DEEEE",
        font=('arial narrow',12,'italic','bold')
        ).place(x=20,y=81)

    day_label = Label(win,text="Day",bg="#8DEEEE").place(x=184,y=60)
    month_label = Label(
        win,
        text="Month",
        bg="#8DEEEE"
        ).place(x=237,y=60)
    
    year_label = Label(
        win,
        text="Year"
        ,bg="#8DEEEE"
        ).place(x=316,y=60)


    day=StringVar()
    day.set("")
    month=StringVar()
    month.set("")
    year=StringVar()
    year.set("")

    day_entry = Entry(
        win,
        width=5,
        textvariable=day,
        relief = GROOVE
        )
    
    day_entry.place(x=180,y=85)

    month_entry = Entry(
        win,
        width=5,
        textvariable=month,
        relief = GROOVE
        )
    
    month_entry.place(x=240,y=85)

    year_entry = Entry(
        win,
        width=10,
        textvariable=year,
        relief = GROOVE,
        )
    
    year_entry.place(x=300,y=85)


    # calculating the age

    calc = Button(
        win,
        text="Calculate Age",
        width=15,
        height=2,
        bg="#FFEFDB",
        command = calc_age,
        padx=2,
        pady=2,
        relief=RAISED,
        bd=5
        ).place(x=140,y=130)
    

    age=StringVar()
    age.set("")

    greet=StringVar()
    greet.set("")

    # greeting the user

    greeting_label = Label(
        win,
        textvariable=greet,
        bg="#8DEEEE",
        font=('Calisto MT',12),
        padx=2,
        pady=2
        ).place(x=170,y=180)
    
    # displaying the age

    age_label = Label(
        win,
        textvariable=age,
        bg="#8DEEEE",
        font=('Calisto MT',14,'bold'),
        padx=2,
        pady=2
        ).place(x=95,y=200)


    # reset button

    reset = Button(
        win,
        text="Reset",
        width=12,
        height=2,
        bg="#2E2E2E",
        fg="#FFF8DC",
        command = reset_values,
        relief=RAISED,
        bd=5
        ).place(x=70,y=250)


    # exit button

    exit_btn = Button(
        win,
        text="EXIT",
        width=12,
        height=2,
        bg="#FF3030",
        command = win.quit,
        relief=RAISED,
        bd=5
        ).place(x=240,y=247)



    win.mainloop()