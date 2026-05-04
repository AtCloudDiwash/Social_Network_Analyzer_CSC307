# Social Network Analyzer (CSC307)

**Author:** Shaheer Saeed, Diwash Kuskusmiya, Haadi Ali, D'Khristyn Halton.
**Course:** CSC307 – Data Structures & Algorithms
**Semester:** [Spring/Fall 2026]

---

## 1. Prerequisites & Environment

Before running this project, ensure your system meets the following requirements:

* **Operating System:** Windows 10/11, or macOS
* **Compiler:** Minimum versions, GCC 7, Clang++ 5, MSVC 2017 (later versions of these compilers will work) 
* **Build System:** g++ or any C++ IDE (Visual Studio/VS Code)

### Required Libraries

This project uses only standard C++ libraries:

* **Standard Library (`iostream`, `string`, etc.)**: Input/output and string handling
* **Custom Graph Module**: Implements social network structure and algorithms
* **Command Handler Module**: Parses and executes user commands

---

   2. Installation & Setup

1. Download the zip file
2. clone the zip file into the C++ terminal in V.S code 

  3. Build Instructions


### Using Windows 
   1.First:g++ -std=c++17 -Wall -Wextra -o social_network.exe main.cpp graph.cpp storage.cpp commands.cpp

   2.Second:.\social_network.exe 


### Using MAC
*In the terminal write make
*The program will automatically Create a file named social_network
*In the terminal write ./social_network
*It will start the CLI version of the program


---

## 4. Execution Guide
Once the program is properly built use the following commands to test all the features of this project 
  AddPerson <name>
  AddFriendship <name1> <name2>
  RemovePerson <name>
  RemoveFriendship <name1> <name2>
  UpdatePerson <oldname> <newname>
  ShowFriends <name>
  MutualFriends <name1> <name2>
  ShortestPath <name1> <name2>
  SaveNetwork <csv_file>
  LoadNetwork <csv_file>
  exit


Program Actions:

 Launches an interactive command-line interface for accessing social networks.
 Provides users a way to interact and manage a social network
 Executes operations such as:

    Adding/Removing users in the program
    Updating users 
    Creating/removing friendships
    Finding mutual friends
    Computing shortest paths
    Saving/loading network data


---

## 5. Troubleshooting / Known Issues

1. No Known errors at this time

---
