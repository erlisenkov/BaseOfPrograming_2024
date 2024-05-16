#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits> // for std::numeric_limits
#include <string>
#include <vector>

struct Temperature {
  Temperature(int min, int max, int aver, int month, int year)
      : min{min}, max{max}, average{aver}, monthNum{month}, year{year} {}

  int min;
  int max;
  int average;
  int monthNum;
  int year;
};

class Db {
public:
  Db(std::string connectionString) : connectionString{connectionString} {}

  void Save() {
    std::ofstream out(connectionString);
    if (out.is_open()) {
      for (const Temperature &temperature : temps) {
        out << temperature.min << " " << temperature.max << " "
            << temperature.average << " " << temperature.monthNum << " "
            << temperature.year << std::endl;
      }
    }
    out.close();
  }

  void Load() {
    std::ifstream in(connectionString);
    if (in.is_open()) {
      int min, max, average, monthNum, year;
      temps.clear();
      while (in >> min >> max >> average >> monthNum >> year) {
        temps.push_back(Temperature{min, max, average, monthNum, year});
      }
    }
    in.close();
  }

  void Add(Temperature temp) { temps.push_back(temp); }

  void Edit(int index, Temperature newTemp) {
    if (index >= 0 && index < temps.size()) {
      temps[index] = newTemp;
    } else {
      std::cerr << "Invalid index" << std::endl;
    }
  }

  void Delete(int index) {
    if (index >= 0 && index < temps.size()) {
      temps.erase(temps.begin() + index);
    } else {
      std::cerr << "Invalid index" << std::endl;
    }
  }

  void Print() {
    for (const Temperature &temperature : temps) {
      std::cout << temperature.min << " " << temperature.max << " "
                << temperature.average << " " << temperature.monthNum << " "
                << temperature.year << std::endl;
    }
    std::cout
        << "<============================================================>"
        << std::endl;
  }

  void Search(int month, int year) {
    bool found = false;
    for (const Temperature &temperature : temps) {
      if (temperature.monthNum == month && temperature.year == year) {
        std::cout << temperature.min << " " << temperature.max << " "
                  << temperature.average << " " << temperature.monthNum << " "
                  << temperature.year << std::endl;
        found = true;
      }
    }
    if (!found) {
      std::cout << "No records found for month " << month << " and year "
                << year << std::endl;
    }
  }

private:
  std::vector<Temperature> temps;
  std::string connectionString;
};

void PrintMenu() {
  std::cout << "1. Load data from file" << std::endl;
  std::cout << "2. Save data to file" << std::endl;
  std::cout << "3. Add record" << std::endl;
  std::cout << "4. Edit record" << std::endl;
  std::cout << "5. Delete record" << std::endl;
  std::cout << "6. Search record" << std::endl;
  std::cout << "7. Print all records" << std::endl;
  std::cout << "8. Exit" << std::endl;
}

int GetValidInput(const std::string &prompt) {
  int value;
  while (true) {
    std::cout << prompt;
    std::cin >> value;
    if (std::cin.fail()) {
      std::cin.clear(); // clear the error flag
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                      '\n'); // discard invalid input
      std::cerr << "Invalid input, please enter a valid number." << std::endl;
    } else {
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                      '\n'); // discard any remaining input
      return value;
    }
  }
}

int main() {
  Db db("Temps.txt");
  int choice;

  while (true) {
    PrintMenu();
    choice = GetValidInput("Enter your choice: ");

    if (choice == 8) {
      break;
    }

    switch (choice) {
    case 1:
      db.Load();
      std::cout << "Data loaded from file." << std::endl;
      break;

    case 2:
      db.Save();
      std::cout << "Data saved to file." << std::endl;
      break;

    case 3: {
      int min = GetValidInput("Enter min: ");
      int max = GetValidInput("Enter max: ");
      int average = GetValidInput("Enter average: ");
      int month = GetValidInput("Enter month: ");
      int year = GetValidInput("Enter year: ");
      db.Add(Temperature{min, max, average, month, year});
      std::cout << "Record added." << std::endl;
      break;
    }

    case 4: {
      int index = GetValidInput("Enter record index to edit: ");
      int min = GetValidInput("Enter new min: ");
      int max = GetValidInput("Enter new max: ");
      int average = GetValidInput("Enter new average: ");
      int month = GetValidInput("Enter new month: ");
      int year = GetValidInput("Enter new year: ");
      db.Edit(index, Temperature{min, max, average, month, year});
      std::cout << "Record edited." << std::endl;
      break;
    }

    case 5: {
      int index = GetValidInput("Enter record index to delete: ");
      db.Delete(index);
      std::cout << "Record deleted." << std::endl;
      break;
    }

    case 6: {
      int month = GetValidInput("Enter month to search: ");
      int year = GetValidInput("Enter year to search: ");
      db.Search(month, year);
      break;
    }

    case 7:
      db.Print();
      break;

    default:
      std::cerr << "Invalid choice" << std::endl;
    }
  }

  std::cout << "Goodbye!" << std::endl;
  return 0;
}
