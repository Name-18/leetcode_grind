# Last updated: 6/17/2026, 1:20:37 AM
1class Solution(object):
2    def fizzBuzz(self, n):
3        return [
4            "FizzBuzz" if i % 15 == 0 else "Fizz" if i % 3 == 0 else "Buzz" if i % 5 == 0 else str(i)
5            for i in range(1, n + 1)
6        ]