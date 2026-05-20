# Project_ASP
This is a repoitory for the project in course Advanced System Programming  

## Build and run tests instruction
1) Write in terminal `docker build --target test_runner -t recommendation-tests .
` for bulding 
2) Write it terminal `docker run --rm rec-tests  ` for running tests

## Build and run app instruction
1) Write in terminal `docker compose build  
` for buiilding
2) Write in terminal `docker compose run client
` for running app

## Port modifying 
In case you decide to change port open `docker-compose.yml` file and change port from `8080` in all dedicated places. They were also marked in comments
(I have no clue why and in my opinion it doesn't make any common sense)


# SOLID & Open-Closed Principle (OCP)

**Command changes** (Names and new commands):
Adding new commands like PATCH and DELETE, or renaming old ones to GET and POST, didn't require us to change the main app logic. Thanks to our design from the first exercise, we only had to add new classes for the new commands. The core code stays closed for modification but open for extension. 

**Output format changes:** 
Changing the exact output strings was simple. We only updated the return values inside the specific command classes, without touching the main system.

**Console to TCP Sockets:** 
Moving from console I/O to sockets didn't break our OCP design. We added the IRequestHandler interface. The TcpServer handles the network and uses this interface to pass strings to the app logic. The app logic doesn't even know it's getting data from a network socket now. 

**Future - Multiple Clients:**
If we need to support many clients at the same time in the future, our code is ready. Because the network server is completely separated from the business logic, we will only need to add threads to the TcpServer. We won't need to change the application logic at all. 
