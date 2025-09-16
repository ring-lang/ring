# C-Style Arrays Implementation in Ring Language
# Corrected to work with Ring's actual capabilities
# Using Ring's native list functions and avoiding conflicts
# Author: Bert Mariani, Claude AI
# Date..: 2025-09-16

Func main

see "C-Style Arrays in Ring Language (Corrected Version)" + nl
see "====================================================" + nl + nl

#===================================================
# Example 1: Basic array declaration and initialization

see "1. Basic Array Operations (C-style)" + nl
see "-----------------------------------" + nl

#--- Like: int arr[5] = {10, 20, 30, 40, 50};
arr = c_array_init([10, 20, 30, 40, 50])
see "Array initialized: "
arr.print_array()

#--- Array access like C: arr[2] = 35;
arr.set_value(2, 35)
see "After arr[2] = 35: "
arr.print_array()

see "arr[0] = " + arr.get_value(0) + nl
see "arr[4] = " + arr.get_value(4) + nl + nl

#===================================================
# Example 2: Dynamic memory allocation (Ring style)

see "2. Dynamic Memory Allocation" + nl
see "----------------------------" + nl

#--- Like: int *ptr = (int*)malloc(10 * sizeof(int));
ptr = ring_malloc(10)
see "Allocated array of size: " + ptr.get_size() + nl

#--- Like: int *ptr2 = (int*)calloc(5, sizeof(int));
ptr2 = ring_calloc(5)
see "Calloc array (Zeros): "
ptr2.print_array()

# Fill with values
for i = 0 to 4
    ptr.set_value(i, (i + 1) * 10)
next

see "Malloc array filled.: "
ptr.print_array()

#--- Memory operations
ring_memset(ptr2,  99, 3)  # Set first 3 elements to 99
see "After memset(ptr2,  99, 3): "
ptr2.print_array()

ring_memcpy(ptr2, ptr, 2)  # Copy first 2 elements
see "After memcpy(ptr2, ptr, 2): "
ptr2.print_array()

#--- Free memory
ring_free(ptr)
ring_free(ptr2)
see "Memory freed" + nl + nl

#===================================================
# Example 3: Array algorithms (C-style)
see "3. Array Algorithms (C-style)" + nl
see "-----------------------------" + nl

#--- Create test array
test_data = [64, 34, 25, 12, 22, 11, 90]
test_arr = c_array_init(test_data)
n = test_arr.get_size()

see "Original array...: "
test_arr.print_array()

#--- Bubble sort
bubble_sort_arr = c_array_init(test_data)
bubble_sort(bubble_sort_arr, n)
see "After bubble sort: "
bubble_sort_arr.print_array()

#--- Quick sort
quick_sort_arr = c_array_init(test_data)
quick_sort(quick_sort_arr, 0, n-1)
see "After quick sort.: "
quick_sort_arr.print_array()

#--- Binary search
target = 25
index = binary_search(quick_sort_arr, 0, n-1, target)
if index != -1
    see "Binary search: found " + target + " at index " + index + nl
else
    see "Binary search: " + target + " not found" + nl
ok

#--- Linear search
target = 90
index = array_search(test_arr, n, target)
if index != -1
    see "Linear search: found " + target + " at index " + index + nl
else
    see "Linear search: " + target + " not found" + nl
ok
see nl

#===================================================
# Example 4: 2D Arrays (C-style matrices)
see "4. 2D Arrays / Matrices (C-style)" + nl
see "---------------------------------" + nl

#--- Like: int matrix[3][3];
matrix = new CMatrix
matrix.init_matrix(3, 3)

#--- Initialize matrix
counter = 1
for i = 0 to 2
    for j = 0 to 2
        matrix.set_matrix(i, j, counter)
        counter = counter + 1
    next
next

see "3x3 Matrix:" + nl
matrix.print_matrix()

#--- Matrix operations example
see "Matrix element[1][1] = " + matrix.get_matrix(1, 1) + nl
matrix.set_matrix(1, 1, 99)
see "After   matrix[1][1] = 99:" + nl
matrix.print_matrix()

#===================================================
# Example 5: Pointer arithmetic simulation
see nl+"5. Pointer Arithmetic Simulation" + nl
see "--------------------------------" + nl

ptr_arr = c_array_init([100, 200, 300, 400, 500])
see "Original array........: "
ptr_arr.print_array()

#--- Simulate pointer arithmetic: *(ptr + 2) = 350
offset = 2
ptr_arr.set_value(0 + offset, 350)
see "After *(ptr + 2) = 350: "
ptr_arr.print_array()

