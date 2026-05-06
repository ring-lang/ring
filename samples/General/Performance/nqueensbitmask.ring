# Fast N-Queens using Bitmask Backtracking

n     = 12
total = 0

start_t = clock()

solveNQueens(n)

end_t = clock()
total_t = end_t - start_t

see "Time (ms): " + total_t + nl
see "Time (sec): " + (total_t / ClocksPerSecond()) + nl


func solveNQueens(n)

        total = 0

        all = (1 << n) - 1     # bitmask with n bits set to 1

        # Start recursion
        backtrack(0, 0, 0, all)

        see "Total solutions: " + total + nl
        return total

# colMask  = columns already used
# diag1    = main diagonal conflicts
# diag2    = anti-diagonal conflicts
# all      = mask with n bits set (limit)

func backtrack(colMask, diag1, diag2, all)

        if colMask = all
                total++
                return
        ok

        # available positions = free columns AND no diagonal conflict
        free = all & ~(colMask | diag1 | diag2)

        while free > 0
                # pick lowest 1-bit
                bit = free & (-free)

                # remove this bit from free
                free = free - bit

                # recursive call with updated masks
                backtrack(
                        colMask | bit,
                        (diag1 | bit) << 1,
                        (diag2 | bit) >> 1,
                        all
                )
        end


