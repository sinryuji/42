# get_next_line
42 Seoul get_next_line By hyeongki

# Description
파일 디스크립터로부터 읽혀진, 개행으로 끝나는 한 줄을 반환하는 함수를 만드는 서브젝트이다.

# Mandatory
|Function Name|get_next_line|
|------|---|
|Prototype|char *get_next_line(int fd);|
|Turn in files|get_next_line.c, get_next_line_utils.c, get_next_line.h|
|Parameters|fd: The file dscriptor to read from|
|Return value|Read line: correct behavior</br>NULL: there is nothing else to read, or an error occurred
|External functs|read, malloc, free|
|Description|Write a function that returns a line read from  a file descriptor|

# Bonus
Be implemented to work on multiple FD

# Tester
1. https://github.com/Tripouille/gnlTester

# Finish
<img width="199" alt="Screen Shot 2022-06-10 at 5 21 42 PM" src="https://user-images.githubusercontent.com/59722407/173023560-a926235b-fcfc-4611-ad31-a447b4640781.png">
