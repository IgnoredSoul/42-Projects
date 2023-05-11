filename = str(input("Filename\n> "))
path = str(input("Path\n> "))

open(f"{path}/{filename}.cpp", 'w')
open(f"{path}/{filename}.hpp", 'w')