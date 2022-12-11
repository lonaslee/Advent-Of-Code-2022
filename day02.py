pairs: list[tuple[str, str]] = []
with open("inputs/in2.txt", "r") as f:
    pairs = [(l[0], l[2]) for l in f.readlines()]

# A X - rock - 1
# B Y - paper - 2
# C Z - scissors - 3


# total = 0
# for opponent, me in pairs:
#     total += 1 if me == 'X' else 2 if me == 'Y' else 3
#     if (opponent == 'A' and me == 'X') or (opponent == 'B' and me == 'Y') or (opponent == 'C' and me == 'Z'):
#         total += 3
#     elif (opponent == 'A' and me == 'Y') or (opponent == 'B' and me == 'Z') or (opponent == 'C' and me == 'X'):
#         total += 6

total = 0
for opponent, result in pairs:
    if result == "X":
        if opponent == "A":
            total += 3
        elif opponent == "B":
            total += 1
        else:
            total += 2
    elif result == "Y":
        if opponent == "A":
            total += 1
        elif opponent == "B":
            total += 2
        else:
            total += 3
        total += 3
    else:
        if opponent == "A":
            total += 2
        elif opponent == "B":
            total += 3
        else:
            total += 1
        total += 6

print(total)
