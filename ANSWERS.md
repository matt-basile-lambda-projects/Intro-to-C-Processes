**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
Prequel - Allocate data: in order for any process to run there needs to be allocted space to store their data. This is done prior to entering the process.
1.) Start - Our process is initiate and first created
2.) Ready - Our process is ready to rock and anxiously waiting to be assigned to a processor. 
3.) Running - Once assigned to a processor the process begins to run and executes the instructions.
4.) Waiting - Process continues until it waits for some sort of data whether that's a file, user input or a returned resource.
5.) Exit - The process completes execution and is terminated by the OS. 

**2. What is a zombie process? How does a zombie process get created?**
Essentially, when we fork a process we create a parent and child process. In a perfect world, all of our children processes would run before our parents so that our parents can clean them up. Wellllll, that doesn't always happen, sometimes our parents can finish prior to our child. Leaving our child to complete but never get cleaned up. Sitting in a state of half alive half dead, our child sits their occupying space but not really causing a major problem unless we have multiple zombies continue to accumulate. 


**3.  How does one get destroyed?**
The first way to prevent zombies to happening in the first place is by implementing our wait() system call. This will force our parent to wait for our child's response before continuing. 

The hard thing about zombies is that they're already dead so we can't use the SIGKILL command to destroy them. Instead we can use kill -s SIGCHLD pid, where the pid is the parent id of the zombie child. That way the parent can clean them up and "take care of them". 


**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**
Compiled Languages:
Pros: 
- Faster Performance because the code used is directly relatable and readable by the machine aka Computers. Making run time and optimization much quicker! This also lends to more control over memory management. 
- There's a manual "build" step to compiled languages, which forces us to rebuild a program every time a change is made (see:gcc -o ex ex.c)

Non-compiled Languages:
Pros:
- Easier to implement, more programmer friendly syntax. (maybe im biased :P )
- Catching up from being considered the slower of the two types of languages
