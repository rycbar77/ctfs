s = ""
with open('./IceCreamManual.txt', 'r') as f:
    s += f.read()
intGredients = [27, 120, 79, 80, 147,
                154, 97, 8, 13, 46, 31, 54, 15, 112, 3,
                464, 116, 58, 87, 120, 139, 75, 6, 182,
                9, 153, 53, 7, 42, 23, 24, 159, 41, 110]
correct = ""
for i in intGredients:
    correct += s[i]
# print(correct)
inputIceCream = [0 for i in correct]
outputIceCream = [ord(i) for i in correct]
toppings = [8, 61, -8, -7, 58, 55,
            -8, 49, 20, 65, -7, 54, -8, 66, -9, 69,
            20, -9, -12, -4, 20, 5, 62, 3, -13, 66,
            8, 3, 56, 47, -5, 13, 1, -7]
for i in range(len(outputIceCream)):
    outputIceCream[i] -= toppings[i]
for i in range(len(outputIceCream)):
    if i % 2 == 0:
        if i > 0:
            inputIceCream[i - 2] = outputIceCream[i]
        else:
            inputIceCream[len(outputIceCream) - 2] = outputIceCream[i]
    else:
        if i < len(outputIceCream) - 2:
            inputIceCream[i + 2] = outputIceCream[i]
        else:
            inputIceCream[1] = outputIceCream[i]
for i in range(len(outputIceCream)):
    if i % 2 == 0:
        inputIceCream[i] = chr(inputIceCream[i] - 1)
    else:
        inputIceCream[i] = chr(inputIceCream[i] + 1)
inputIceCream.reverse()
flag = ''.join(inputIceCream)
print(flag)
