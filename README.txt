1. Empty tile's value is assumed to be 0. Hence 0 is returned in VALUE query, and any changes in board are judged by this perspective only

2. [4 2 2 4] With SUBTRACT LEFT is assumed to give [4 4 0 0] 

3. STDERR printing is done only if there is any change in matrix/board or names/variables

4. Any syntax errors lead to -1 on STDERR and syntax error message on shell

5. Other errors like out of cell range (exampe: VALUE IN 5,1.) or Variable name already exists, also lead to -1 in STDERR and error messages on shell

6. Names/variables are implimented using 2-D array of doubly linked lists

7. Board is implimented using a 2-D array

8. Failure of insertion of random tile in case the board is full, is not considered an error and nothing is printed on STDERR (since no change in board or names)

9. Every line is treated as a single statement and any number of syntax errors in a line results in only one -1 print on STDERR and only one syntax error print on shell

10. Space and tab are considered equivalent while \n (newline) is different from both and it is used to identify end of a line and statement

11. Variable names can start with any alphabet (upper/lower case or underscore) and can have numbers too in non-starting position 

12. Case sensitivity is maintained 

13. The executable formed on "make" command is named "exe", run it using "./exe"
