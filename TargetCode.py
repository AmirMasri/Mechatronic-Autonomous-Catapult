from tkinter import *
import settings
import util
import SerialCom 

# Updates selected values
def set_value(x, y):
    global xCoord
    global yCoord
    xCoord = 0
    yCoord = 0
    xCoord = x 
    yCoord = y 

def send_Value():
    global arduino_value
    arduino_value = str(xCoord) + ':' + str(yCoord)
    print(arduino_value)


# Cell buttons class
class Cell:
    def __init__(self, x, y):
        self.cell_btn_object = None
        self.x = x
        self.y = y

    def create_btn_object(self, location):
        btn = Button(
            location,
            width = 12,
            height = 4,
            text = f"{self.x},{self.y}"
        )
        btn.bind('<Button-1>', self.left_click_actions) # Left Click
        self.cell_btn_object = btn

    def left_click_actions(self, event):
        print(event)
        set_value(self.x, self.y)
        target_text = Label(
        left_frame,
        font = ('HelveticalBold', 20),
        bg = '#454242',
        fg = 'red',
        text = f'{xCoord},{yCoord}'
        )
        target_text.place(x = 46, y = 40)
        print(f"{self.x},{self.y} was selected")

# Confirmation button
class Confirm:
    def __init__(self):
        self.cell_btn_object = None

    def create_btn_object(self, location):
        btn = Button(
            location,
            width = 16,
            height = 3,
            bg = 'white',
            activebackground = 'green',
            text = 'Confirm Target'
        )
        btn.place(x = 11, y = 200)
        btn.bind('<Button-1>', self.confirmSelection)
        self.cell_btn_object = btn

    def confirmSelection(self, event):
        print(event)
        send_Value()
        SerialCom.write_read(arduino_value)
        print(f"...Targeting {xCoord},{yCoord}")


root = Tk()

# Override Settings
root.configure(bg="white")
root.geometry(f'{settings.WIDTH}x{settings.HEIGHT}')
root.title("Targeting Area")
root.resizable(False, False)

# Top Bar
top_frame = Frame(
    root,
    bg = 'black',
    width = settings.WIDTH,
    height = util.height_prcnt(20),
)
top_frame.place(x = 0, y = 0)

top_text = Label(
    top_frame,
    font = ('Helvetical Bold', 40), 
    bg = 'black',
    fg = 'lightgreen',
    text = 'Target Selection'
)
top_text.place(x = 175, y = 35)

# Left Sidebar
left_frame = Frame(
    root,
    bg = '#454242',
    width = util.width_prcnt(20),
    height = util.height_prcnt(80),
)
left_frame.place(x = 0, y = util.height_prcnt(20))

side_text = Label(
    left_frame,
    font = ('HelveticalBold', 14),
    bg = '#454242',
    fg = 'lightgreen',
    text = 'Selected Target'
)
side_text.place(x = 0, y = 10)

# Central Area
centre_frame = Frame(
    root,
    bg = 'white',
    width = util.width_prcnt(80),
    height = util.height_prcnt(80)
)
centre_frame.place(x = util.width_prcnt(20), y = util.height_prcnt(20))

# Seperate Cells
for x in range(settings.GRID_COLUMN):
    for y in range (settings.GRID_ROW):
        c = Cell(x, y)
        c.create_btn_object(centre_frame)
        c.cell_btn_object.grid(
            column=x, row=y
        )

# Confirmation Button
cfmButton = Confirm()
cfmButton.create_btn_object(left_frame)

# Run Window
root.mainloop()
