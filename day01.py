inp: list[str] = []
with open("inputs/in1.txt", "r") as f:
    inp = f.readlines()
inp.append("\n")

print(inp)

val_list: list[int] = []

cur = 0
for e in inp:
    if e == '\n':
        val_list.append(cur)
        cur = 0
    else:
        cur += int(e)

first = max(val_list)
val_list.pop(val_list.index(first))

second = max(val_list)
val_list.pop(val_list.index(second))

third = max(val_list)

print(first, second, third)

print(sum([first, second, third]))
