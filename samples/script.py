import rabbit

# Press left Window key
rabbit.keyboard_press_vkey(0x5B)
rabbit.sleep(1000)

# Input 'Notepad'
rabbit.press('N')
rabbit.input('tepad')
rabbit.sleep(1000)

# Press Enter key
rabbit.keyboard_press_vkey(0x0D)
rabbit.sleep(1000)

# Do input
rabbit.input('Hello Rabbit!\n')
rabbit.sleep(1000)
rabbit.input('你好兔子!\n')
rabbit.sleep(1000)

# Find current Window
notepad = rabbit.window_find_focus()
l, t, r, b = rabbit.window_get_rect(notepad)

# Move mouse do doubleclick and then input more
rabbit.moveto(int(l + (r - l)/2), int(t + (b - t)/2))
rabbit.doubleclick()
rabbit.sleep(500)
rabbit.input('Window location: %d %d %d %d\n' % (l, t, r, b))
rabbit.keyboard_press_vkey(0x0D)
rabbit.keyboard_press_vkey(0x0D)
