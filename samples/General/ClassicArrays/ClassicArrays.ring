# Ring Language - Classic Arrays Implementation
# Demonstrating traditional array operations for numerical calculations
# Author: Bert Mariani, Claude AI
# Date..: 2025-09-11

# =====================================================================
# Demonstration Program - RUNS FIRST
# =====================================================================

see "Classic Arrays in Ring Language" + nl
see "================================" + nl + nl

#------------------------------
# Create 1D arrays
see "1D Array Operations:" + nl
see "--------------------" + nl

arr1 = new ClassicArray {
    init(5, 0)
}

#------------------------------
# Fill with values
for i = 1 to 5
    arr1.setElement(i, i * 2)
next

see "Array 1: "
arr1.print()

arr2 = new ClassicArray {
    init(5, 0)
}

#------------------------------
# Fill with different values
for i = 1 to 5
    arr2.setElement(i, i + 10)
next

see "Array 2: "
arr2.print()

#------------------------------
# Perform operations
#------------------------------
arr_sum = arrayAdd(arr1, arr2)
see "Addition: "
arr_sum.print()

#------------------------------
arr_diff = arraySubtract(arr1, arr2)
see "Subtraction: "
arr_diff.print()

#------------------------------
arr_scaled = arrayScalarMultiply(arr1, 3)
see "Scalar multiply by 3: "
arr_scaled.print()

#------------------------------
dot_product = arrayDotProduct(arr1, arr2)
see "Dot product: " + dot_product + nl

#------------------------------
see "Array 1 sum: "  + arraySum(arr1) + nl
see "Array 1 mean: " + arrayMean(arr1) + nl
see "Array 1 min: "  + arrayMin(arr1) + nl
see "Array 1 max: "  + arrayMax(arr1) + nl
see "Array 1 std dev: " + arrayStandardDeviation(arr1) + nl + nl

#------------------------------
# 2D Array (Matrix) Operations
see "2D Array (Matrix) Operations:" + nl
see "-----------------------------" + nl

matrix1 = new ClassicArray {
    init([3, 3], 0)
}

#------------------------------
# Fill matrix1 with values
counter = 1
for r = 1 to 3
    for c = 1 to 3
        matrix1.setElement([r, c], counter)
        counter = counter + 1
    next
next

see "Matrix 1:" + nl
matrix1.print()

matrix2 = new ClassicArray {
    init([3, 3], 0)
}

#------------------------------
# Fill matrix2 with values
for r = 1 to 3
    for c = 1 to 3
        matrix2.setElement([r, c], r + c)
    next
next

see "Matrix 2:" + nl
matrix2.print()

#------------------------------
# Matrix multiplication
result_matrix = matrixMultiply(matrix1, matrix2)
see "Matrix multiplication result:" + nl
result_matrix.print()

#------------------------------
# Statistical analysis example
see "Statistical Analysis Example:" + nl
see "-----------------------------" + nl

#------------------------------
# Create sample data arrays
x_data = new ClassicArray {
    init(10, 0)
}

y_data = new ClassicArray {
    init(10, 0)
}

#------------------------------
# Generate sample data (linear relationship with noise)
for i = 1 to 10
    x_val = i
    y_val = 2 * x_val + 5 + (random(10) - 5)  # y = 2x + 5 + noise
    x_data.setElement(i, x_val)
    y_data.setElement(i, y_val)
next

see "X data: "
x_data.print()
see "Y data: "
y_data.print()

#------------------------------
# Perform linear regression
regression = arrayLinearRegression(x_data, y_data)
see "Linear regression:" + nl
see "  Slope: " + regression[1] + nl
see "  Intercept: " + regression[2] + nl
see "  Equation: y = " + regression[1] + "x + " + regression[2] + nl + nl

#------------------------------
# Performance comparison
see "Performance Comparison:" + nl
see "-----------------------" + nl

#------------------------------
# Create large arrays for performance testing
large_size = 1000
large_arr1 = new ClassicArray {
    init(large_size, 0)
}

large_arr2 = new ClassicArray {
    init(large_size, 0)
}

#------------------------------
# Fill with random values
for i = 1 to large_size
    large_arr1.setElement(i, random(100))
    large_arr2.setElement(i, random(100))
next

see "Created arrays of size " + large_size + nl

#------------------------------
# Time array addition
start_time = clock()
result_large = arrayAdd(large_arr1, large_arr2)
end_time = clock()

see "Array addition time: " + (end_time - start_time) + " clock ticks" + nl

