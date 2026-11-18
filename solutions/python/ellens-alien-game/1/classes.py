"""Solution to Ellen's Alien Game exercise."""

class Alien:
    """Create an Alien object with location x_coordinate and y_coordinate.

    Attributes:
        (class) total_aliens_created (int): Total number of Alien instances.
        x_coordinate (int): Position on the x-axis.
        y_coordinate (int): Position on the y-axis.
        health (int): Number of health points.

    Methods:
        hit(): Decrement Alien health by one point.
        is_alive(): Return a boolean for if Alien is alive (if health is > 0).
        teleport(new_x_coordinate, new_y_coordinate): Move Alien object to new coordinates.
        collision_detection(other): Implementation TBD.

    """
    total_aliens_created = 0
    aliens = []
    
    def __init__(self, *args):
        self.x_coordinate = args[0]
        self.y_coordinate = args[1]
        self.health = 3
        Alien.total_aliens_created += 1
        Alien.aliens.append(self)
    
    def hit(self):
        self.health -= 1

    def is_alive(self):
        if self.health > 0:
            return True
        return False

    def teleport(self, *args):
        self.x_coordinate = args[0]
        self.y_coordinate = args[1]

    def collision_detection(self, object):
        if self.x_coordinate == object.x_coordinate and self.y_coordinate == object.y_coordinate:
            return object
        return None

#TODO (Student): Create the new_aliens_collection() function below to call your Alien class with a list of coordinates
def new_aliens_collection(coordinates):
    aliens = []
    for i in coordinates:
        aliens.append(Alien(i[0], i[1]))
    return aliens