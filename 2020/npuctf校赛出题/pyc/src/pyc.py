a=input("Input the flag:")
target=[0, 10, 7, 1, 29, 21, 86, 11, 3, 81, 15, 11, 3, 21, 57, 2, 15, 83, 57, 17, 86, 8, 18, 57, 17, 86, 20, 13, 57, 4, 19, 81, 57, 18, 14, 15, 83, 57, 86, 8, 3, 57, 87, 21, 57, 16, 3, 20, 31, 57, 3, 82, 21, 31, 27]
if len(a) !=len(target):
	print("Wrong!")
	exit(1)
for i in range(len(a)):
	if (ord(a[i])^0x66)!=target[i]:
		print("Wrong!")
		exit(1)
print("You Got it!")
