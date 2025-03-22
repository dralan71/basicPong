# Pong Game in C++

This is a terminal-based Pong game built in C++ for **macOS**.

## 📋 Description

The game is a classic Pong game where two players control paddles on either side of the screen, trying to bounce a ball back and forth. The game ends when one player scores a point by getting the ball past the opponent's paddle.

### 🕹️ Controls
- **Player 1**: 
  - `W` to move up.
  - `S` to move down.
- **Player 2**: 
  - `I` to move up.
  - `K` to move down.
- Press `X` to quit the game.

### ⚙️ How It Works
- The **ball** is controlled by physics and randomly changes direction upon hitting a wall or paddle.
- **Paddles** are controlled by the players using their respective keys. The paddle moves up and down, but is restricted to staying within the boundaries of the screen.
- The **score** is incremented when a player gets the ball past the opponent’s paddle. The game resets the ball and paddles to their starting positions after each score.
  
---

## ⚠️ Notes
- This code is designed to run on **macOS**, as it uses the `termios` API to handle keypress detection (which is compatible with macOS's terminal).
- If you're using **Linux**, this code should work similarly. Windows users may need to modify the `kbhit()` function for compatibility (such as using `conio.h` on Windows).
