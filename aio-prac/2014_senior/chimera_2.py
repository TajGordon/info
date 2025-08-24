n = int(input())

lion = list(input())
snake = list(input())
goat = list(input())

lc = 0
sc = 0
gc = 0

singles_count = 0

for i in range(n).__reversed__():
    if lion[i] == snake[i] == goat[i]:
        lc += 1
        sc += 1
        gc += 1

        lion.pop(i)
        snake.pop(i)
        goat.pop(i)

        continue
    if lion[i] != snake[i] and lion[i] != goat[i] and snake[i] != goat[i]:
        singles_count += 1
        lion.pop(i)
        snake.pop(i)
        goat.pop(i)

print(lion)
print(snake)
print(goat)
print(singles_count)
outer_changed = True
while outer_changed:
    outer_changed = False
    changed = True
    while changed:
        changed = False # if too slow, can use like priority queues to sort based on who they are a double for, like with a tuple or som and precalc
        for i in range(len(goat)):
            if lion[i] == snake[i] and sc == min([lc, sc, gc]) or lc == min([lc, sc, gc]):
                lc += 1
                sc += 1

                lion.pop(i)
                snake.pop(i)
                goat.pop(i)

                changed = True
                break
            elif lion[i] == goat[i] and gc == min([lc, sc, gc]) or lc == min([lc, sc, gc]):
                lc += 1
                gc += 1

                lion.pop(i)
                snake.pop(i)
                goat.pop(i)

                changed = True
                break
            elif snake[i] == goat[i] and gc == min([lc, sc, gc]) or sc == min([lc, sc, gc]):
                sc += 1
                gc += 1

                lion.pop(i)
                snake.pop(i)
                goat.pop(i)

                changed = True
                break
    print(lion)
    if singles_count > 0:
        for i in range(len(goat)):
            lc += 1
            sc += 1
            gc += 1
            singles_count -= 1
            outer_changed = True
            if singles_count <= 0:
                break
    if singles_count <= 0:
        lc += (len(goat)//3)
        sc += (len(goat)//3)
        gc += (len(goat)//3)


print(lion)
print(snake)
print(goat)
print(singles_count)