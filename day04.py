pairs: list[tuple[set[int], set[int]]]
with open("inputs/in4.txt", "r") as f:
    pairs = [
        tuple(
            set(range(int(r[0]), int(r[1]) + 1))
            for r in [h.split("-") for h in s.split(",")]
        )
        for s in f.readlines()
    ]

# total = 0
# for a, b in pairs:
#     if len(a) == len(a | b) or len(b) == len(b | a):
#         total += 1

total = 0
for a, b in pairs:
    if len(a) + len(b) > len(a | b):
        total += 1

print(total)
