# Search for a file by the name ##
import os

fileName = str(input("Enter the name of the file: "))
partitions = ["D:\\", "C:\\"]
found = False
for partition in partitions:
    for root, dirs, files in os.walk(partition):
        if fileName in files:
            print("The path of the file: ", os.path.join(root, fileName))
            found = True

if found == False:
    print("The file doesn't exist")
    exit()
else:
    exit()