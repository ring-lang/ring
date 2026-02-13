/*
**  ld_puzzledefs.ring
**  Puzzle definitions for Line Drawing 3D (15 puzzles)
**  Format: [gridW, gridH, startR, startC, exitR, exitC, dotsStr, brokenStr, consStr]
*/

// Level 1: Simple 3x3 path, no constraints
add(puzzleDefs, [3, 3, 3, 1, 1, 3, "", "", ""])
// Level 2: 3x3, one required dot
add(puzzleDefs, [3, 3, 3, 1, 1, 3, "2,2", "", ""])
// Level 3: 4x4, two required dots
add(puzzleDefs, [4, 4, 4, 1, 1, 4, "3,2;2,3", "", ""])
// Level 4: 3x3, broken edge
add(puzzleDefs, [3, 3, 3, 1, 1, 3, "", "H,2,1", ""])
// Level 5: 4x4, dots + broken edges
add(puzzleDefs, [4, 4, 4, 1, 1, 4, "3,2", "H,2,2;V,2,3", ""])
// Level 6: 3x3, black/white separation
add(puzzleDefs, [3, 3, 3, 1, 1, 3, "", "", "1,1,B;1,2,W"])
// Level 7: 4x4, color separation
add(puzzleDefs, [4, 4, 4, 1, 1, 4, "", "", "1,1,B;1,3,B;3,1,W;3,3,W"])
// Level 8: 4x4, dots + colors
add(puzzleDefs, [4, 4, 4, 1, 1, 4, "2,2", "", "1,1,B;1,3,W;3,1,W;3,3,B"])
// Level 9: 5x5, multi-dot
add(puzzleDefs, [5, 5, 5, 1, 1, 5, "4,2;3,3;2,4", "", ""])
// Level 10: 4x4, broken edges maze
add(puzzleDefs, [4, 4, 4, 1, 1, 4, "", "H,2,1;H,3,2;V,1,2;V,3,3", ""])
// Level 11: 5x5, colors + dots
add(puzzleDefs, [5, 5, 5, 1, 1, 5, "3,3", "", "1,1,B;1,4,W;4,1,W;4,4,B"])
// Level 12: 5x5, complex broken edges + dot
add(puzzleDefs, [5, 5, 5, 1, 1, 5, "4,2;2,4", "H,2,2;H,4,3;V,2,1;V,3,4", ""])
// Level 13: 5x5, full challenge (all types)
add(puzzleDefs, [5, 5, 5, 1, 1, 5, "3,3", "V,2,3;H,4,2", "1,1,B;1,4,W;4,1,W;4,4,B"])
// Level 14: 6x6, all constraint types
add(puzzleDefs, [6, 6, 6, 1, 1, 6, "4,3;3,4", "H,1,2;H,2,4;H,3,1;H,4,3;H,5,5;V,1,3;V,2,1;V,3,5;V,4,2;V,5,4", "1,1,B;1,5,B;5,1,W;5,5,W;3,3,B"])
// Level 15: 6x6, grand finale
add(puzzleDefs, [6, 6, 6, 1, 1, 6, "4,3;2,5", "H,1,1;H,2,3;H,3,5;H,4,2;H,5,4;V,1,4;V,2,2;V,3,3;V,4,5;V,5,1", "1,2,B;1,5,W;5,2,W;5,5,B"])
