# get_next_line

In this project we must create a function that returns one line from the specified fd every time it is called, followed by a newline if the line has one. This project introduces the idea of static variables, which will be very useful for future projects. On top of that, we'll also learn a way to define macros right when compiling!

The function to implement is called `get_next_line`, and will have the following prototype:

```C
char *get_next_line(int fd);
```

- Function Overview

`ft_copy_to_stabuf` It takes two strings and concatenates them into a new string

`ft_extract_line` Finds and extracts a line of text up to the first line break character ('\n') from a character string

`ft_free_stabuf` Frees the memory associated with the stabuf pointer (static buffer) and returns a copy of the string pointed to by stabuf  
 before freeing it

`ft_new_line` Checks if a string contains a line break ('\n')

`ft_recreate_stabuf` Creates a new string containing the contents of stabuf starting from the first line break to the end of the original string

`ft_strdup` Creates a copy of the string in dynamic memory and returns a pointer to the copy

`ft_strjoin` Concatenates two character strings and returns a pointer to the concatenated string

`ft_strlen` Calculates the length of a character string without including the terminating null character

`ft_subtsr` Takes a string, a starting position, and a length as arguments and returns a substring of the original string starting from the starting position with the specified length

`get_next_line` Reads a file line by line, storing the partially read content in a static buffer and returning each line complete as line breaks are encountered. After the file is finished, it frees the memory associated with the buffer and returns the last line read.
