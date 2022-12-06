# pairs: list[tuple[str, str]] = []
# with open("inputs/in3.txt", "r") as f:
#     pairs = [(l[: int(len(l) / 2)], l[int(len(l) / 2) :]) for l in f.readlines()]

# total = 0
# for a, b in pairs:
#     common = ""
#     for e in a:
#         if e in b:
#             common = e
#             break
#     total += ord(common) - (96 if common.islower() else 38)


threes: list[tuple[str, str, str]] = []
with open("inputs/in3.txt", "r") as f:
    inp = f.readlines()
    threes = [tuple(inp[i : i + 3]) for i in range(0, len(inp), 3)]

total = 0
for a, b, c in threes:
    common = ""
    for e in a:
        if e in b and e in c:
            common = e
            break
    total += ord(common) - (96 if common.islower() else 38)

print(total)
