# UsingClaude — Ring Language Samples

This folder contains applications and games developed in the **Ring programming language** using the **RingRayLib** library. All projects were generated with the assistance of **Claude Code**.

---

## Table of Contents

- [Games](#games)
  - [Classic Arcade](#classic-arcade)
  - [Board Games](#board-games)
  - [Puzzle Games](#puzzle-games)
  - [Action & Adventure](#action--adventure)
  - [Strategy & Simulation](#strategy--simulation)
- [Tools & Applications](#tools--applications)
- [Simulations & Visualizations](#simulations--visualizations)

---

## Games

### Classic Arcade

#### `pacman2d.ring` — Pac-Man 2D
Classic Pac-Man in a faithful 2D recreation. Navigate the maze, eat all pellets, avoid the four ghosts, and grab power pellets to turn the tables. Features the authentic 28×31 maze layout, ghost AI with chase/scatter/frightened modes, and multiple lives.

#### `pacman3d.ring` — Pac-Man 3D
The same beloved Pac-Man experience elevated into full 3D. Multiple camera views let you watch the action from different angles. Includes all classic gameplay elements: pellets, power pellets, ghosts, and bonus fruit.

#### `asteroids2d.ring` — Asteroids 2D
A faithful remake of the classic vector-graphics space shooter. Pilot your ship, destroy asteroids that split into smaller fragments, and handle UFO attacks. Press **N** for a new game.

#### `flappybird.ring` — Flappy Bird
Tap to flap through endless pipe gaps. Features three difficulty levels (Easy/Normal/Hard), day/night mode toggle, and progressively increasing challenge as you survive longer.

#### `spaceinv.ring` — Space Invaders
"Ring Invaders" — a classic top-down space shooter where waves of alien enemies descend. Destroy all enemies before they reach the ground.

#### `donkeykong.ring` — Donkey Kong
"Ring Kong" — inspired by the legendary barrel-jumping arcade classic. Climb platforms, dodge rolling barrels thrown by Kong, and rescue the princess.

#### `mario.ring` — Mario (Platformer)
"Ring Mario" — a classic side-scrolling platformer. Run and jump through levels, stomp enemies, and reach the flag.

#### `megaman.ring` — Mega Man
A Mega Man–style action platformer with multiple stages, each with distinct visual themes and enemy types. Run, jump, and shoot your way through challenging levels.

#### `tanks.ring` — Tanks (2-Player Battle)
A two-player top-down tank battle game. Players navigate a maze of walls and fight to destroy each other's tanks with cannon shots.

---

### Board Games

#### `chess2d.ring` — Chess 2D
A complete chess game against the computer. Fully implements chess rules including castling (kingside and queenside), en passant captures, pawn promotion, check detection, and checkmate. Undo moves with **U** and restart with **R**.

#### `chess3d.ring` — Chess 3D (Performance Optimized)
The same full chess experience rendered in beautiful 3D. Choose from three AI difficulty levels (Easy/Medium/Hard). Cycle between Front, Isometric, and Overhead camera views. Optimized with lightweight make/unmake for responsive AI search.

#### `checker3d.ring` — 3D Checkers (Draughts)
Classic draughts on a full 3D board. Select and move pieces diagonally, jump to capture opponents, and crown kings when reaching the far end. Supports Player vs Player and Player vs AI modes with valid-move hints.

#### `go3d.ring` — 3D Go (Weiqi / Baduk)
The ancient game of Go rendered in 3D with a wooden board aesthetic. Place black and white stones to surround territory and capture opponent groups. Includes territory estimation display and undo support.

#### `othello3d.ring` — 3D Othello (Reversi)
Classic Othello with smooth 3D disc-flip animations. Outflank and flip your opponent's pieces to dominate the board. Features valid-move highlighting, AI opponent, and polished visual effects.

#### `connectfour3d.ring` — 3D Connect Four
Drop discs into a 7-column, 6-row board and connect four in a row horizontally, vertically, or diagonally. Rendered in full 3D with smooth fall animations. Supports Player vs Player and Player vs AI modes.

#### `hexgame3d.ring` — 3D Hex Game
The classic connection strategy game on a diamond-shaped board. Two players compete to connect their opposite sides. Choose from five board sizes (5×5 up to 13×13) with a built-in AI opponent and multiple camera views.

---

### Puzzle Games

#### `sokoban2d.ring` — Sokoban 2D
The classic box-pushing puzzle in a clean 2D view. Push crates onto all target positions across multiple hand-crafted levels. Features an undo system and uses standard Sokoban notation for level design.

#### `sokoban3d.ring` — Sokoban 3D
The same Sokoban puzzles elevated to a full 3D warehouse setting with smooth push animations. Navigate multiple levels and use the undo system freely.

#### `ice3d.ring` — 3D Ice Sliding Puzzle
Slide across icy floors where you cannot stop until you hit a wall or rock. Navigate through maze-like levels to reach the goal. Includes a built-in BFS auto-solver (**H**) and an undo system.

#### `laser3d.ring` — 3D Laser Puzzle
Redirect a laser beam from emitter to target by placing and rotating mirrors on the grid. Features 3D beam tracing, placement animations, and multiple puzzle levels of increasing complexity.

#### `pipe3d.ring` — 3D Pipe Connect
Rotate pipe segments to connect a water flow from the source to the drain. Build a continuous path across the board. Rendered in 3D with animated water flow when the puzzle is solved.

#### `slide3d.ring` — 3D Sliding Puzzle (15-Puzzle)
The classic 15-tile sliding puzzle in stunning 3D. Slide numbered tiles into the correct order with an undo system and multiple board sizes.

#### `maze3d.ring` — 3D Maze
Navigate a glowing sphere through a procedurally generated 3D maze. Each restart generates a unique maze using the Recursive Backtracker algorithm. Features atmospheric lighting effects.

#### `hanoi3d.ring` — 3D Tower of Hanoi
The classic Tower of Hanoi puzzle in full 3D. Move discs between three pegs to transfer the entire stack. Adjustable disc count (3–10), an undo system, and an **Auto-Solve** mode that animates the optimal solution step by step.

#### `minesweeper3d.ring` — 3D Minesweeper
Classic Minesweeper in a 3D perspective. Reveal cells, flag mines, and clear the board without triggering any explosions. Multiple camera views and flagging via right-click or **F**.

#### `knight3d.ring` — 3D Knight's Tour
Complete a full knight's tour of the chessboard — visit every square exactly once using only L-shaped chess moves. Features Warnsdorff hint highlighting (**H**), an auto-solver (**S**), undo, and board sizes from 5×5 to 8×8.

#### `nqueens3d.ring` — 3D N-Queens Puzzle
Place N queens on an N×N chessboard so no two queens threaten each other. Features a threat heatmap overlay (**H**), an auto-solver, and adjustable board sizes (4–12).

#### `lights3d.ring` — 3D Lights Out
Toggle lights on a grid to turn them all off. Each press flips the pressed cell and its orthogonal neighbors. Includes a solution hint overlay (**S**) and an undo system.

#### `match3d.ring` — 3D Match-3 Gem Game
Swap adjacent gems to form rows or columns of 3 or more. Chain reactions cascade as gems fall to fill gaps. Features match-hint highlighting, undo for pre-cascade swaps, and multiple board sizes.

#### `rescue3d.ring` — 3D Rescue Rover
A rich 3D puzzle game: push boxes, collect keys, redirect lasers with ice blocks, fill water with crates, rescue your dog, and escape. Multiple levels with increasing complexity and a generous undo system.

#### `the2048game3d.ring` — 3D 2048
Slide numbered tiles on a 4×4 grid. When two identical tiles collide they merge into one. Reach the 2048 tile to win. Rendered in 3D with smooth tile-slide animations and multiple camera views.

---

### Action & Adventure

#### `doom3d.ring` — Ring Doom 3D
A retro first-person shooter in the style of Wolfenstein/DOOM. Navigate corridors, blast enemies with your pistol, open doors, and find the exit. Features a toggleable map overlay (**TAB**) and mouse-look.

#### `dungeoncrawler3d.ring` — 3D Dungeon Crawler
First-person 3D dungeon exploration. Find keys, unlock doors, fight enemies in melee, and reach the exit. Includes an inventory system (**TAB**), minimap (**M**), multiple pre-built levels, and health management.

#### `swordgame.ring` — The Sword Game
A 3D platformer with sword combat and dungeon traps. Features ledge-grabbing, climbing, crouching, careful-step mechanics, and sword draw/sheathe. A physics-driven action-adventure with atmospheric dungeon environments.

#### `helicopter3d.ring` — Helicopter Gunship 3D
Fly an attack helicopter over terrain in mission-based gameplay. Destroy ground targets, rescue hostages, and dodge anti-air fire. Features machine gun and rocket weapons, terrain-following flight physics, and multiple missions.

#### `runner3d.ring` — 3D Endless Runner
An endless lane-running game set in a 3D world. Dodge obstacles, collect coins and power-ups while speed increases over time. Jump, slide (duck), and switch lanes to survive as long as possible.

#### `platform2d.ring` — 2D Platformer
A classic side-scrolling platformer with precise jump physics. Navigate platforms, avoid hazards, and complete levels. Hold the jump button for higher jumps.

#### `baba3d.ring` — Baba Is You 3D
A puzzle game inspired by *Baba Is You*. Push word blocks around the level to rewrite the rules of the game itself. Changing which words are connected changes what objects do — a mind-bending logic puzzle experience.

---

### Strategy & Simulation

#### `bomberman.ring` — Ring Bomber (Bomberman-Style)
"Ring Bomber" — an arcade game where you place bombs to blast destructible walls, collect power-ups, and eliminate enemies. Features multiple enemy types and power-ups that enhance bomb count, range, and movement speed.

#### `breakout3d.ring` — 3D Breakout
The classic Breakout / Arkanoid brick-breaking game rendered in 3D. Control a paddle, launch the ball, and clear all bricks. Features sound effects (brick_break, level_clear, game_over) and increasing difficulty.

#### `pinball3d.ring` — 3D Pinball
A full pinball table in 3D. Launch the ball with the plunger, use left and right flippers, hit bumpers and targets for points. Features multiple camera views and a pause function.

#### `racing3d.ring` — 3D Racing
Race around a track against three AI opponents. Features acceleration, braking, reversing, handbrake turns, and multiple camera angles. Includes a lap counter and race restart.

#### `shooter3d.ring` — Space Shooter 3D
Fly your ship through asteroid fields and enemy waves in a 3D space shooter. Move in all four directions, shoot projectiles, and survive increasingly intense waves.

#### `towerdefense2d.ring` — Tower Defense 2D
Place turrets along enemy paths to prevent waves of enemies from breaking through. Features six turret types, upgrade and sell mechanics (50% refund), fast-forward mode, and a grid overlay.

#### `towerdefense3d.ring` — 3D Tower Defense
The same tower defense strategy elevated into 3D. Enemies follow a winding path across a grid while you build and upgrade towers to stop them. Four tower types with upgrade paths and wave bonuses for sending enemies early.

---

## Tools & Applications

#### `analogclock.ring` — Analog Clock
A smooth animated analog clock rendered with RayLib. Displays hours, minutes, and seconds hands with real-time updates.

#### `paint.ring` — Paint Program
A 2D drawing application with multiple tools: freehand brush, line, rectangle, circle/oval, and fill-rectangle. Supports a color palette and right-click erasing.

#### `diagram.ring` — Diagram / Flowchart Tool
A flowchart and diagram maker. Create draggable boxes in five shapes, connect them with arrows, edit label text inline, and auto-arrange with grid snap. Export-ready for quick visual documentation.

#### `circuit.ring` — Logic Circuit Simulator
A visual logic gate simulator. Place AND, OR, NOT, XOR, NAND, NOR, and other gates on a canvas, wire outputs to inputs, and toggle input switches to watch signals propagate in real time. Features auto-layout, undo, and grid snap.

#### `sortvis.ring` — Sorting Algorithm Visualizer
Watch six classic sorting algorithms animate on colorful bars: Bubble Sort, Selection Sort, Insertion Sort, Quick Sort, Merge Sort, and Shell Sort. Adjust speed and array size to compare performance visually.

---

## Simulations & Visualizations

#### `solarsystem.ring` — 3D Solar System
An interactive 3D solar system with all eight planets orbiting the Sun. Sizes, distances, and speeds are scaled for visual appeal. Switch between Free, Follow-Planet, Overhead, and Orbit camera modes. Toggle orbit lines, labels, and an info panel.

#### `ecosystemsimulator.ring` — Ecosystem Simulator
A predator/prey population simulation (foxes and rabbits) demonstrating Lotka-Volterra dynamics. Watch populations rise and fall, spawn extra animals, switch terrain/stats views, and choose from preset scenarios.

#### `trafficsimulator.ring` — Traffic Simulator
Cars drive on a road grid with traffic lights and intersections. Watch traffic flow emerge from signal timing, add cars, switch between 2×2 and 3×3 grid layouts, and adjust light cycle duration.

#### `weathersimulator.ring` — Weather Simulator
A living sky simulation with clouds, rain, lightning, wind, snow, and a day/night cycle. Switch between six weather presets, trigger lightning bolts manually, and watch atmospheric conditions evolve over a landscape.

#### `gameoflife2d.ring` — Conway's Game of Life 2D
The classic cellular automaton in a zoomable, pannable 2D grid. Toggle cells with mouse clicks, step generation by generation, load built-in pattern presets, and adjust simulation speed. Supports large grid sizes.

#### `gameoflife3d.ring` — Conway's Game of Life 3D
Conway's Game of Life visualized as glowing 3D cubes rising from a dark grid plane. Click cells to toggle them via ray-picking, cycle preset patterns, randomize the grid, and adjust simulation speed.

#### `particles.ring` — Particle System Playground
Interactive particle emitters with physics. Place attractors and repulsors with the mouse, switch between six emitter types (fireworks, fountain, vortex, etc.), cycle color themes, and toggle gravity and wind.

#### `screensaver.ring` — Color Animation Screensaver
Eight mesmerizing animated visual modes — flowing colors, bouncing shapes, Lissajous curves, and more. Cycle through color palettes, toggle background trails, and pause/resume the animation.

#### `forest3d.ring` — 3D Forest Explorer
A first-person walk through a procedurally generated 3D forest. Trees are randomly placed across terrain, creating an immersive outdoor environment to explore freely.

#### `cardsanimation2d.ring` — Cards Animation 2D
A 2D animated card-dealing and shuffling demonstration. Smooth card movement animations showcase RayLib's 2D rendering and easing capabilities.

#### `cardsanimation3d.ring` — Cards Animation 3D
The same card animation showcase in full 3D space, demonstrating 3D transformations, rotations, and smooth camera work with playing card assets.

---

