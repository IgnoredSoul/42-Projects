import os

with open(str(input("Original Ansi File\n> ")), "r") as f:
    original_contents = f.read()

def search_and_copy(path):
    for item in os.listdir(path):
        item_path = os.path.join(path, item)
        if os.path.isfile(item_path) and item == "AnsiColorSheet.hpp":
            with open(item_path, "w") as f:
                f.write(original_contents)
        elif os.path.isdir(item_path):
            search_and_copy(item_path)

search_and_copy(str(input("Starting Path\n> ")))
print("Finished")