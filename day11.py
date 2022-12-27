import re
from functools import reduce

reducer: int = 0


class Monke:
    def __init__(self, data: list[str]) -> None:
        print(data)

        self.number = int(re.search(r"(\d+)", data[0]).group())  # type: ignore
        self.items = [int(a.group()) for a in re.finditer(r"(\d+)", data[1])]

        def operation(val: int) -> int:
            return eval(data[2][19:].replace("old", str(val)))

        self.operation = operation

        self.divisor = int(re.search(r"(\d+)", data[3]).group())  # type: ignore

        def test(val: int) -> bool:
            return val % self.divisor == 0

        self.test = test

        self.true_ = int(re.search(r"(\d+)", data[4]).group())  # type: ignore
        self.false_ = int(re.search(r"(\d+)", data[5]).group())  # type: ignore

        self.inspected = 0

    def inspect(self) -> None:
        # print(f"MONKE {self.number} INSPECTS:  {len(self.items)} items")
        # print(f"\tBEFORE: {self.items}")
        for i, e in enumerate(self.items):
            oped = self.operation(e)
            oped %= reducer
            self.items[i] = int(oped)
        # self.items = [int(self.operation(e) / (reducer if self.operation(e) > reducer else 1)) for e in self.items]
        # print(f"\t AFTER: {self.items}")
        self.inspected += len(self.items)

    def throw_all(self) -> list[tuple[int, int]]:
        ret = [
            (self.true_ if self.test(item) else self.false_, item)
            for item in self.items
        ]
        self.items.clear()
        return ret

    def catch(self, item: int):
        self.items.append(item)

    def __str__(self) -> str:
        return (
            f"Monke {self.number}:\n"
            f"\tItems: {self.items}\n"
            f"\tOperation, Test\n"
            f"\tTrue: {self.true_}\n"
            f"\tFalse: {self.false_}\n"
        )


with open("inputs/in11.txt", "r") as f:
    lns = f.readlines()
    monkes = [Monke(lns[i : i + 7]) for i in range(0, len(lns), 7)]
    reducer = reduce(lambda a, b: a * b, [m.divisor for m in monkes])
    print(f"REDUCER: {reducer}\n\n")

for i in range(10000):
    for monke in monkes:
        # print(f"ROUND {i+1}")
        # print(f'ITEMS: {reduce(lambda a, b: a + b, [len(m.items) for m in monkes])}')
        monke.inspect()
        reciever = 0
        for reciever, item in monke.throw_all():
            # print(f"\tTHROWING item {item} TO monke {reciever}")
            monkes[reciever].catch(item)
        # print(f"MONKE: {monke.items}")
        # print(f"RECIEVER: {monkes[reciever].items}")

        # for monke in monkes:
        # print(f"MONKE {monke.number} : {monke.items}")
        # print()

monkes.sort(key=lambda m: m.inspected, reverse=True)

print([m.inspected for m in monkes])

monke_business = monkes[0].inspected * monkes[1].inspected

print(monke_business)
