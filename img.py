#!/usr/bin/env python3
from PIL import Image
from PIL import ImageEnhance
import sys
if len(sys.argv)<2:
    print("Usage: %s image [dither_amount]" % sys.argv[0])
    exit()

image = Image.open(sys.argv[1])
dither = 0.5
if len(sys.argv)>=3:
    dither=float(sys.argv[2])

def ansi_color(image,dither):
    pal_image= Image.new("P", (1,1))
    b=255
    pal=(0,0,0,
         b,0,0,
         0,b,0,
         b,b,0,
         0,0,b,
         b,0,b,
         0,b,b,
         b,b,b)
    pal_image.putpalette(pal+(0,0,0)*(256-len(pal)//3))
    new_image = Image.new("RGBA", image.size, "WHITE") # Create a white rgba background
    new_image.paste(image, (0, 0), image)
    image = new_image.convert("RGB")
    smooth = image.quantize(palette=pal_image,dither=0).convert("RGB")
    smooth = Image.blend(smooth, image, dither).convert("RGB")
    return smooth.quantize(palette=pal_image)

def resize_max(image,maxw,maxh):
    w,h=image.size
    scale=min(maxw/w, maxh/h)
    if scale >= 1.0:
        return image
    return image.resize((int(w*scale),int(h*scale)),resample=Image.LANCZOS)

def print_image(image):

    e = ImageEnhance.Color(image)
    image = e.enhance(1.5)
    e = ImageEnhance.Brightness(image)
    #image = e.enhance(2)
    e = ImageEnhance.Contrast(image)
    image = e.enhance(1.5)
    
    image = resize_max(image,80,48)
    w,h=image.size
    
    image = ansi_color(image,dither)
    
    text = ""
    obg = -1
    ofg = -1
    if h % 2:
        h = h -1
    for y in range(0,h,2):
        for x in range(0,w):
            bg = image.getpixel((x,y))
            fg = image.getpixel((x,y+1))
            if bg>=8 or fg>=8:
                print("ERROR",bg,fg)
                exit()
            if bg==fg:
                if bg==obg:
                    text+=" "
                elif fg==ofg:
                    text+="█"
                else:
                    text+="\033[%dm█" % (30+fg)
                    ofg=fg
            elif fg==ofg and bg==obg:
                text += "▄"
            elif fg==ofg:
                text += "\033[%dm▄" % (40+bg)
                obg = bg
            elif bg==obg:
                text += "\033[%dm▄" % (30+fg)
                ofg=fg
            else:
                text += "\033[%d;%dm▄" % ((30+fg),(40+bg))
                ofg=fg
                obg=bg
            #more optimizations: if bg==ofg or fg==obg
        text+="\033[49m\n"
        obg=-1
    text+="\033[m"
    return text
#image.save("out.png")
#"▄█"
    
