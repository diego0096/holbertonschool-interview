#!/usr/bin/python3
"""Module used to add two arrays"""


def canUnlockAll(boxes):
    """Method that determines if all the boxes can be opened."""

    if (type(boxes) is not list):
        return False
    if (len(boxes) == 0):
        return False
    n_boxes = len(boxes)
    unlocked_lst = ["Locked"] * n_boxes
    unlocked_lst[0] = "Unlocked"

    next = boxes[0]
    while (unlocked_lst.count("Unlocked") < n_boxes and next is not None):
        open_me = next
        next = go_open(open_me, boxes, unlocked_lst)

    if (unlocked_lst.count("Unlocked") == n_boxes):
        return True
    return False


def go_open(open_me, boxes, unlocked_lst):
    """Opens a single box, and check it as unlocked in unlocked_list."""

    if (open_me is None):
        return None
    elif (len(open_me) == 0):
        return None
    elif (len(open_me) == 1):
        i = open_me[0]
        if (len(boxes) <= i):
            return None
        if (unlocked_lst[i] == "Unlocked"):
            return None
        else:
            unlocked_lst[i] = "Unlocked"
            if(boxes[i] == open_me):
                return None
        return boxes[i]

    else:
        next_boxes = [None] * len(open_me)
        i = 0
        for box_i in open_me:
            if (type(box_i) == int):
                open_me_i = [box_i]
            else:
                open_me_i = box_i
            next_boxes[i] = go_open(open_me_i, boxes, unlocked_lst)
            i += 1

        if len(next_boxes) == 0:
            return None
        if next_boxes.count(None) == i:
            return None
        return next_boxes
