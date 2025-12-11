# Penguin Size Program

This program reads data from a CSV file and displays information about penguins. It uses two classes to stay organized:

## PenguinRecord
This class represents one row from the CSV file.  
It stores:
- species
- island
- culmen length
- culmen depth
- body mass

It also has a print function that displays this information.

## PenguinDataset
This class loads the CSV file and creates PenguinRecord objects from each valid row.

It:
1. Opens the CSV file  
2. Skips the header line  
3. Reads each line and splits it into columns  
4. Converts numeric values (like culmen length) from text to numbers  
5. Stores each row as a PenguinRecord  
6. Prints all loaded records

## main()
The main function loads the dataset and prints the results.

Overall, the code reads the CSV, stores the data in objects, and prints each penguin's information.
