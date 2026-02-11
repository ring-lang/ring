/*
**  cr_rooms.ring - Room Definitions
**  Code Rooms 3D - Programming Puzzles
*/

roomCount = 10

roomTitles  = list(roomCount)
roomCodes   = list(roomCount)
roomLabels  = list(roomCount)
roomSlotLbls = list(roomCount)
roomMaps    = list(roomCount)

// ------ Room 1: Hello World ------
roomTitles[1]   = "Print Hello World"
roomCodes[1]    = "print hello space world"
roomLabels[1]   = ["Print", "Hello", "(space)", "World"]
roomSlotLbls[1] = ["Print", "Hello", "(space)", "World"]
roomMaps[1]     = [
    "############",
    "#..........#",
    "#..A.......#",
    "#......B...#",
    "#..........#",
    "#...C......#",
    "#..........#",
    "#.D........#",
    "#..........#",
    "#.1234..Z..#",
    "#..........#",
    "#.....@....#",
    "############"
]

// ------ Room 2: Count 1 to 10 ------
roomTitles[2]   = "Count Numbers from One to Ten"
roomCodes[2]    = "for x = 1 to 10 print x"
roomLabels[2]   = ["for", "x", "=", "1", "to", "10", "print", "x"]
roomSlotLbls[2] = ["for", "x", "=", "1", "to", "10", "print", "x"]
roomMaps[2]     = [
    "################",
    "#..............#",
    "#..A.....B.....#",
    "#..............#",
    "#.....C....D...#",
    "#..............#",
    "#..E......F....#",
    "#..............#",
    "#........G..H..#",
    "#..............#",
    "#.12345678..Z..#",
    "#..............#",
    "#......@.......#",
    "################"
]

// ------ Room 3: Sum Two Numbers ------
roomTitles[3]   = "Calculate Sum of Three Plus Seven"
roomCodes[3]    = "sum = 3 + 7"
roomLabels[3]   = ["sum", "=", "3", "+", "7"]
roomSlotLbls[3] = ["sum", "=", "3", "+", "7"]
roomMaps[3]     = [
    "##############",
    "#............#",
    "#..A....B....#",
    "#............#",
    "#....C.......#",
    "#............#",
    "#.......D..E.#",
    "#............#",
    "#.12345...Z..#",
    "#............#",
    "#....@.......#",
    "##############"
]

// ------ Room 4: If-Else ------
roomTitles[4]   = "Check if X is Greater than Five"
roomCodes[4]    = "if x > 5 see good ok"
roomLabels[4]   = ["if", "x", ">", "5", "see", "good", "ok"]
roomSlotLbls[4] = ["if", "x", ">", "5", "see", "good", "ok"]
roomMaps[4]     = [
    "################",
    "#..............#",
    "#..A.......B...#",
    "#..............#",
    "#.....C....D...#",
    "#..............#",
    "#..E......F....#",
    "#..............#",
    "#........G.....#",
    "#..............#",
    "#.1234567...Z..#",
    "#..............#",
    "#......@.......#",
    "################"
]

// ------ Room 5: While Loop ------
roomTitles[5]   = "Repeat While X is Greater than Zero"
roomCodes[5]    = "while x > 0 see x x-- end"
roomLabels[5]   = ["while", "x", ">", "0", "see", "x", "x--", "end"]
roomSlotLbls[5] = ["while", "x", ">", "0", "see", "x", "x--", "end"]
roomMaps[5]     = [
    "##################",
    "#................#",
    "#..A.........B...#",
    "#................#",
    "#.....C....D.....#",
    "#................#",
    "#..E.........F...#",
    "#................#",
    "#.....G....H.....#",
    "#................#",
    "#.12345678....Z..#",
    "#................#",
    "#.......@........#",
    "##################"
]

// ------ Room 6: Function Definition ------
roomTitles[6]   = "Define a Function Called Hello"
roomCodes[6]    = "func hello see hi"
roomLabels[6]   = ["func", "hello", "see", "Hi!"]
roomSlotLbls[6] = ["func", "hello", "see", "Hi!"]
roomMaps[6]     = [
    "############",
    "#..........#",
    "#..A...B...#",
    "#..........#",
    "#......C...#",
    "#..........#",
    "#..D.......#",
    "#..........#",
    "#.1234..Z..#",
    "#..........#",
    "#....@.....#",
    "############"
]

// ------ Room 7: List Creation ------
roomTitles[7]   = "Create a List of One, Two and Three"
roomCodes[7]    = "list = [ 1 , 2 , 3 ]"
roomLabels[7]   = ["list", "=", "[", "1", ",", "2", ",", "3", "]"]
roomSlotLbls[7] = ["list", "=", "[", "1", ",", "2", ",", "3", "]"]
roomMaps[7]     = [
    "####################",
    "#..................#",
    "#..A.........B.....#",
    "#..................#",
    "#.....C....D.......#",
    "#..................#",
    "#..E.........F.....#",
    "#..................#",
    "#.....G....H...I...#",
    "#..................#",
    "#.123456789.....Z..#",
    "#..................#",
    "#........@.........#",
    "####################"
]

// ------ Room 8: Class Definition ------
roomTitles[8]   = "Define a Class Called Point with X and Y"
roomCodes[8]    = "class point x y"
roomLabels[8]   = ["class", "point", "x", "y"]
roomSlotLbls[8] = ["class", "point", "x", "y"]
roomMaps[8]     = [
    "############",
    "#..........#",
    "#..A...B...#",
    "#..........#",
    "#..C.......#",
    "#..........#",
    "#.......D..#",
    "#..........#",
    "#.1234..Z..#",
    "#..........#",
    "#....@.....#",
    "############"
]

// ------ Room 9: Try-Catch ------
roomTitles[9]   = "Try Something and Catch the Error"
roomCodes[9]    = "try see x catch see err done"
roomLabels[9]   = ["try", "see", "x", "catch", "see", "err", "done"]
roomSlotLbls[9] = ["try", "see", "x", "catch", "see", "err", "done"]
roomMaps[9]     = [
    "################",
    "#..............#",
    "#..A.......B...#",
    "#..............#",
    "#.....C....D...#",
    "#..............#",
    "#..E......F....#",
    "#..............#",
    "#........G.....#",
    "#..............#",
    "#.1234567...Z..#",
    "#..............#",
    "#......@.......#",
    "################"
]

// ------ Room 10: Switch/On ------
roomTitles[10]   = "Switch on X and Handle Case One"
roomCodes[10]    = "switch x on 1 see one other see ? off"
roomLabels[10]   = ["switch", "x", "on", "1", "see", "one", "other", "see", "?", "off"]
roomSlotLbls[10] = ["switch", "x", "on", "1", "see", "one", "other", "see", "?", "off"]
roomMaps[10]     = [
    "######################",
    "#....................#",
    "#..A..........B......#",
    "#....................#",
    "#.....C.....D........#",
    "#....................#",
    "#..E..........F......#",
    "#....................#",
    "#.....G.....H........#",
    "#....................#",
    "#..I..........J......#",
    "#....................#",
    "#.1234567890......Z..#",
    "#....................#",
    "#..........@.........#",
    "######################"
]
