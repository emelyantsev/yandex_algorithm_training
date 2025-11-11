
from dataclasses import dataclass
from typing import List

@dataclass
class Car:
    x: int
    y: int
    vx: int
    vy: int


if __name__ == '__main__':

    line = list(map(int, input().split() ) )

    N, L, W = line[0], line[1], line[2]

    cars: List[Car] = []

    for i in range(N):

        line = list(map(int, input().split() ) )
        x, y, vx, vy = line[0], line[1], line[2], line[3]

        assert x >= 0 and x < L
        assert y > 0 and y < W

        cars.append(Car(x=x,y=y,vx=vx,vy=vy))


    events = []


    for i, car in enumerate(cars):

        if car.vx == 0:
            continue

        t = (L - car.x) / car.vx

        if t < 0:
            continue

        y = car.y + car.vy * t

        if y <= 0 or y >= W:
            continue

        events.append( (t, 1, i) )


    for i in range(N):

        for j in range(i+1, N):

            if cars[i].vx == cars[j].vx and cars[i].vy == cars[j].vy :
                continue

            t = ( ( cars[j].x - cars[i].x ) / ( cars[i].vx - cars[j].vx ) ) if cars[i].vx != cars[j].vx else ( ( cars[j].y - cars[i].y ) / ( cars[i].vy - cars[j].vy ) )

            xi =  cars[i].x + cars[i].vx * t
            xj = cars[j].x + cars[j].vx * t

            yi = cars[i].y + cars[i].vy * t
            yj = cars[j].y + cars[j].vy * t

            if xi != xj or yi != yj :
                continue

            if xi >= 0 and xi <= L and yi >= 0 and yi <= W:
                events.append( (t, -1, (i, j) ) )

    
    events.sort()

    best_time = None
    best_cars = []

    time_collapsed = [None for i in range(N)]

    for e in events:

        if e[1] == -1:

            i = e[2][0]
            j = e[2][1]

            t = e[0]

            if time_collapsed[i] is None and time_collapsed[j] is None:
                time_collapsed[i] = t
                time_collapsed[j] = t
            elif time_collapsed[i] is None and time_collapsed[j] == t:
                time_collapsed[i] = t
            elif time_collapsed[j] is None and time_collapsed[i] == t:
                time_collapsed[j] = t
            else:
                pass
        else:

            t = e[0]
            ind = e[2]

            if time_collapsed[ind] is None:

                if best_time is None or t == best_time:

                    best_cars.append(ind)
                    best_time = t
                
                elif t > best_time:
                    break

print(len(best_cars))

if len(best_cars) > 0:
    best_cars.sort()

for car in best_cars:
    print(car + 1, end=' ')

print()



 

