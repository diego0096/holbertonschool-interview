#!/usr/bin/python3
""" Prime Game """


def isprime(n):
    """Number to check if it is prime"""
    for i in range(2, n):
        if n % i == 0:
            return False
    return True


def delete_numbers(n, nums):
    """Delete numbers - assign zero"""
    for i in range(len(nums)):
        if nums[i] % n == 0:
            nums[i] = 0


def isWinner(x, nums):
    """Where x is the number of rounds"""
    nums.sort()
    winner = False
    Maria = 0
    Ben = 0
    for game in range(x):
        nums2 = list(range(1, nums[game] + 1))
        turn = 0
        while True:
            """Uncomment to monitor turns"""
            change = False
            for i, n in enumerate(nums2):
                if n > 1 and isprime(n):
                    delete_numbers(n, nums2)
                    change = True
                    turn += 1
                    break
            if change is False:
                break
        if turn % 2 != 0:
            Maria += 1
        else:
            Ben += 1
    if Maria == Ben:
        return None
    if Maria > Ben:
        return "Maria"
    return "Ben"
