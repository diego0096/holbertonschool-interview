#!/usr/bin/python3
"""Module used to add two arrays."""


def makeChange(coins, total):
    """Given a pile of coins of different values"""
    if total <= 0:
        return 0
    if (coins is None or len(coins) == 0):
        return -1
    change = 0
    my_coins = sorted(coins, reverse=True)
    money_left = total
    for coin in my_coins:
        while (money_left % coin >= 0 and money_left >= coin):
            change += int(money_left / coin)
            money_left = money_left % coin
    change = change if money_left == 0 else -1
    return change