#--- Array traversal using pointer-style loop
see "Traversal using pointer-style: "+nl
for i = 0 to ptr_arr.get_size()-1
    see "*(ptr + " + i + ") = " + ptr_arr.get_value(i) +nl
next
see nl + nl

#===================================================
# Example 6: String-like operations on integer arrays
see "6. Array Operations (string-like)" + nl
see "---------------------------------" + nl

src = c_array_init([1, 2, 3, 4, 5])  # "string" terminated with zeros
dest = ring_malloc(5)

see "Source array.................: "
src.print_array()

#--- Copy array (like strcpy)
array_copy(dest, src, 3)
see "After array_copy (3 elements): "
dest.print_array()

#--- Compare arrays
result = array_compare(src, dest, 3)
see "Array comparison result: " + result + " (0=equal, -1=less, 1=greater)" + nl

ring_free(dest)
see nl + "C-style array operations completed!" + nl

return

# =============================================================================
# RING MEMORY MANAGEMENT FUNCTIONS
# =============================================================================

#------------------------------------
func ring_malloc size
    ptr = new CArray
    ptr.init_array(size)
    ptr.clear_memory()
    return ptr

#------------------------------------
func ring_calloc count
    ptr = new CArray
    ptr.init_array(count)
    ptr.clear_memory()  # Already zeros in init_array
    return ptr

#------------------------------------
func ring_free ptr
    if ptr != null
        ptr.deallocate()
    ok

#------------------------------------
func ring_memset ptr,value,count
    for i = 0 to count-1
        ptr.set_value(i, value)
    next

#------------------------------------
func ring_memcpy dest,src,count
    for i = 0 to count-1
        dest.set_value(i, src.get_value(i))
    next

# =============================================================================
# STANDALONE FUNCTIONS (C-Style Memory and Array Functions)
# =============================================================================

#------------------------------------
func c_array_init values
    arr_size = len(values)
    arr = ring_malloc(arr_size)
    for i = 1 to arr_size
        arr.set_value(i-1, values[i])  # Convert Ring's 1-based to our 0-based
    next
    return arr

#------------------------------------
func array_copy dest,src,count
    for i = 0 to count-1
        dest.set_value(i, src.get_value(i))
    next

#------------------------------------
func array_compare arr1,arr2,count
    for i = 0 to count-1
        if arr1.get_value(i) < arr2.get_value(i)
            return -1
        but arr1.get_value(i) > arr2.get_value(i)
            return 1
        ok
    next
    return 0

#------------------------------------
func array_search arr,size,target
    for i = 0 to size-1
        if arr.get_value(i) = target
            return i  # Return index (C-style 0-based)
        ok
    next
    return -1  # Not found

#------------------------------------
#--- Sorting algorithms
func bubble_sort arr,n
    for i = 0 to n-2
        for j = 0 to n-2-i
            if arr.get_value(j) > arr.get_value(j+1)
                # Swap elements
                temp = arr.get_value(j)
                arr.set_value(j, arr.get_value(j+1))
                arr.set_value(j+1, temp)
            ok
        next
    next

#------------------------------------
func quick_sort arr,low,high
    if low < high
        pi = partition(arr, low, high)
        quick_sort(arr, low, pi-1)
        quick_sort(arr, pi+1, high)
    ok

#------------------------------------
func partition arr,low,high
    pivot = arr.get_value(high)
    i = low - 1
    
    for j = low to high-1
        if arr.get_value(j) <= pivot
            i = i + 1
            # Swap arr[i] and arr[j]
            temp = arr.get_value(i)
            arr.set_value(i, arr.get_value(j))
            arr.set_value(j, temp)
        ok
    next
    
    #--- Swap arr[i+1] and arr[high]
    temp = arr.get_value(i+1)
    arr.set_value(i+1, arr.get_value(high))
    arr.set_value(high, temp)
    
    return i + 1

#------------------------------------
func binary_search arr,left,right,target
    if right >= left
        mid = left + floor((right - left) / 2)
        
        if arr.get_value(mid) = target
            return mid
        ok
        
        if arr.get_value(mid) > target
            return binary_search(arr, left, mid-1, target)
        ok
        
        return binary_search(arr, mid+1, right, target)
    ok
    
    return -1
    
#------------------------------------
func min_val a,b
    if a < b
        return a
    else
        return b
    ok

# =============================================================================
# CLASS DEFINITIONS
# =============================================================================

