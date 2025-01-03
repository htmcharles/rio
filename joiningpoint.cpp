def find_square(points):
    # Set to store unique points
    unique_points = set(tuple(point) for point in points)
    
    # If there are not exactly 4 unique points, it's impossible to form a square
    if len(unique_points) != 4:
        return "Impossible"
    
    # Sorting points
    points = list(unique_points)
    points.sort()
    
    # Check if the points form a valid square
    # Square properties: we expect two x-coordinates and two y-coordinates
    x_coords = {point[0] for point in points}
    y_coords = {point[1] for point in points}
    
    # If we do not have exactly 2 unique x and 2 unique y coordinates, it's impossible
    if len(x_coords) != 2 or len(y_coords) != 2:
        return "Impossible"
    
    # The opposite corners can be derived from the unique x and y values
    x1, x2 = x_coords
    y1, y2 = y_coords
    
    # Return the two opposite corners of the square
    return f"{x1} {y1} {x2} {y2}"

# Input
n = int(input())  # Number of points
points = [list(map(int, input().split())) for _ in range(n)]

# Find the square
result = find_square(points)
print(result)

