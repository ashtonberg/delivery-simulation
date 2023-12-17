# UMTC Campus Routing Simulation
## Team Number 001-29
## Members
* Adam Arnett, arnet027
* Ashton Berg, ber00063
* Philip Nguyen, nguy4652
* Jack Pearson, pear0829

## Docker
Link to our deployed simulation on Docker: https://hub.docker.com/r/plip02/team-001-29-drone-sim

Use this command to pull from Docker:
```bash
docker pull plip02/team-001-29-drone-sim
```
Use this command to run after pulling from docker:
```bash
docker run --rm -it -p 8081:8081 plip02/team-001-29-drone-sim
```

## System Description
The system is designed to simulate routing and traffic on the University of Minnesota Twin Cities (Minneapolis) campus. It features a 3D map of the campus, and several different entities that exist and move within the map. Currently, the entities include:
* Drones
* Robots
* Packages
* Humans
* Helicopters 
* Stop Signs
* Cars 
<!-- end list -->

## UML Diagram
![UML Diagram](/images/UMLDiagram.png "UML Diagram")
This diagram shows the relationships our new features have with each other.


Users can simulate the delivery of packages with a scheduler page that is seperate (but accessible from) the map.

### Running The System
To run the system, open a terminal and change your working directory to the file that contains the system. Then, run the following commands:
```
// makefile builds the project
make -j
// run with ./build/web-app <port> <web folder>
./build/web-app 8081 apps/transit_service/web/
```
Those commands start the server. To access the map view, navigate to http://127.0.0.1:8081. To access the scheduler page, navigate to http://127.0.0.1:8081/schedule.html. If you used a port other than 8081 in the second command, replace 8081 in the links with the port you used.

### Map View
![Map view](/images/screenMain.png "Map view")
The map is a 3D map featuring sattelite images of the university. The horizontal textures on the map (ground/roads, roofs of buildings, etc.) are composed of the sattelite images, while the vertical textures are currently blank.  
The user has a "birds eye view" of the campus which can be panned, zoomed, and tilted by the user. Certain entities can also be selected to automatically watch. That is, the view will automatically follow the entity as it moves to keep it in the center of the view.

### Delivery Scheduler
![Delivery scheduler](/images/screenScheduler.png "Delivery scheduler")
The system features a delivery scheduler that allows for the simulation of a package being delivered to a destination.
To schedule a delivery, the user inputs the name of the package's owner, the pathfinding strategy (astar, depth first, etc), and a pickup location and delivery location on the map. Scheduling a delivery will create a package and robot entity then dispatch a drone to pickup and deliver the package to the robot.  
Users can also create human entities from the scheduler, which require no specific input other than the request for it to be created.

### Entities
The campus is populated by a selection of entities. These entities are represented on the map by an animated 3D model. Each different type of entity has it's own unique behaviors.
###### Drones
Drone entities exist on the map to move (deliver) package entities to robot entities. These deliveries are scheduled by the user. The drone's propellers are animated. When the system is started up, one drone is created.
###### Robots
Robot entities exist on the map to recieve packages delivered by Robots. The position of a Robot does not change, but like most entities their model is animated, they periodically spin and wave. They are created when a delivery is scheduled by the user.
###### Packages
Package entities exist on the map to represent packages transported in deliveries. They do not move on their own, but are moved by drone entities to their owner (a robot entity). Their model does not have any animation.
###### Humans
Human entities exist on the map to represent pedestrians. While most pedistrians have a specific destination in mind, the human entities choose a destination at random and walk to it, repeating the process on arrival. Their model moves it's legs as it walks. One human is created on startup, but more can be created in the scheduler.
###### Helicopters
Helicopter entities exist on the map to represent air traffic. The helicopters operate similarly to the humans in that they pick a random destination and go there, except in the air rather than on the ground. One helicopter is created on startup.  

## New Feature - Notifications
![Notifications](/images/screenNotifications.png "Notifications bar shown on the left")
The new notification feature was added to notify the user of certain events via a translucent notification bar on the left side of the map view.  
The notifications will allow users to be more aware of all of the events occuring in the simulation. Currently, the system will notify the user when a drone is dispatched to pickup a package, picks up a package, or delivers a package. The implementation of this feature follows the observer pattern, where drones posses a subject object that attaches to a DroneObserver that sends any messages it recieves from the subject object to the UI.

## New Feature - Stop signs
![Mediator](/images/screenMediator.png "Stopsign with cars")
### NOTE: We were not able to find a 4-way-stopsign model, so intersections are shown by a single stopsign in the middle of the intersection.
Stop signs were added to the simulation so drones and cars will not collide at intersections. Once a drone or car reaches an intersection it will be add to a queue and be allowed to move through the intersection one by one. Along with intersections, a collider decorator was added to each collidable entity. Two entities that are facing different directions are allowed to pass through each other, but two entities facing the same directions are able to collide.

The stop signs were implemented using the mediator design pattern, which means that collidable entities do not communicate with each other to decide when it is their turn to stop and pass through an intersection. Instead, there exists a intersection mediator that keeps track of every intersection and collidable entity. The mediator then decides which intersection to add the car to and the intersection will tell which car when to stop and when to pass through the intersection. 

The collision decorator was implemented using the decorator design pattern. The collision decorator wraps the collidable entities allowing us to change its update function. There is then a collision mediator that keeps track of every collision decorator. The mediator then checks every update call for a collision and decides if an entity needs to stop.

## Sprint Retrospective
We were able to complete the entire project in time, but our sprint could have been done more efficiently. We saved most of the work for the second half of the deadline and had to do some cramming towards the end. In the future, we would spread out our work to have a more even work flow. We had weekly meetings, but besides those, we didn't have much comunication. We feel as though we could have better communicated throughout the process and had more consistent progress updates, such as sending more messages over our group discord. Overall, our sprint was successful in getting the project done and dividing work among team members through smaller tasks, but our communication and time management could have been better.
