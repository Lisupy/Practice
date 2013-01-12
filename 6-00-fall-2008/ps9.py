# 6.00 Problem Set 9
#
# Name:
# Collaborators:
# Time:

from string import *

class Shape(object):
    def area(self):
        raise AttributeException("Subclasses should override this method.")

class Square(Shape):
    def __init__(self, h):
        """
        h: length of side of the square
        """
        self.side = float(h)
    def area(self):
        """
        Returns area of the square
        """
        return self.side**2
    def __str__(self):
        return 'Square with side ' + str(self.side)
    def __eq__(self, other):
        """
        Two squares are equal if they have the same dimension.
        other: object to check for equality
        """
        return type(other) == Square and self.side == other.side

class Circle(Shape):
    def __init__(self, radius):
        """
        radius: radius of the circle
        """
        self.radius = float(radius)
    def area(self):
        """
        Returns approximate area of the circle
        """
        return 3.14159*(self.radius**2)
    def __str__(self):
        return 'Circle with radius ' + str(self.radius)
    def __eq__(self, other):
        """
        Two circles are equal if they have the same radius.
        other: object to check for equality
        """
        return type(other) == Circle and self.radius == other.radius

# Problem 1: Create the Triangle class
#
class Triangle(Shape):
    """docstring for Triangle"""
    def __init__(self, base, height):
        self.base = base
        self.height = height

    def area(self):
        return self.base*self.height*0.5

    def __str__(self):
        return 'Triangle with base ' + str(self.base) + ' and height ' + str(self.height) 
        #return  'Triangle with a base of %0.2f and height of %0.2f.' % (self.base, self.height)

    def __eq__(self, other):
        return type(other) == Triangle and self.base == other.base and self.height == other.height



# Problem 2: Create the ShapeSet class
#
## TO DO: Fill in the following code skeleton according to the
##    specifications.

class ShapeSet:

    def __init__(self):
        """
        Initialize any needed variables
        """
        self.set = []

    def addShape(self, sh):
        """
        Add shape sh to the set; no two shapes in the set may be
        identical
        sh: shape to be added
        """
        if sh in self.set:
            print "aleady in set"
            return
        self.set.append(sh)

    def __iter__(self):
        """
        Return an iterator that allows you to iterate over the set of
        shapes, one shape at a time
        """
        self.place = 0
        return self
    def next(self):
        if self.place >= len(self.set):
            raise StopIteration
        self.place += 1
        return self.set[self.place-1]


    def __str__(self):
        """
        Return the string representation for a set, which consists of
        the string representation of each shape, categorized by type
        (circles, then squares, then triangles)
        """
        st = ""
        for i in sorted(self.set):
            st += str(i) + '\n'
        return st  



#
# Problem 3: Find the largest shapes in a ShapeSet
#
def findLargest(shapes):
    """
    Returns a tuple containing the elements of ShapeSet with the
       largest area.
    shapes: ShapeSet
    """
    Largest = Square(0)
    for sh in shapes:
        if Largest.area() < sh.area():
            Largest = sh
    return Largest 
    ## TO DO

#
# Problem 4: Read shapes from a file into a ShapeSet
#
def readShapesFromFile(filename):
    """
    Retrieves shape information from the given file.
    Creates and returns a ShapeSet with the shapes found.
    filename: string
    """
    shapes = ShapeSet()
    for line in file(filename):
      #  print line
        obj_para = line.rstrip('\n').split(',')
       # print obj_para
        if obj_para[0] == "circle":
            sh = Circle(float(obj_para[1]))
        elif obj_para[0] == "square":
            sh = Square(float(obj_para[1]))
        elif obj_para[0] == "triangle":
            sh = Triangle(float(obj_para[1]), float(obj_para[2]))
        shapes.addShape(sh)
    return shapes

print type(float("1.0"))
print readShapesFromFile("shapes.txt")
print "============="
for i in readShapesFromFile("shapes.txt"):
    print i, i.area()