# Project_ASP
This is a repoitory for the project in course Advanced System Programming  

## Build and run tests instruction
1) Write in terminal `docker build --target test_runner -t my-project-tests . 
` for bulding 
2) Write it terminal `docker run --rm my-project-tests  ` for running tests

## Build and run app instruction
1) Write in terminal `docker build --target runtime -t recommendation-app .
` for buiilding
2) Write in terminal `docker run -it -v "${PWD}/data:/app/data" recommendation-app
` for running app