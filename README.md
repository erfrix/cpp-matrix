# cpp-matrix
A Program that can inputs multiple matrixes and can check their properties or make changes on them.
[USAGE]

ADDING MATRIXES:
- ```add matrix {name} {rows} {columns}``` : asks you for each element individually
- ```add matrix {name} {rows} {columns} [a,b,c,d,....]``` : (elements in order) --> direct input to matrix from brackets
- ```add matrix {name} {number}``` : creates a matrix with equal rows and columns with size {number} then asks for each element
- ```add matrix {name} {number} [a,b,c,d,...]``` : creates a matrix with equal rows and columns with size {number} then inputs the elements in brackets

CHECK DIFFRENT PROPERTIES OF A MATRIX:\
- ```is_diagonal {name}``` : Check if diagonal\
- ```is_upper_triangular {name}``` : Checks if upper triangular\
- ```is_lower_triangular {name}``` : Checks if lower triangular\
- ```is_triangular {name}``` : Checks both triangularity and tells you\
- ```is_identity {name}``` : Checks identity\
- ```is_normal_symmetric {name}``` :  Checks normal symmetricity\
- ```is_skew_symmetric {name}``` : Checks skew symmetricity\
- ```is_symmetric {name}``` :  Checks both symmetricity and tells you\\

OPERATIONS ON MATRIXES:\
- ```inverse {name}``` : Inverses the matrix {name}\
- ```inverse {name1}``` {name2} :  Copies the inverse of matrix {name1} to {name2}\
- ```delete {name}``` : Deletes the matrix\
- ```change {name}``` {row} {column} {value} : Changes the value of element [{row}][{column}] in matrix {name}\