#------------------------------
# Time dot product
start_time = clock()
dot_result = arrayDotProduct(large_arr1, large_arr2)
end_time = clock()

see "Dot product time: " + (end_time - start_time) + " clock ticks" + nl
see "Dot product result: " + dot_result + nl + nl

#------------------------------
see "Classic array operations completed!" + nl


#============================================================ 
#============================================================ 
#============================================================ 
#---
#--- FUNCTIONS
#---
# =================================================================
# Array Mathematical Operations - FUNCTIONS DEFINED AFTER MAIN CODE
# =================================================================

#============================================================ 
# Add two arrays element-wise - WORKING VERSION

func arrayAdd(arr1, arr2)
    if arr1.getSize() != arr2.getSize()
        raise("Array size mismatch for addition")
    ok
    
    # Get dimensions from first array
    dims = arr1.getDimensions()
    
    # Create result array using the SAME syntax as main program
    result = NULL
    if len(dims) = 1
        result = new ClassicArray {
            init(dims[1], 0)
        }
    else
        result = new ClassicArray {
            init(dims, 0)
        }
    ok
     
    for i = 1 to arr1.getSize()
        result.data[i] = arr1.data[i] + arr2.data[i]
    next
    
    return result

#============================================================
# Subtract two arrays element-wise - WORKING VERSION 

func arraySubtract(arr1, arr2)
    if arr1.getSize() != arr2.getSize()
        raise("Array size mismatch for subtraction")
    ok
    
    # Get dimensions from first array
    dims = arr1.getDimensions()
    
    # Create result array using the SAME syntax as main program
    result = NULL
    if len(dims) = 1
        result = new ClassicArray {
            init(dims[1], 0)
        }
    else
        result = new ClassicArray {
            init(dims, 0)
        }
    ok
    
    for i = 1 to arr1.getSize()
        result.data[i] = arr1.data[i] - arr2.data[i]
    next
    
    return result

#============================================================
# Multiply array by scalar - WORKING VERSION

func arrayScalarMultiply(arr, scalar)
    # Get the array info
    arr_size = arr.getSize()
    dims = arr.getDimensions()
    
    # Create new array using the SAME syntax as main program
    result = NULL
    if len(dims) = 1
        result = new ClassicArray {
            init(dims[1], 0)
        }
    else
        result = new ClassicArray {
            init(dims, 0)
        }
    ok
    
    # Copy and scale the data
    for i = 1 to arr_size
        result.data[i] = arr.data[i] * scalar
    next
    
    return result

#============================================================
# Element-wise array multiplication - WORKING VERSION

func arrayMultiply(arr1, arr2)
    if arr1.getSize() != arr2.getSize()
        raise("Array size mismatch for multiplication")
    ok
    
    # Get dimensions from first array
    dims = arr1.getDimensions()
    
    # Create result array using the SAME syntax as main program
    result = NULL
    if len(dims) = 1
        result = new ClassicArray {
            init(dims[1], 0)
        }
    else
        result = new ClassicArray {
            init(dims, 0)
        }
    ok
    
    for i = 1 to arr1.getSize()
        result.data[i] = arr1.data[i] * arr2.data[i]
    next
    
    return result

#============================================================
# Calculate array dot product (1D arrays only)

func arrayDotProduct(arr1, arr2)
    if len(arr1.getDimensions()) != 1 or len(arr2.getDimensions()) != 1
        raise("Dot product requires 1D arrays")
    ok
    
    if arr1.getSize() != arr2.getSize()
        raise("Array size mismatch for dot product")
    ok
    
    result = 0
    for i = 1 to arr1.getSize()
        result = result + (arr1.data[i] * arr2.data[i])
    next
    
    return result

#============================================================
# Calculate array sum

func arraySum(arr)
    sum = 0
    for i = 1 to arr.getSize()
        sum = sum + arr.data[i]
    next
    return sum

#============================================================
# Calculate array mean

func arrayMean(arr)
    return arraySum(arr) / arr.getSize()

#============================================================
# Find array minimum

func arrayMin(arr)
    if arr.getSize() = 0
        return NULL
    ok
    
    min_val = arr.data[1]
    for i = 2 to arr.getSize()
        if arr.data[i] < min_val
            min_val = arr.data[i]
        ok
    next
    return min_val

#============================================================
# Find array maximum

func arrayMax(arr)
    if arr.getSize() = 0
        return NULL
    ok
    
    max_val = arr.data[1]
    for i = 2 to arr.getSize()
        if arr.data[i] > max_val
            max_val = arr.data[i]
        ok
    next
    return max_val