# C-style array class with zero-based indexing simulation
Class CArray

    data size is_allocated   # Attributes

    #------------------------------------    
    func init_array array_size
        size = array_size
        is_allocated = true
        data = []  # Empty list first
        
        # Create list with proper size, initialized to 0
        for i = 1 to size
            add(data, 0)
        next

    #------------------------------------
    #--- Get value at index (0-based indexing simulation)
    func get_value index
        if index < 0 or index >= size
            see "Array index out of bounds: " + index + " (size: " + size + ")" + nl
            return 0
        ok
        return data[index + 1]  # Convert 0-based to Ring's 1-based indexing

    #------------------------------------
    #--- Set value at index (0-based indexing simulation)
    func set_value index,value
        if index < 0 or index >= size
            see "Array index out of bounds: " + index + " (size: " + size + ")" + nl
            return
        ok
        data[index + 1] = value  # Convert 0-based to Ring's 1-based indexing

    #------------------------------------
    #--- Get size
    func get_size
        return size
 
    #------------------------------------ 
    #--- Clear memory to zeros
    func clear_memory
        for i = 1 to size
            data[i] = 0
        next
 
    #------------------------------------ 
    #--- Deallocate memory
    func deallocate
        if is_allocated
            data = []
            size = 0
            is_allocated = false
        ok

    #------------------------------------    
    #--- Print array C-style
    func print_array
        see "{ "
        for i = 0 to size-1
            see "" + this.get_value(i)
            if i < size-1
                see ", "
            ok
        next
        see " }" + nl

#=================================================
#=================================================

#--- 2D Array class (C-style int arr[rows][cols])
Class CMatrix

    data rows cols is_allocated    # Attributes

    #------------------------------------    
    func init_matrix num_rows,num_cols
        rows = num_rows
        cols = num_cols
        is_allocated = true
        data = []
        
        #--- Create 2D array structure using Ring lists
        for i = 1 to rows
            row_data = []
            for j = 1 to cols
                add(row_data, 0)
            next
            add(data, row_data)
        next

    #------------------------------------
    #--- Get value at [row][col]
    func get_matrix row_index,col_index
        if row_index < 0 or row_index >= rows
            see "Row index out of bounds: " + row_index + nl
            return 0
        ok
        if col_index < 0 or col_index >= cols
            see "Column index out of bounds: " + col_index + nl
            return 0
        ok
        return data[row_index + 1][col_index + 1]  # Convert to Ring's 1-based
 
    #------------------------------------ 
    #--- Set value at [row][col]
    func set_matrix row_index,col_index,value
        if row_index < 0 or row_index >= rows
            see "Row index out of bounds: " + row_index + nl
            return
        ok
        if col_index < 0 or col_index >= cols
            see "Column index out of bounds: " + col_index + nl
            return
        ok
        data[row_index + 1][col_index + 1] = value  # Convert to Ring's 1-based

    #------------------------------------    
    #--- Deallocate matrix memory
    func deallocate
        if is_allocated
            data = []
            rows = 0
            cols = 0
            is_allocated = false
        ok
 
    #------------------------------------ 
    func print_matrix
        for i = 0 to rows-1
            for j = 0 to cols-1
                see "" + this.get_matrix(i, j) + " "
            next
            see nl
        next
        
        
# ==================================
/*

Basic array operations    - initialization, setting/getting values with C-style 0-based indexing
Dynamic memory allocation - malloc/calloc simulation
Memory operations         - memset, memcpy functions
Array algorithms          - bubble sort, quick sort, binary search, linear search
2D matrices               - C-style matrix operations
Pointer arith simulation  - offset-based access
Array utility functions   - copying, comparing arrays


Successfully bridges C-style array concepts with Ring's native capabilities, 
providing a familiar C-like interface 
while working within Ring's 1-based indexing and memory management system.  

*/  

/*
func ring_malloc   size
func ring_calloc   count
func ring_free     ptr
func ring_memset   ptr,value,count
func ring_memcpy   dest,src,count
func c_array_init  values
func array_copy    dest,src,count
func array_compare arr1,arr2,count
func array_search  arr,size,target
func bubble_sort   arr,n
func quick_sort    arr,low,high
func partition     arr,low,high
func binary_search arr,left,right,target
func min_val       a,b

Class CArray

func init_array array_size
func get_value  index
func set_value  index,value
func get_size
func clear_memory
func deallocate
func print_array

Class CMatrix

func init_matrix num_rows,num_cols
func get_matrix  row_index,col_index
func set_matrix  row_index,col_index,value
func deallocate
func print_matrix
*/
