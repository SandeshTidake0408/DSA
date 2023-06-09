# To create ADT that implement the "set" concept. a. Add (newElement) -Place a value into the set b. Remove (element) Remove the value c. Contains (element) Return true if element is in collection d. Size () Return number of values in collection Iterator () Return an iterator used to loop over collection e. Intersection of two sets f. Union of two sets g. Difference between two sets h.Subset

class Set:
    def __init__(self):
        self.elements = []

    def addItem(self, item):
        flag = False
        if item in self.elements:
            flag = True
        if flag == True:
            print("Item is already Present !!")
        else:
            self.elements.append(item)
            print("Item Added Successfully !!")

    def removeItem(self, item):
        flag = False
        if item in self.elements:
            flag = True
        if flag == True:
            self.elements.remove(item)
            print("Item Deleted Successfully !!")
        else:
            print("Item not found !!")

    def unionSet(self, B):
        result = []
        for i in self.elements:
            result.append(i)
        for i in B.elements:
            if i not in result:
                result.append(i)
        return result

    def intersectionSet(self, B):
        result = []
        for i in B.elements:
            if i in self.elements:
                result.append(i)
        return result

    def symmetricDiff(self, B):
        result = []
        for i in self.elements:
            if i not in B.elements:  # A - B
                result.append(i)
        return result

    def subset(self, B):
        for i in B:
            if i not in self.elements:
                return "It is not subset"
        return "It is subset"
