

wow = rabbit.findwindow("World of Warcraft");
print wow
offsetx,offsety,width,height = rabbit.get_window_rect(wow);
print offsetx,offsety,width,height

rabbit.keypress('0')
rabbit.sleep(100)

rabbit.keypress('A')
rabbit.sleep(100)

rabbit.keypress('a')
rabbit.sleep(100)

rabbit.input('input')
rabbit.sleep(100)

rabbit.input('文本输入')
rabbit.sleep(100)

rabbit.moveto(100, 100)
rabbit.click()