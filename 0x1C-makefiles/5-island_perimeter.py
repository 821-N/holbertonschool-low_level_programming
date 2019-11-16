#!/user/bin/python3


def island_perimeter(grid):
    def find_land(grid):
        for y in range(len(grid)):
            row = grid[y]
            for x in range(len(row)):
                if row[x]:
                    return (x, y)
        return None

    start = find_land(grid)
    if not start:
        return 0

    def cw(dir):
        """rotate a cardinal direction 90 degrees clockwise"""
        return (dir[1], -dir[0])

    def ccw(dir):
        return (-dir[1], dir[0])

    def adddir(pos, dir):
        return (pos[0]+dir[0], pos[1]+dir[1])

    def check(grid, pos):
        """Check if tile is land"""
        return (
            0 <= pos[1] < len(grid) and
            0 <= pos[0] < len(grid[pos[1]]) and
            grid[pos[1]][pos[0]]
        )

    perimeter = 0
    dir = (1, 0)
    startdir = dir
    first = True

    def turn(grid, pos, dir):
        nonlocal perimeter
        dir = cw(dir)  # try turning left
        for i in range(4):
            if dir == startdir and pos == start and not first:
                perimeter -= 1
                return None

            if check(grid, adddir(pos, dir)):  # find place to move to
                return dir
            perimeter += 1  # add 1 to perimeter for each wall that is hit
            dir = ccw(dir)  # turn right
        return None

    def debug(grid, dir, pos):
        for y in range(len(grid)):
            row = grid[y]
            for x in range(len(row)):
                if (x, y) == pos:
                    print(end="*")
                elif row[x]:
                    print(end="#")
                else:
                    print(end="~")
            print()
        print(dir)

    # Edge following
    pos = start
    while 1:
        dir = turn(grid, pos, dir)
        if not dir:
            break
        first = False
        pos = adddir(pos, dir)
        # debug(grid, dir, pos)
        # input()

    return perimeter
