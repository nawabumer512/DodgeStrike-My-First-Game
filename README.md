# DodgeStrike-My-First-Game
# PF's Game 🎮
### CS1002 - Programming Fundamentals | NUCES Multan Campus

A 2D OpenGL arcade game built in C++ where you control a player character, dodge falling obstacles, collect coins, and survive against a computer-controlled villain.

---

## 📁 Repository & Folder Structure

**Repository name:** `DodgeStrike-My-First-Game`  
**Folder structure:**

```
DodgeStrike-My-First-Game
/
├── game-release.cpp      # Main game logic (player, obstacles, collision, timer)
├── util.cpp              # OpenGL drawing utility functions
├── util.h                # Header file — color definitions, function declarations
├── Makefile              # Build configuration
├── install-libraries.sh  # Script to install required dependencies
├── pf_file.txt           # Stores player name (auto-generated at runtime)
└── README.md             # This file
```

---

## 🎮 Gameplay

- **Move** your character using arrow keys (←→↑↓)
- **Dodge** falling obstacles — square and circle enemies
- **Collect** coins to increase your coin count
- **Survive** as long as possible — you have 3 lives
- **Beware** — after score 2000, a computer villain chases you!
- Score increases automatically as time passes, and obstacles speed up

### Controls

| Key        | Action         |
|------------|----------------|
| ← → ↑ ↓   | Move player    |
| P          | Pause game     |
| R          | Resume game    |
| Esc        | Quit game      |

---

## 🖥️ System Requirements

> ⚠️ This game uses OpenGL + GLUT and **only runs on Linux/Ubuntu**.  
> It is **not compatible with Windows** without major setup changes.

- Ubuntu 18.04 or later
- g++ compiler
- OpenGL / GLUT libraries
- FreeImage library

---

## ⚙️ How to Compile & Run (Ubuntu)

### Step 1 — Install Dependencies

Open a terminal and run:

```bash
chmod +x install-libraries.sh
./install-libraries.sh
```

Or manually install:

```bash
sudo apt-get install make freeglut3-dev glew-utils libglew-dev libfreeimage-dev
```

### Step 2 — Clone the Repository

```bash
git clone https://github.com/your-username/pfs-game.git
cd pfs-game
```

### Step 3 — Compile

```bash
make
```

This will compile `game-release.cpp` and `util.cpp` and produce the `game-release` executable.

To clean previous build files:

```bash
make clean
```

### Step 4 — Run

```bash
./game-release
```

You will be prompted to enter your name, then the game window will open.

---

## 🔧 Troubleshooting

**Error: cannot find -lfreeimage**
```bash
sudo apt-get install libfreeimage-dev
```

**Error: cannot find -lglut**
```bash
sudo apt-get install freeglut3-dev
```

**Display error / no window opens**  
Make sure you are running on a desktop environment (not SSH without X forwarding). If using SSH:
```bash
ssh -X username@hostname
```

---

## 📐 Project Structure Explained

| File | Purpose |
|------|---------|
| `game-release.cpp` | Core game — handles display, input, collision detection, scoring, timer |
| `util.cpp` | Drawing functions — circles, squares, triangles, lines, strings |
| `util.h` | Declarations, color enum (140+ named colors), constants like FPS |
| `Makefile` | Automates compilation with correct OpenGL flags |
| `install-libraries.sh` | One-command dependency installer for Ubuntu |
| `pf_file.txt` | Created at runtime — saves player name entered at start |

---

## ⚠️ Disclaimer

This project was developed as part of coursework at NUCES Multan for CS1002 – Programming Fundamentals. It is shared for reference and learning purposes only.

- Do **NOT** copy or submit any part of this code as your own academic work.
- The author holds no responsibility for any academic misconduct resulting from misuse.

Use it to learn, not to cheat.

---

## 👨‍💻 Muhammad Umar Farooq

Developed at **NUCES Multan Campus**  
Course: CS1002 – Programming Fundamentals | Fall 2025
