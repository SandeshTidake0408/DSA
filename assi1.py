import assignment1

object = assignment1.Set()
object_2 = assignment1.Set()


elements = int(input("Enter the number of elements in Set 1 : "))
print("Enter the Element one by one for set 1")
for i in range(elements):
    temp = int(input())
    object.addItem(temp)

print(object.elements)


elements_2 = int(input("Enter the number of elements in Set 2 : "))
print("Enter the Element one by one for set 2 ")
for i in range(elements_2):
    temp = int(input())
    object_2.addItem(temp)

print(object_2.elements)
print("Union Of Set A & B : ", object.unionSet(object_2))
print("Intersection of set A & B : ", object.intersectionSet(object_2))
print("Symmetric Deff  A - B : ", object.symmetricDiff(object_2))


