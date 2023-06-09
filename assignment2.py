'''Consider telephone book database of N clients. Make use of a hash table implementation to quickly
 look up client's telephone number. Make use of two collision handling techniques and compare them 
 using number of comparisons required to find a set of telephone numbers'''


class accept:
    def __init__(self):
        self._name = None
        self._num = None
#         # self._num=None

    def set(self, name, number):
        self._name = name
        self._num = number


class dhash(accept):
    def __init__(self):
        self.a = []

    def insert(self, x, n):
        h1 = accept()
        self.a = [None]*n
        for i in range(x):
            na = str(input("Enter the name of the client :"))
            no = int(input("Enter the tele of the client :"))
            h1.set(na, no)
            k = 1
            hash1 = no % n

            if (self.a[hash1] == None):
                self.a[hash1] = [na, no]
            else:
                while (True):
                    hash2 = 7-(no % 7)
                    inde = (hash1+(hash2*k)) % n
                    if (self.a[inde] == None):
                        self.a[inde] = [na, no]
                        break
                    else:
                        k = k+1

    def search(self, n):
        k = 1
        key = int(input("Enter the no of the client :"))
        hash1 = key % n
        if self.a[hash1] is not None and self.a[hash1][0] == key:
            print("Record found")
        else:
            while (True):
                hash2 = 7-(key % 7)
                prime = (hash1+(hash2*k)) % n
                if self.a[prime] is not None and self.a[prime][1] == key:
                    print("Record found")
                    break
                else:
                    k = k+1

    def display(self, n):
        for i in range(n):
            print(self.a[i])


def main():

    x1 = dhash()
    n = 0
    while (True):
        print("------MENU------", "\n 1.Insert",
              "\n 2.Display", "\n 3.Search", "\n 4.Exit")
        ch = int(input("Enter your choice from the Menu : "))
        if (ch == 1):
            n = int(input(" Enter the size of the hash table : "))
            x = int(input(" Enter the total no client : "))
            x1.insert(x, n)
        elif (ch == 2):
            print("The records are :")
            x1.display(n)
        elif (ch == 3):
            x1.search(n)
        elif (ch == 4):
            break
        else:
            print("You entered wrong choice ")


main()


'''Linear Probing'''
 

class accept:
    def _init_(self):
        self._name = None
        self._num = None

    def set(self, name, number):
        self._name = name
        self._num = number


class lprobe(accept):
    def _init_(self):
        self.a = []

    def insert(self, x, n):
        h1 = accept()
        self.table = [None]*n

        for i in range(x):
            na = str(input("Enter the name of the student :"))
            no = int(input("Enter the rollno of the student :"))
            h1.set(na, no)
            hash = no % n
            while self.table[hash] is not None:
                hash = (hash + 1) % n
            self.table[hash] = [na, no]

    def search(self, n):
        key = int(input("Enter the rollno of the student :"))
        index = key % n
        while self.table[index] is not None:
            if self.table[index][0] == key:
                print("Record found")
                print(f"The name of  roll no {key} is :", self.table[index][0])
                break

            index = (index + 1) % n

    def display(self, n):
        for i in range(n):
            print(self.table[i])


def main():

    obj = lprobe()
    n = 0
    while (True):
        print("------MENU------", "\n 1.Insert",
              "\n 2.Display", "\n 3.Search", "\n 4.Exit")
        ch = int(input("Enter your choice from the Menu : "))
        if (ch == 1):
            n = int(input(" Enter the size of the hash table : "))
            x = int(input(" Enter the total no students : "))
            obj.insert(x, n)
        elif (ch == 2):
            print("The records are :")
            obj.display(n)
        elif (ch == 3):
            obj.search(n)
        elif (ch == 4):
            break
        else:
            print("You entered wrong choice ")


main()
