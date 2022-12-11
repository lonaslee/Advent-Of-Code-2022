import re

inp: list[str]
with open("inputs/in5.txt", "r") as f:
    inp = f.readlines()

crateslns: list[str] = []
for ln in inp:
    if ln == "\n":
        break
    crateslns.append(ln)

stacks: list[list[str]] = [[] for _ in range(len(re.findall(r"\d", crateslns[-1])))]
for ln in reversed(crateslns[:-1:]):
    for m in re.finditer(r"[A-Z]", ln):
        stacks[int((m.start() - 1) / 4)].append(m.group())

instructions: list[tuple[int, int, int]] = [
    tuple(int(s) for s in re.findall(r"\d+", s)) for s in inp[len(crateslns) + 1 :]
]

for move, from_, to in instructions:
    # for _ in range(move):
    #     stacks[to - 1].append(stacks[from_ - 1].pop())
    poped: list[str] = []
    for _ in range(move):
        poped.append(stacks[from_ - 1].pop())
    poped.reverse()

    stacks[to - 1].extend(poped)

print("\n".join(" ".join(a) for a in stacks))
for stack in stacks:
    print(stack[-1], end="")
