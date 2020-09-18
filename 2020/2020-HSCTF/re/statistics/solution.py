def swap(array):
    for i in range(1, len(array)):
        if array[i - 1] <= array[i]:
            flip(array, i, i - 1)
    return array


def flip(array, a, b):
    tmp = array[a]
    array[a] = array[b]
    array[b] = tmp


def to_num(l, j):
    arr = [0] * len(l)
    arr[0] = 97 + j
    for i in range(1, len(l)):
        if arr[i - 1] % 2 == 0:
            arr[i] = l[i] + (arr[i - 1] - 97)
        else:
            arr[i] = l[i] - (arr[i - 1] - 97)

        arr[i] = (arr[i] - 97 + 29) % 29 + 97
    return arr


def reverse_back(l, j):
    arr = [0] * len(l)
    arr[0] = 97 + j
    for i in range(1, len(l)):
        if l[i - 1] % 2 == 0:
            if l[i] < l[i - 1]:
                arr[i] = l[i] + 29 - l[i - 1] + 97
            else:
                arr[i] = l[i] - (l[i - 1] - 97)
        else:
            tmp = l[i] + l[i - 1] - 97 - 29
            if tmp < 97:
                tmp += 29
            arr[i] = tmp

        arr[i] = (arr[i] - 97 + 29) % 29 + 97
    return arr


# tt = "qtqnhuyj{fjw{rwhswzppfnfrz|qndfktceyba"
# target = "flag{"
# ll = [ord(i) for i in target]
# ran = 0
# for j in range(29):
#     if "qtqn" in "".join([chr(i) for i in swap(swap(to_num(ll, j)))]):
#         # print("".join([chr(i) for i in swap(swap(to_num(ll, j)))]))
#         ran = j

t = "fqntqchuyj{bjw{rwhswzppfnfrz|qndfktaey"
l = [ord(i) for i in t]
print("".join([chr(i) for i in reverse_back(l, 5)]))

# target = "flag{sjnper|intofallstativmicsatcfake}"
# ll = [ord(i) for i in target]
# swap(swap(to_num(ll, 5)))
# print("".join([chr(i) for i in swap(swap(to_num(ll, 5)))]) == tt)
# lll = [ord(i) for i in tt]
# print(reverse_back(ll, ran))
