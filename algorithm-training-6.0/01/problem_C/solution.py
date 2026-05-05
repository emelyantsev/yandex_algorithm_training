from typing import List, Optional, Tuple


def find_hash_bbox(table: List[str]) -> Optional[Tuple[int, int, int, int]]:
    """Bounding box (r1, c1, r2, c2) of all '#' cells, or None if there are none."""
    n = len(table)
    rs, cs = [], []
    for r in range(n):
        for c in range(n):
            if table[r][c] == '#':
                rs.append(r)
                cs.append(c)
    if not rs:
        return None
    return min(rs), min(cs), max(rs), max(cs)


def find_dot_components(
    table: List[str], r1: int, c1: int, r2: int, c2: int
) -> Optional[List[Tuple[int, int, int, int]]]:
    """Find 4-connected components of '.' inside the rectangle [r1..r2] x [c1..c2].

    Returns the list of bounding boxes if every component is itself a filled
    rectangle. Returns None if any component is not a rectangle.
    """
    visited = set()
    components = []
    for r in range(r1, r2 + 1):
        for c in range(c1, c2 + 1):
            if table[r][c] != '.' or (r, c) in visited:
                continue
            stack = [(r, c)]
            cells = []
            while stack:
                cr, cc = stack.pop()
                if (cr, cc) in visited:
                    continue
                if not (r1 <= cr <= r2 and c1 <= cc <= c2):
                    continue
                if table[cr][cc] != '.':
                    continue
                visited.add((cr, cc))
                cells.append((cr, cc))
                stack.extend([(cr + 1, cc), (cr - 1, cc), (cr, cc + 1), (cr, cc - 1)])

            rows = [cell[0] for cell in cells]
            cols = [cell[1] for cell in cells]
            cr1, cc1, cr2, cc2 = min(rows), min(cols), max(rows), max(cols)
            if len(cells) != (cr2 - cr1 + 1) * (cc2 - cc1 + 1):
                return None
            components.append((cr1, cc1, cr2, cc2))
    return components


def is_i(table: List[str]) -> bool:
    bbox = find_hash_bbox(table)
    if bbox is None:
        return False
    r1, c1, r2, c2 = bbox
    for r in range(r1, r2 + 1):
        for c in range(c1, c2 + 1):
            if table[r][c] != '#':
                return False
    return True


def is_o(table: List[str]) -> bool:
    bbox = find_hash_bbox(table)
    if bbox is None:
        return False
    r1, c1, r2, c2 = bbox
    comps = find_dot_components(table, r1, c1, r2, c2)
    if comps is None or len(comps) != 1:
        return False
    dr1, dc1, dr2, dc2 = comps[0]
    return dr1 > r1 and dr2 < r2 and dc1 > c1 and dc2 < c2


def is_c(table: List[str]) -> bool:
    bbox = find_hash_bbox(table)
    if bbox is None:
        return False
    r1, c1, r2, c2 = bbox
    comps = find_dot_components(table, r1, c1, r2, c2)
    if comps is None or len(comps) != 1:
        return False
    dr1, dc1, dr2, dc2 = comps[0]
    return dr1 > r1 and dr2 < r2 and dc1 > c1 and dc2 == c2


def is_l(table: List[str]) -> bool:
    bbox = find_hash_bbox(table)
    if bbox is None:
        return False
    r1, c1, r2, c2 = bbox
    comps = find_dot_components(table, r1, c1, r2, c2)
    if comps is None or len(comps) != 1:
        return False
    dr1, dc1, dr2, dc2 = comps[0]
    return dr1 == r1 and dr2 < r2 and dc1 > c1 and dc2 == c2


def is_h(table: List[str]) -> bool:
    bbox = find_hash_bbox(table)
    if bbox is None:
        return False
    r1, c1, r2, c2 = bbox
    comps = find_dot_components(table, r1, c1, r2, c2)
    if comps is None or len(comps) != 2:
        return False

    upper, lower = sorted(comps, key=lambda x: x[0])
    ur1, uc1, ur2, uc2 = upper
    lr1, lc1, lr2, lc2 = lower

    if ur1 != r1 or lr2 != r2:
        return False
    if uc1 != lc1 or uc2 != lc2:
        return False
    if uc1 <= c1 or uc2 >= c2:
        return False
    if lr1 - ur2 < 2:
        return False
    return True


def is_p(table: List[str]) -> bool:
    bbox = find_hash_bbox(table)
    if bbox is None:
        return False
    r1, c1, r2, c2 = bbox
    comps = find_dot_components(table, r1, c1, r2, c2)
    if comps is None or len(comps) != 2:
        return False

    upper, lower = sorted(comps, key=lambda x: x[0])
    ur1, uc1, ur2, uc2 = upper
    lr1, lc1, lr2, lc2 = lower

    if lr2 != r2 or lc2 != c2:
        return False
    if lr1 <= r1 or lc1 <= c1:
        return False
    if not (ur1 > r1 and ur2 < r2 and uc1 > c1 and uc2 < c2):
        return False
    if uc1 != lc1:
        return False
    if uc2 >= lc2:
        return False
    if lr1 - ur2 < 2:
        return False
    return True


def solve(table: List[str]) -> None:

    if is_i(table):
        print('I')
    elif is_o(table):
        print('O')
    elif is_c(table):
        print('C')
    elif is_l(table):
        print('L')
    elif is_h(table):
        print('H')
    elif is_p(table):
        print('P')
    else:
        print('X')


if __name__ == '__main__':

    n = int(input())

    lines = []

    for i in range(n):

        line = input()
        assert len(line) == n
        lines.append(line)

    solve(lines)