#============================================================
# Matrix multiplication (2D arrays)

func matrixMultiply(mat1, mat2)
    dims1 = mat1.getDimensions()
    dims2 = mat2.getDimensions()
    
    if len(dims1) != 2 or len(dims2) != 2
        raise("Matrix multiplication requires 2D arrays")
    ok
    
    if dims1[2] != dims2[1]
        raise("Matrix dimension mismatch: " + dims1[2] + " != " + dims2[1])
    ok
    
    rows = dims1[1]
    cols = dims2[2]
    inner = dims1[2]
    
    result = new ClassicArray {
        init([rows, cols], 0)
    }
    
    for r = 1 to rows
        for c = 1 to cols
            sum = 0
            for k = 1 to inner
                val1 = mat1.getElement([r, k])
                val2 = mat2.getElement([k, c])
                sum = sum + (val1 * val2)
            next
            result.setElement([r, c], sum)
        next
    next
    
    return result

# =============================================================================
# Statistical Functions
# =============================================================================

#============================================================
# Calculate standard deviation

func arrayStandardDeviation(arr)
    mean = arrayMean(arr)
    variance_sum = 0
    
    for i = 1 to arr.getSize()
        diff = arr.data[i] - mean
        variance_sum = variance_sum + (diff * diff)
    next
    
    variance = variance_sum / arr.getSize()
    return sqrt(variance)

#============================================================
# Linear regression on two arrays

func arrayLinearRegression(x_arr, y_arr)
    if x_arr.getSize() != y_arr.getSize()
        raise("Arrays must be same size for regression")
    ok
    
    n = x_arr.getSize()
    sum_x = arraySum(x_arr)
    sum_y = arraySum(y_arr)
    sum_xy = arrayDotProduct(x_arr, y_arr)
    
    # Calculate sum of x squared
    sum_x_squared = 0
    for i = 1 to n
        sum_x_squared = sum_x_squared + (x_arr.data[i] * x_arr.data[i])
    next
    
    # Calculate slope and intercept
    slope = (n * sum_xy - sum_x * sum_y) / (n * sum_x_squared - sum_x * sum_x)
    intercept = (sum_y - slope * sum_x) / n
    
    return [slope, intercept]


#============================================================ 
#============================================================ 
#============================================================ 
#---
#--- CLASS
#---
# =============================================================================
# Class for Classic Fixed-Size Arrays - CLEAN WORKING VERSION
# =============================================================================

Class ClassicArray
    data size dimensions   ### <<<<< Attributes

    #============================================================    
    # Initialize Array with Fixed Size and Optional Initial Value
	# Ex. arr1 = new ClassicArray { init(5, 0) }		  
              
    func init(array_size, initial_value)
        if isnumber(array_size)
            #--- 1D Array
            size = array_size
            dimensions = [array_size]
            data = list(array_size)
            
            #--- Initialize with default value
            init_val = 0
            if initial_value != NULL
                init_val = initial_value
            ok
            
            for i = 1 to array_size
                data[i] = init_val
            next
            
        elseif islist(array_size)
            #--- Multi-Dimensional Array
            if len(array_size) >= 2
                dimensions = array_size
                size = 1
                for dim in dimensions
                    size = size * dim
                next
                data = list(size)
                
                # Initialize with default value
                init_val = 0
                if initial_value != NULL
                    init_val = initial_value
                ok
                
                for i = 1 to size
                    data[i] = init_val
                next
            elseif len(array_size) = 1
                #--- Handle [5] case as 1D
                actual_size = array_size[1]
                size        = actual_size
                dimensions  = array_size
                data        = list(actual_size)
                
                init_val = 0
                if initial_value != NULL
                    init_val = initial_value
                ok
                
                for i = 1 to actual_size
                    data[i] = init_val
                next
            ok
        ok
    return
    
    #============================================================     
    # Get element at index (1-based indexing)
	# Ex. val1 = mat1.getElement([r, k])
    
    func getElement(index)
        if isnumber(index)
            if index >= 1 and index <= size
                return data[index]
            else
                raise("Array index out of bounds: " + index)
            ok
        elseif islist(index)
            # Multi-dimensional indexing
            flat_index = calculateFlatIndex(index)
            return data[flat_index]
        ok
    return      

    #============================================================     
    # Set element at index
	# Ex. arr1.setElement(i, i * 2)
    
    func setElement(index, value)
        if isnumber(index)
            if index >= 1 and index <= size
                data[index] = value
            else
                raise("Array index out of bounds: " + index)
            ok
        elseif islist(index)
            # Multi-dimensional indexing
            flat_index = calculateFlatIndex(index)
            data[flat_index] = value
        ok
    return  

    #============================================================     
    # Calculate flat index for multi-dimensional arrays
    
    func calculateFlatIndex(indices)
        if len(indices) != len(dimensions)
            raise("Dimension mismatch")
        ok
        
        flat_index = 1
        multiplier = 1
        
        for i = len(dimensions) to 1 step -1
            flat_index = flat_index + (indices[i] - 1) * multiplier
            multiplier = multiplier * dimensions[i]
        next
        
    return flat_index

    #============================================================     
    # Get array size
	# Ex. arr1.getSize()
    
    func getSize()
        return size
    
    #============================================================ 
    # Get dimensions
	# Ex. arr1.getDimensions()
    
    func getDimensions()
        return dimensions

    #============================================================     
    # Fill array with value
    
    func fill(value)
        for i = 1 to size
            data[i] = value
        next
    return

    #============================================================     
    # Copy array - REMOVED (NOT NEEDED)
    # Instead use the array operations functions which work correctly

    #============================================================     
    # Print array contents
    # Ex. arr1.print()
	
    func print()
        if len(dimensions) = 1
            # 1D array
            see "["
            for i = 1 to size
                see data[i]
                if i < size
                    see ", "
                ok
            next
            see "]" + nl
        elseif len(dimensions) = 2
            # 2D array
            rows = dimensions[1]
            cols = dimensions[2]
            for r = 1 to rows
                see "["
                for c = 1 to cols
                    index = (r - 1) * cols + c
                    see data[index]
                    if c < cols
                        see ", "
                    ok
                next
                see "]" + nl
            next
        else
            # Higher dimensions - print as flat array
            see "Flat array: "
            for i = 1 to size
                see data[i]
                if i < size
                    see ", "
                ok
            next
            see nl
        ok
    return
	
