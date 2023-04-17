import os

def find_files_with_three_hashes(path):
    file_paths = []

    for root, dirs, files in os.walk(path):
        for file in files:
            if str(file) == "Makefile" or file.endswith('.c') or file.endswith('.h'):
                file_path = os.path.join(root, file)
                print(f"checking {file}")
                with open(file_path, 'r') as f:
                    first_line = f.readline()
                if first_line.startswith("/* ") or first_line.startswith("/**"):
                    file_paths.append(file_path)

    return file_paths

print(find_files_with_three_hashes('./'))