#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

class PenguinRecord {
private:
    // These correspond to columns we care about from penguins_size.csv
    std::string species;        // penguin species (Adelie, Gentoo, Chinstrap)
    std::string island;         // island where it was observed
    double culmenLength;        // culmen (bill) length in mm
    double culmenDepth;         // culmen (bill) depth in mm
    double bodyMass;            // body mass in grams

public:
    // Constructor that takes all 5 fields we want to store
    PenguinRecord(const std::string &species_,
                  const std::string &island_,
                  double culmenLength_,
                  double culmenDepth_,
                  double bodyMass_)
        : species(species_),
          island(island_),
          culmenLength(culmenLength_),
          culmenDepth(culmenDepth_),
          bodyMass(bodyMass_) {}

    // Print this penguin's data in a readable format for the user
    void print() const {
        std::cout << "Species:       " << species      << "\n"
                  << "Island:        " << island       << "\n"
                  << "Culmen (L/D):  " << culmenLength << " mm / "
                                       << culmenDepth  << " mm\n"
                  << "Body mass:     " << bodyMass     << " g\n";
    }
};

class PenguinDataset {
private:
    // Vector to store each row as a PenguinRecord object
    std::vector<PenguinRecord> records;

public:
   
    bool loadFromCsv(const std::string &filename, std::size_t maxRows = 10) {
        std::ifstream file(filename);

        // If the file cannot be opened, print an error and stop
        if (!file.is_open()) {
            std::cerr << "Error: Could not open file '" << filename << "'.\n";
            return false;
        }

        std::string line;

        if (!std::getline(file, line)) {
            std::cerr << "Error: File is empty or unreadable.\n";
            return false;
        }

        std::size_t count = 0;
        while (std::getline(file, line) && count < maxRows) {
            // Skip completely empty lines if they appear
            if (line.empty()) {
                continue;
            }

            std::stringstream ss(line);

            // Temp strings to store raw text for each column
            std::string speciesStr;
            std::string islandStr;
            std::string culmenLengthStr;
            std::string culmenDepthStr;
            std::string flipperLengthStr;
            std::string bodyMassStr;
            std::string sexStr;

            // Read each column separated by commas
            if (!std::getline(ss, speciesStr, ','))        continue;
            if (!std::getline(ss, islandStr, ','))         continue;
            if (!std::getline(ss, culmenLengthStr, ','))   continue;
            if (!std::getline(ss, culmenDepthStr, ','))    continue;
            if (!std::getline(ss, flipperLengthStr, ','))  continue;
            if (!std::getline(ss, bodyMassStr, ','))       continue;
            // Sex is the last column; we read it to move the stream forward
            std::getline(ss, sexStr, ',');

            // Some rows in the dataset can have missing numeric values
            // If body mass or culmen numbers are missing, skip this row
            if (culmenLengthStr.empty() ||
                culmenDepthStr.empty()  ||
                bodyMassStr.empty()) {
                continue;
            }

            try {
                // Convert numeric strings to double
                double culmenLength = std::stod(culmenLengthStr);
                double culmenDepth  = std::stod(culmenDepthStr);
                double bodyMass     = std::stod(bodyMassStr);

                // Create a PenguinRecord object from the parsed values
                PenguinRecord record(speciesStr,
                                     islandStr,
                                     culmenLength,
                                     culmenDepth,
                                     bodyMass);

                // Add it to our list of records
                records.push_back(record);
                ++count;
            }
            catch (const std::exception &e) {
                // If conversion fails, we skip this row but continue reading.
                std::cerr << "Warning: Skipping invalid row: " << line << "\n";
                continue;
            }
        }

        // If we ended up with no records at all, consider loading a failure
        if (records.empty()) {
            std::cerr << "No valid data rows were loaded from the file.\n";
            return false;
        }

        return true;
    }

    // Print all stored penguin records in order
    void printAll() const {
        std::cout << "Loaded " << records.size()
                  << " penguin records from the dataset.\n\n";

        for (std::size_t i = 0; i < records.size(); ++i) {
            std::cout << "Penguin #" << (i + 1) << "\n";
            records[i].print();
            std::cout << "---------------------------------\n";
        }
    }
};

int main() {
    // Name of the CSV file
    std::string filename = "penguins_size.csv";

    // Create a PenguinDataset object to manage loading and printing
    PenguinDataset dataset;

    // Load at least 10 rows from the CSV file using our class
    if (!dataset.loadFromCsv(filename, 10)) {
        std::cerr << "Failed to load penguin dataset. "
                  << "Make sure '" << filename << "' is in the same folder.\n";
        return 1;  // non-zero → indicates an error
    }

    dataset.printAll();

    return 0; 
}
