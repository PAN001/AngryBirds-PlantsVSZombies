# AngryBirds-PlantsVSZombies

## Game Story
The title of the game is Angry Birds & Plants VS. Zombies. The game background is that there has been a war between zombies and plants lasting for hundreds of years. As time goes by, zombies gradually became immune from normal attacking from plants and they killed all sunflowers. As a result, the number of plants became smaller and smaller, and finally there was only one pea shooter left. In order to protect the garden, this final plant, pea shooter, asked help from angry birds. To fight against the vicious zombies, angry birds agreed to help the pea shooter, and thus the war between plants, angry birds and zombies starts.

## Game Play
The players controls the pea shooter, which is set at the middle of the bottom of the screen. It could send out angry birds, like bullets, to kill the zombies that come from the right side of the screen and walk to the left side.

## Game Design and Implementation
The game is written in C++ and Simple DirectMedia Layer (SDL) 2.0, which is a cross-platform development library designed to provide low level access to audio, keyboard, mouse, joystick, and graphics hardware (Wikipedia, 2016). The complete codes are divided into several logically related components and run through the main function defined in MainFunction class.

## OOP Design
Object oriented concepts, such as abstraction, encapsulation, separating implementation from interface, inheritance, composition and polymorphism, are carefully taken in consider- ation and adopted flexibly during the development of the game.

In terms of abstraction, the main purpose is to hide data or information that is not necessary to be presented. The important idea behind data abstraction is to give a clear separation between properties of data type and the associated implementation details. For encapsu- lation, it is mainly focused on restricting access to some components of the object, which prevents the object being changed directly from outside sources. Abstraction together with encapsulation mechanisms provides more flexibility in approach and ensures the security of the program. As a form of software reuse, inheritance allows an object (of the derived class) to inherit properties and methods from another object of a higher or base class. The relationship between the two classes is the is-a relationship. In C++, there are two types of in- heritance, single and multiple inheritance, and three specific ways to implement inheritance: public, protected and private. In this game, inheritance is efficiently adopted in the design of zombies, bird bullets among all other displayed objects in the game.

In OOP design, composition refers to a way to combine simple objects or data types into more complex ones. Each composition is an independent logic building block of related objects of other class. The relationship represented by composition is the has-a relation- ship, which is different from the is-a relationship in inheritance. Polymorphism is another importantpartofOOP,whichenableshavingdifferentobjectswiththesameinterface,but with different implementations. In the OOP design of this game, polymorphism is realized through hierarchical inheritances and flexible manipulation of pointers.

### Separating interface from implementation
As a fundamental principle of software engineering, separation between interface and imple- mentation could hide details of implementation from the client code. In this game, all class definition is splitted into two separate files, the header file where the class is defined and the source-code file in which the member functions of the class are defined.

### Inheritance hirearchy
DisplayableObject is the base class which represents an independent object shown in the game interface. It composes all necessary information about an game object including the pointer to the texture (of MyTexture class), the pointer to the game engine (of MyEngine class), the width, height and the position of the object. Zombie, BirdBullet, Battery, Button and Text are all derived classes of DisplayableObject class because they all share common properties and methods.

Each derived class overrides the virtual function such as draw and doUpdate to realize various visual appearance and animation. The UML class diagram below shows the relation- ship of the hierarchical inheritance:
Based on the DisplayableObject inheritance, polymorphism could be easily achieved and thus the whole game system becomes much more flexible and easily extensive. By assign- ing the address of a derived class to a base-class pointer, specific functions of the derived classes could be called through base-class pointers. Based on this mechanism, a list of Dis- playableObject pointers pointing to different derived classes is maintained. When updating or rendering each object, there is no need to distinguish among object types and invoke an appropriate action for a particular object at compile time; instead, a one time traversal through the whole list and calling one same function of each object could achieve the ex- pected effect.

Moreover, new classes such as a new zombie or bird bullet can also be added with little or no modification to the program, as long as they are part of the inheritance hierarchy that the program processes generally.


### Inheritance Example: Zombie and its derived classes
Zombie class itself serves as a base class and provides template for its derived classes, various kinds of zombies. In the game, derived classes only override the constructor to specify different texture, HP, velocity and rewarded points due to the simplicity of the game. However, there may be more methods needed to be overridden, such as die function which creates various dying animation after the zombie is killed.

### Composition and aggregation
Basically, there are two kinds of compositions. The first one is the normal composition where all sub objects which belong to the owner object are destroyed whenever the owner object is destroyed whereas the other one is called aggregation where sub objects will not be destroyed. In the normal composition, subclasses are added as normal variables or pointers, existing within the class. However, in aggregation, sub objects are either pointers or references.

In the game, one example of aggregation is that each object of DisplayableObject main- tains one pointer to the game engine so that each object could get or change attributes of the game such as the current position of the mouse, the game state and game level by calling getters and setters. As aggregation, when the objects of DisplayableObject class is destroyed, for example, the zombie is dead and the bullet is exploded, the game engine will not be affected and still exist.

With regard to the normal composition, for example, the Game class consists of neces- sary objects for the game such as SDL_Window, SDL_Renderer, timer, background images (of MyTexture class) for different interfaces, audios and the list of all displayable objects. The UML diagram below illustrates the main composition and aggregation relationship.

### Design pattern: Observer
The relationship between the game engine and all displayable objects is by nature a one-to- many dependency, which means once the state of the engine (game itself) is changed, all its dependents should be notified and updated automatically. The observer design pattern is an ideal solution to this situation.

In the design of the Game class (game engine), it maintains a list of objects of Displaya- leObject, which are its dependents, called observers, and notifies them automatically when the state is changed through function updateAllObjects.

