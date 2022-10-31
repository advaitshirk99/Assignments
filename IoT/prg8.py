input_file = input("Enter the name of the input file:")
output_file = input("Enter the name of the output file:")

with open(input_file) as f:
    with open(output_file, "w") as f1:
        for line in f:
            f1.write(line)
