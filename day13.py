from ast import literal_eval
from itertools import zip_longest
from functools import cmp_to_key


with open("inputs/in13.txt", "r") as f:
    # lines = f.readlines()
    # pairs = []
    # for i in range(0, len(lines), 3):
    #     pairs.append((literal_eval(lines[i]), literal_eval(lines[i + 1])))  # type: ignore

    packets = [literal_eval(l) for l in f.readlines() if l != "\n"]
    packets.extend([[[2]], [[6]]])


def compare_list(left, right) -> int:
    for l, r in zip_longest(left, right):
        if l is None:
            return -1
        if r is None:
            return 1

        if isinstance(l, list) or isinstance(r, list):
            match compare_list(
                l if isinstance(l, list) else [l], r if isinstance(r, list) else [r]
            ):
                case 1:
                    return 1
                case -1:
                    return -1
                case 0:
                    continue

        if l < r:
            return -1

        if l > r:
            return 1
    return 0


# indices = []
# for i, (left, right) in enumerate(pairs):
#     if compare_list(left, right):
#         indices.append(i + 1)
# print(sum(indices))

packets = sorted(packets, key=cmp_to_key(compare_list))


print(d1 := packets.index([[2]]) + 1)
print(d2 := packets.index([[6]]) + 1)
print(d1 * d2)
