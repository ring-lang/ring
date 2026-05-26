/*
**  cr_utils.ring - Utility Functions
**  Code Rooms 3D
*/

func fabs n
    if n < 0 return -n ok
    return n

func isdigit s
    sLen = len(s)
    if sLen = 0 return 0 ok
    for i = 1 to sLen
        code = ascii(substr(s, i, 1))
        if code < 48 or code > 57 return 0 ok
    next
    return 1

func cr_tan angle
    c = cos(angle)
    if fabs(c) < 0.0001 return 9999.0 ok
    return sin(angle) / c