###===========================================
###===========================================
###===========================================

/*
OUTPUT

Classic Arrays in Ring Language
================================
1D Array Operations:
--------------------
Array 1: [2, 4, 6, 8, 10]
Array 2: [11, 12, 13, 14, 15]
Addition: [13, 16, 19, 22, 25]
Subtraction: [-9, -8, -7, -6, -5]
Scalar multiply by 3: [6, 12, 18, 24, 30]
Dot product: 410
Array 1 sum: 30
Array 1 mean: 6
Array 1 min: 2
Array 1 max: 10
Array 1 std dev: 2.83
2D Array (Matrix) Operations:
-----------------------------
Matrix 1:
[1, 2, 3]
[4, 5, 6]
[7, 8, 9]
Matrix 2:
[2, 3, 4]
[3, 4, 5]
[4, 5, 6]
Matrix multiplication result:
[20, 26, 32]
[47, 62, 77]
[74, 98, 122]
Statistical Analysis Example:
-----------------------------
X data: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
Y data: [2, 9, 12, 17, 10, 19, 14, 20, 19, 30]
Linear regression:
  Slope: 2.19
  Intercept: 3.13
  Equation: y = 2.19x + 3.13
Performance Comparison:
-----------------------
Created arrays of size 1000
Array addition time: 3 clock ticks
Dot product time: 2 clock ticks
Dot product result: 2564197

Classic array operations completed!

###=======================================================
## FUNCTIONS and CLASS Used

Selected file: C:\MyStuff\AA-ARRAY-RING-Claude\Array-Ring-Classic.ring

F: 211: func arrayAdd(arr1, arr2)
F: 240: func arraySubtract(arr1, arr2)
F: 269: func arrayScalarMultiply(arr, scalar)
F: 296: func arrayMultiply(arr1, arr2)
F: 325: func arrayDotProduct(arr1, arr2)
F: 344: func arraySum(arr)
F: 354: func arrayMean(arr)
F: 360: func arrayMin(arr)
F: 376: func arrayMax(arr)
F: 392: func matrixMultiply(mat1, mat2)
F: 433: func arrayStandardDeviation(arr)
F: 448: func arrayLinearRegression(x_arr, y_arr)

C: 481: Class ClassicArray

F: 488: func init(array_size, initial_value)
F: 547: func getElement(index)
F: 565: func setElement(index, value)
F: 582: func calculateFlatIndex(indices)
F: 601: func getSize()
F: 608: func getDimensions()
F: 614: func fill(value)
F: 628: func print()

<<<==========>>>
*/
	
