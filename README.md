# Clone Thread Example
This C program uses clone() to create a new thread. It illustrates, that the new thread shares the same data and heap segment. The main process creates a new thread with clone. clone() will execute a function that prints a buffer to stdout and then waits 2 seconds and does it again. In the meantime, the main thread changes the content of the buffer. That the child thread prints different things shows that they are not seperate processes.

# Compile 
```
make
```
# Run 
```bash 
./main
```
