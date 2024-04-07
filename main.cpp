#include <iostream>
#include <string>
#include <unordered_map>

struct Task {
  int id;
  std::string name;
  bool completed;
};

class List {
private:
  std::unordered_map<int, Task> list;
  int counterForID;

public:
  List() : counterForID(0) {}

  void printList() {
    std::cout << "--------------------------" << '\n';
    if (list.size() == 0)
      std::cout << "There are no things todo...\n";
    for (auto it = list.begin(); it != list.end(); ++it) {
      Task t = it->second;
      std::cout << t.id << " " << (t.completed == true ? "(X)" : "( )") << " "
                << t.name << "\n";
    }
    std::cout << "--------------------------" << '\n';
  }

  void addTask(Task t) {
    counterForID++;
    t.id = counterForID;
    list[counterForID] = t;
  }

  void deleteTask(int id) {
    auto it = list.find(id);
    if (it != list.end())
      list.erase(id);
    else
      std::cout << "No such task exists!" << '\n';
  }

  void checkTask(int id) {
    auto it = list.find(id);
    if (it != list.end()) {
      list[id].completed = !list[id].completed;
    } else
      std::cout << "No such task exists!" << '\n';
  }
};

int main() {
  List list;
  int choice = 0;

  while (choice != 4) {
    list.printList();
    std::cout << "1. Add a task!" << '\n';
    std::cout << "2. Delete a task!" << '\n';
    std::cout << "3. Check a task!" << '\n';
    std::cout << "4. Exit! \n\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    if (choice == 4)
      break;

    switch (choice) {
    case 1: {
      std::cout << '\n';
      std::cout << "Enter your task: ";
      Task t;
      t.id = 0;
      std::cin.ignore();
      std::getline(std::cin, t.name);
      t.completed = false;
      std::cout << '\n';
      list.addTask(t);
      break;
    }
    case 2: {
      std::cout << '\n';
      std::cout << "Enter the id of the task you want to delete: ";
      int id;
      std::cin >> id;
      std::cout << '\n';
      list.deleteTask(id);
      break;
    }
    case 3: {
      std::cout << '\n';
      std::cout << "Enter the id of the task you want to check: ";
      int id;
      std::cin >> id;
      std::cout << '\n';
      list.checkTask(id);
      break;
    }
    default: {
      std::cout << "\nInvalid Input! \n\n";
      break;
    }
    }
  }

  return 0;
}
