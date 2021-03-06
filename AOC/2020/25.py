from functools import lru_cache
from typing import Tuple, Final


class Solution:
    def __init__(self, public_keys: Tuple[int, int], test: bool = False):
        self.public_keys: Tuple[int, int]
        self.MOD: Final[int] = 20201227
        self.BASE: Final[int] = 7
        if test:
            self.test()
        self.public_keys = public_keys

    def test(self) -> None:
        self.public_keys = (5764801, 17807724)
        assert self.crack() == 14897079

    def crack(self) -> int:
        # Solution 1: O(c + lgd)
        card, door = self.public_keys
        card_round = self.findRound(card)   # O(c)
        encryption_key = self.pow(door, card_round)   # O(lgd)
        return encryption_key

    def crack_slower(self) -> int:
        # Solution 2: O(c + d)
        card, door = self.public_keys
        card_round = self.findRound(card)  # O(c)
        door_round = self.findRound(door)  # O(d)
        encryption_key = self.pow(self.BASE, card_round * door_round)  # O(lgd + lgc)
        return encryption_key

    def findRound(self, public: int) -> int:
            rnds: int = 1
            while self.pow(self.BASE, rnds) != public:
                rnds += 1
            return rnds

    @lru_cache(maxsize=None)
    def pow(self, base: int, exp: int) -> int:
        if exp == 1:
            return base % self.MOD
        half = self.pow(base, (exp >> 1))
        ans = half * half
        is_odd = exp & 1
        if is_odd:
            ans *= base
        return ans % self.MOD


public_keys = (14222596, 4057428)
s = Solution(public_keys, True)
print(s.crack())
