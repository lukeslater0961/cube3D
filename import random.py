import random

def generate_maze(width, height):
    # Initialize the maze with walls (1s)
    maze = [[1] * width for _ in range(height)]
    
    # Iterative stack-based carving function
    def carve_iteratively(x, y):
        stack = [(x, y)]  # Stack to track the cells to process
        while stack:
            x, y = stack.pop()
            if maze[y][x] == 0:
                continue
            maze[y][x] = 0  # Mark as a floor (0)

            # Shuffle the four possible directions (up, down, left, right)
            directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
            random.shuffle(directions)

            for dx, dy in directions:
                nx, ny = x + dx * 2, y + dy * 2
                # Ensure the new cell is within bounds and hasn't been carved yet
                if 0 < nx < width - 1 and 0 < ny < height - 1 and maze[ny][nx] == 1:
                    maze[y + dy][x + dx] = 0  # Carve the wall between the current and new cell
                    stack.append((nx, ny))

    # Start carving from (1, 1)
    carve_iteratively(1, 1)
    
    return maze

def save_maze_as_cub(maze, filename):
    with open(filename, 'w') as file:
        # Write the dimensions at the beginning of the file
        file.write(f"{len(maze)} {len(maze[0])} 1\n")
        # Write the maze data row by row
        for row in maze:
            file.write("".join(map(str, row)) + "\n")

if __name__ == "__main__":
    width, height = 1000, 1000  # Specify the size of the maze
    maze = generate_maze(width, height)
    save_maze_as_cub(maze, "maze.cub")
    print("Maze generated and saved as maze.cub")
