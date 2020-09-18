#coding:utf-8
from libnum import n2s
from secret import cw,ch
from PIL import Image,ImageDraw
from random import getrandbits,seed
from secret import width,height,seed_num,flag,text_color

def makeSourceImg():
	seed(seed_num)
	colors = n2s(getrandbits(width*height*24))
	img = Image.new('RGB', (width,height))
	x = 0
	for i in range(width):
		for j in range(height):
			img.putpixel((i,j),tuple(map(ord,colors[x:x+3])))
			x+=3
	return img

def makeFlagImg():
	img = Image.new("RGB",(width,height))
	draw = ImageDraw.Draw(img)

	for i in range(5):
		draw.text((0,i*2),flag,fill=text_color)
	return img

if __name__ == '__main__':
	img1=makeSourceImg()
	img2=makeFlagImg()

	for i in range(width):
		for j in range(height):
			p1,p2=img1.getpixel((i,j)),img2.getpixel((i,j))
			img1.putpixel((i,j),tuple([(p1[k] ^ p2[k]) for k in range(3)]))

	tmp=[img1.getpixel((i,j)) for j in range(height) for i in range(width)]
	img3 = Image.new("RGB",(cw,ch))
	assert cw*ch == width * height
	for i in range(ch):
		for j in range(cw):
			img3.putpixel((j,i),tmp[i*cw+j])
	img3.save('attach.png')
