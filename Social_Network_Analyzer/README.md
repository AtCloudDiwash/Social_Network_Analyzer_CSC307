# Social Network Analyzer (CSC307)

**Authors:** Shaheer Saeed, Diwash Kuskusmiya, Haadi Ali, D'Khristyn Halton
**Course:** CSC307 – Data Structures & Algorithms
**Semester:** Spring/Fall 2026

---

## 1. Prerequisites & Environment

Before running this project, ensure your system meets the following requirements:

- **Operating System:** Windows 10/11 or macOS
- **Compiler:** GCC 7+, Clang++ 5+, or MSVC 2017+ (Apple Clang 17 confirmed working on macOS)
- **C++ Standard:** C++17
- **Build System:** `make` (macOS/Linux) or `g++` directly (Windows)

### Required Libraries

This project uses only standard C++ libraries:

- **Standard Library (`iostream`, `string`, etc.)** — Input/output and string handling
- **Custom Graph Module** — Implements social network structure and algorithms (`graph.cpp`, `graph.h`)
- **Command Handler Module** — Parses and executes user commands (`commands.cpp`, `commands.h`)
- **Storage Module** — Handles saving and loading network data (`storage.cpp`, `storage.h`)

---

## 2. Installation & Setup

1. Download or clone the repository
2. Open a terminal (macOS) or Command Prompt / PowerShell (Windows) in the project directory

---

## 3. Build Instructions

### macOS / Linux

Uses the provided `Makefile` (`g++ -std=c++17 -Wall -Wextra`):

```bash
make
./social_network
```

To clean the build:

```bash
make clean
```

### Windows

No `Makefile` is provided for Windows. You must have `g++` available via [MinGW-w64](https://www.mingw-w64.org/) or [MSYS2](https://www.msys2.org/).

**Option 1 — MinGW / MSYS2 (g++):**

```cmd
g++ -std=c++17 -Wall -Wextra -o social_network.exe main.cpp graph.cpp storage.cpp commands.cpp
.\social_network.exe
```

**Option 2 — Visual Studio (MSVC 2017+):**

1. Open Visual Studio and create a new **Empty C++ Project**
2. Add all `.cpp` files (`main.cpp`, `graph.cpp`, `storage.cpp`, `commands.cpp`)
3. Set the C++ language standard to **C++17** in Project Properties → C/C++ → Language
4. Build and run (`Ctrl+F5`)

**Option 3 — VS Code with MinGW:**

1. Install the [C/C++ extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
2. Open the project folder in VS Code
3. Run the g++ command above in the integrated terminal

---

## 4. Execution Guide

Once the program is built, use the following commands in the interactive CLI:

| Command | Description |
|---|---|
| `AddPerson <name>` | Add a person to the network |
| `AddFriendship <name1> <name2>` | Create a friendship between two people |
| `RemovePerson <name>` | Remove a person from the network |
| `RemoveFriendship <name1> <name2>` | Remove a friendship between two people |
| `UpdatePerson <oldname> <newname>` | Rename a person |
| `ShowFriends <name>` | List all friends of a person |
| `MutualFriends <name1> <name2>` | Show mutual friends between two people |
| `ShortestPath <name1> <name2>` | Find the shortest connection path between two people |
| `SaveNetwork <csv_file>` | Save the current network to a CSV file |
| `LoadNetwork <csv_file>` | Load a network from a CSV file |
| `exit` | Exit the program |

**Program capabilities:**

- Interactive command-line interface for managing a social network
- Add, remove, and rename users
- Create and remove friendships
- Find mutual friends between any two users
- Compute shortest paths between users
- Persist and restore network data via CSV

---

## 5. Demo

[Watch the demo video](demo.mp4)

---

## 6. Troubleshooting / Known Issues

- No known issues at this time
- If `g++` is not recognized on Windows, ensure MinGW-w64 is installed and its `bin` directory is added to your system `PATH`
- On macOS, `g++` maps to Apple Clang — this is expected and fully compatible

---
