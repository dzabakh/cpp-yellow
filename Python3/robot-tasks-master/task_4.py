#!/usr/bin/python3

from pyrob.api import *


@task
def task_3_3():
    below = wall_is_beneath()
    above = wall_is_above()
    right = wall_is_on_the_right()
    left = wall_is_on_the_left()

    if below and right and left and not above:
        move_up()
    if not below and right and left and above:
       move_down()
    if below and not right and left and above:
       move_right()
    if below and right and not left and above:
       move_left()


if __name__ == '__main__':
    run_tasks()
