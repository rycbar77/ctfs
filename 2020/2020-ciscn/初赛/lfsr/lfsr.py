import random

from secret import flag

N = 100
MASK = 2**(N+1) - 1

def lfsr(state, mask):
    feedback = state & mask
    feed_bit = bin(feedback)[2:].count("1") & 1
    output_bit = state & 1
    state = (state >> 1) | (feed_bit << (N-1))
    return state, output_bit

def main():
    assert flag.startswith("flag{")
    assert flag.endswith("}")

    mask = int(flag[5:-1])
    assert mask.bit_length() == N
    
    state  = random.randint(0, MASK)
    print(state)
    
    outputs = ''
    for _ in range(N**2):
        state, output_bit = lfsr(state, mask)
        outputs += str(output_bit)
    
    with open("output.txt", "w") as f:
        f.write(outputs)

main()