def main():
    height = get_height()
    blocks = 1
    for _ in range(height):
        for column in range(height):
            if height - column <= blocks:
                print("#", end="")
            else:
                print(" ", end="")
        blocks += 1
        print(end="\n")

def get_height():
    while True:
        try:
            n = int(input("Height: "))
            if 0 < n < 9:
                return n
        except ValueError:
            print("Not an integer")

main()

