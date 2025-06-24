![image](https://github.com/user-attachments/assets/bfa4060a-71f8-4392-9d81-0a0356bfc36d)

# 🕹️ So\_long

`so_long` is a 2D graphical game project from the 42 curriculum designed to introduce students to graphics programming using the MiniLibX library. The project involves rendering a map, handling keyboard input, managing sprites, and ensuring game logic.

## 📚 Table of Contents

- [Overview](#-overview)
- [Features](#-features)
- [Installation](#-installation)
- [Usage](#-usage)
- [File Structure](#-file-structure)
- [Subject Breakdown](#-subject-breakdown)
- [License](#-license)
- [Subject PDF](#-subject-pdf)

## 📖 Overview

In this project, you create a basic 2D game where a player must navigate a map, collect all items, and exit safely. The map is built from a `.ber` file and rendered using MiniLibX. The game includes wall collisions, item collection, and win conditions.

## ✨ Features

- ✅ Load and validate maps from `.ber` files
- ✅ Render walls, floor, collectibles, player, and exit using images
- ✅ Track number of movements and display them
- ✅ Handle keyboard input (WASD or arrow keys)
- ✅ Display win/exit screen when conditions are met
- ✅ Protect against invalid maps (wrong chars, unclosed walls, unreachable exits, etc.)
- ✅ BONUS: Animated enemies that patrol or chase the player
- ✅ BONUS: Player loses the game when colliding with an enemy
- ✅ BONUS: Added sprite animations and frame updates

## ⚙️ Installation

```bash
git clone https://github.com/adil-ech/so_long
cd so_long
make
```

Ensure you have MiniLibX installed and linked properly.

## 🚀 Usage

```bash
./so_long maps/map.ber
```

Use arrow keys or `WASD` to move. Your goal is to collect all items and reach the exit.

## 📁 File Structure

```
so_long/
├── src/
│   ├── main.c
│   ├── game_loop.c
│   ├── render.c
│   ├── map_parser.c
│   ├── validation.c
│   ├── controls.c
│   ├── enemy.c            # Bonus
│   ├── animation.c        # Bonus
├── include/
│   └── so_long.h
├── maps/
│   └── example.ber
├── img/                   # Contains XPM sprites
├── Makefile
```

## 📄 Subject Breakdown

### ✅ Mandatory Part

- Map parsing and validation
- Game rendering with MiniLibX
- Movement tracking and item collection
- Exit activation logic
- Input handling and memory management

### 🎉 Bonus Part

- Implemented enemy behavior and collision detection
- Basic AI for patrolling or randomly moving enemies
- Player loses if touched by an enemy
- Animation system for smooth visual effects
- Enhanced visuals through sprite cycling

## 📬 License

This project is part of the 42 Network curriculum and should be used as an academic and learning resource.

## 📄 Subject PDF

You can read the official 42 So\_long subject here:\
👉 [So\_long Subject PDF](./en.subject.pdf)

