#!/usr/bin/python3

from pyrob.api import *


@task
def task_8_22():
    while not wall_is_above():
        move_up()
    if not wall_is_on_the_right():
        while not wall_is_on_the_right():
            move_right()
        return
    if not wall_is_on_the_left():
        while not wall_is_on_the_left():
            move_left()
        return



if __name__ == '__main__':
    run_tasks()
