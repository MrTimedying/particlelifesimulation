
# Introduction: what is a particle life simulation

#emergence #complexity #AI 

Particle life simulations are a specific family of programs that aim at simulating the phenomenon known as emergence. Emergence is a concept that roots into complexity theory, which is a branch of sciences that is not a discipline itself, but embeds a series of fields that approach the study of phenomena through the assumption of complex behavior and non-linearity.

The concept of emergence was appreciated at the mainstream level subsequent to the publication of Humberto Maturana and Francisco Varela in 1980 titled <i>"Autopoiesis and cognition"</i>.  The concept of autopoiesis refers to autonomous self-organizing and <b>self-defining</b>  systems, which then exhibit group behaviors at the interaction level of their single components, which do not possess explicit instruction of the sort. In other words, the parts which constitute an autopoietic system or autopoietic group, eventually coordinate in an unexpected manner to exhibit a particular group behavior.

# Background knowledge: coding

#coding #cpp #OpenFrameworks 

### 0.1 Declarations

In C++, when you declare a variable, you are essentially telling the compiler that a variable with a certain name and data type will be used in your program. However, you need to initialize (create) the variable before you can use it.

Here's the correct sequence:

1. **Declaration**: You declare the variable, indicating its name and data type.
2. **Initialization**: You initialize (create) the variable using the constructor or appropriate method.

So, in my previous example:

```
Vector myVector; // Declaration
myVector.position(10, 20); // Initialization using the position method
```

Here's an alternative way using a constructor:

```
Vector myVector(10, 20); // Declaration and Initialization using constructor
```

The term "declaration" is often used to indicate that you're informing the compiler about the existence of a variable, and "initialization" means giving that variable an initial value.
Remember, the sequence might vary depending on whether your class has a constructor that takes arguments. If it does, you can initialize the instance directly during declaration. If not, you'll declare the variable and then use a method to initialize it.

### 02. Arrays

Arrays are a fundamental concept in programming and are used to store multiple values of the same data type in a single variable. They provide a way to group related data together and access it using an index.

**Arrays in General:** In general, an array is a data structure that holds a fixed-size collection of elements, each identified by an index or a key. Arrays are widely used in programming to store and manipulate data efficiently.

**Arrays in C++:** In C++, an array is a fixed-size sequence of elements of the same data type. The elements of an array are stored in contiguous memory locations, which makes accessing and manipulating them relatively efficient. The index of the elements starts at 0, so the first element is at index 0, the second at index 1, and so on.

Here's a simple example of how to declare and use an array in C++:

```
#include <iostream>

int main() {
    int numbers[5]; // Declare an array of integers with size 5

    // Initialize array elements
    numbers[0] = 10;
    numbers[1] = 20;
    numbers[2] = 30;
    numbers[3] = 40;
    numbers[4] = 50;

    // Access and print array elements
    for (int i = 0; i < 5; i++) {
        std::cout << numbers[i] << " ";
    }

    return 0;
}
```

*  `cout` is a standard C++ stream that represents the standard output, usually the console or terminal. It's used to print or output information to the console. 
* `<<` is the insertion operator in C++. It's used to insert data into a stream. In this case, it's used to insert the value of **numbers[i]** into the **cout** stream.
* `numbers[i]` accesses the element of the array **numbers** at index **i**. So, for each iteration of the loop, it will access a different element of the array.
* `" "` is a string literal that represents a space. It's used to separate the output values in the console. It's included to make the output more readable by adding a space between each printed element. 

you can declare and initialize an array in C++ at the same time using what's called an initializer list. Here's how you can do it:

```
int numbers[] = {10, 20, 30, 40, 50};
```

In this example, the compiler infers the size of the array based on the number of elements in the initializer list. So, **numbers** will be an array of 5 integers.

This syntax allows you to declare, initialize, and fill the array in a more compact way. It's especially useful when you know the initial values of the elements and want to avoid writing multiple lines of assignment.

**Arrays in Python:** In Python, lists are used to achieve similar functionality as arrays in other programming languages. Lists are ordered collections of items, and they can hold elements of different data types. Lists are dynamic in size, meaning you can add or remove elements as needed.

Here's an example of how to use lists in Python:

```
numbers = [10, 20, 30, 40, 50]  # Create a list of numbers

# Access and print list elements
for number in numbers:
    print(number, end=" ")
```

In Python, there's also a built-in **array** module that provides more memory-efficient arrays for storing elements of the same data type. However, lists are used more commonly due to their flexibility.
In summary, arrays (or similar data structures) are essential tools for organizing and manipulating collections of data in programming. The specifics of how arrays are implemented and used can vary between programming languages, but the core concept remains the same.

### 02.1 Array Pointers

The concept of array pointers involves using an array to hold pointers to objects, rather than the objects themselves. This can be a powerful technique in programming, providing flexibility, efficiency, and allowing for polymorphism.

Let's break it down step by step:

1. **Pointers**: A pointer is a variable that holds the memory address of another variable. Instead of directly storing a value, a pointer stores the location where that value is stored in memory.
2. **Arrays**: An array is a collection of elements, each identified by an index or a position. Each element in an array has the same data type.
3. **Array of Pointers**: An array of pointers is an array where each element is a pointer. Instead of holding the actual data, each element in the array holds the memory address of some data.


Now, let's look at how this concept applies to your particle system:

You have three types of particles: blue, red, and yellow. Each type is a different class derived from the base `Particle` class. By using an array of pointers, you can store instances of these derived classes in a way that allows you to manage and iterate through them more efficiently.

Here's why array pointers can be useful:

1. **Polymorphism**: Since all derived particle classes are subclasses of the base `Particle` class, you can store pointers to instances of all these classes in the same array. This allows you to treat all particles uniformly, even though they have different behaviors and properties.
2. **Efficiency**: Storing pointers instead of the actual objects can be more memory-efficient and faster, especially when dealing with a large number of objects. The memory overhead of a pointer is typically smaller than that of an entire object.  
3. **Dynamic Allocation**: If you need to create or destroy particles during runtime, using pointers allows you to allocate memory dynamically and manage resources more effectively.

Here's a step-by-step example of how it works:

1. You create an array of pointers to the base class `Particle`.

```
Particle* particleArray[n]; // An array of pointers to Particle objects
```

2. You instantiate derived classes and assign their addresses to the array of pointers.

```
particleArray[0] = new BlueParticle();   // Instantiate a BlueParticle
particleArray[1] = new RedParticle();    // Instantiate a RedParticle
particleArray[2] = new YellowParticle(); // Instantiate a YellowParticle
```

3. You can now loop through the array and call methods on the objects.

```
for (int i = 0; i < n; i++) { particleArray[i]->update(); // Call the update method on each particle }
```

4. Don't forget to deallocate the memory when you're done.

```
for (int i = 0; i < n; i++) { delete particleArray[i]; // Deallocate memory for each particle }
```

In your specific case, you're using an array of pointers to manage different colors of particles. This approach can make your code more organized, efficient, and easier to maintain, especially if you plan to add more types of particles or behaviors in the future.
### 03. if statement

In C++, the **if** statement is a conditional construct that allows you to execute a block of code only if a certain condition is true. Here's the basic syntax:

```
if (condition) {
    // Code to execute if condition is true
}
```

Here's a breakdown of the components:

1. **if:** This is the keyword that starts the conditional statement.
2. **(condition):** This is the condition that is evaluated. It's enclosed within parentheses. If the condition is true, the code inside the block will execute; otherwise, it will be skipped.
3. **{}:** These curly braces define a block of code. If the condition is true, the code inside the curly braces will be executed. If there's only a single statement, you can omit the curly braces, but it's generally recommended to use them for clarity and to avoid potential bugs.

Here's an example of how the **if** statement works:

```
int age = 25;

if (age >= 18) {
    cout << "You are an adult." << endl;
}
```

In this example, if the value of **age** is greater than or equal to 18, the message "You are an adult." will be printed.
You can also use an **else** clause to provide code that should be executed when the condition is false:

```
int temperature = 22;

if (temperature >= 25) {
    cout << "It's hot outside." << endl;
} else {
    cout << "It's not that hot." << endl;
}

```

In this case, if the temperature is 25 or higher, the first message will be printed; otherwise, the second message will be printed.
Additionally, you can use the **else if** clause to specify alternative conditions to check:

```
int score = 85;

if (score >= 90) {
    cout << "You got an A!" << endl;
} else if (score >= 80) {
    cout << "You got a B." << endl;
} else if (score >= 70) {
    cout << "You got a C." << endl;
} else {
    cout << "You need to improve." << endl;
}

```

In this example, the program checks the score and prints a different message based on the score range.
Remember that the **if** statement evaluates the condition as a boolean expression (true or false). If the condition is true, the code within the block will execute; otherwise, it will be skipped.

### 04. Nested loops

Nested loops involve using one loop inside another, allowing you to iterate over multiple dimensions of data.

Here's the example code you provided for updating particle interactions:

```
for (int i = 0; i < ny; i++) {
    for (int j = 0; j < nb; j++) {
        float distance = ofDist(
            yellow_particles[i].position.x, yellow_particles[i].position.y,
            blue_particles[j].position.x, blue_particles[j].position.y
        );

        if (distance < 400) {
            yellow_particles[i].speed.x *= -1;
            yellow_particles[i].speed.y *= -1;
        }
    }
}
```

Let's break down how this nested loop works step by step:

1. **Outer Loop (`i`)**: The outer loop iterates through the yellow particles array. For each iteration of the outer loop, the inner loop will be executed completely.
2. **Inner Loop (`j`)**: The inner loop iterates through the blue particles array. For each yellow particle in the outer loop, the inner loop iterates through all the blue particles.
3. **Distance Calculation**: Inside the inner loop, you calculate the distance between the `i`th yellow particle and the `j`th blue particle using the `ofDist` function. This calculates the Euclidean distance between the positions of the two particles.
4. **Interaction Check**: If the calculated distance is less than 400 (a threshold you've chosen), it means that the yellow particle is close to the blue particle. In this case, you reverse the direction of the yellow particle's speed. This simulates an interaction where the yellow particle reacts to the proximity of the blue particle.

By using nested loops in this way, you're checking for interactions between every yellow particle and every blue particle. The nested loops allow you to compare each combination of particles in your simulation.

Here's a visual representation of the nested loop process:

```
Outer Loop (yellow particles):
  - Iteration 1:
    Inner Loop (blue particles):
      - Iteration 1: Calculate distance and check interaction
      - Iteration 2: Calculate distance and check interaction
      ...
    End Inner Loop
  - Iteration 2:
    Inner Loop (blue particles):
      - Iteration 1: Calculate distance and check interaction
      - Iteration 2: Calculate distance and check interaction
      ...
    End Inner Loop
  ...
End Outer Loop
```

In this way, you systematically evaluate interactions between each yellow particle and all blue particles, resulting in a more complex and dynamic particle behavior.

Nested loops are a powerful technique for handling multi-dimensional data and relationships between multiple entities in your simulation or program. However, keep in mind that they can also lead to performance issues if not used carefully, especially when dealing with large datasets.

### 04.2 Index vs Range based loops

#### Range-Based `for` Loop (For-Each Loop):

The range-based `for` loop is a more modern construct introduced in C++11. It's designed to simplify iterating through collections, such as arrays, vectors, and other iterable containers. Here's the basic syntax of a range-based `for` loop:

cppCopy code

`for (const auto& element : collection) {     // Do something with 'element' }`

- `element`: This is a placeholder variable that represents the current element of the collection during each iteration.
- `collection`: This is the container you want to iterate through, like an array, vector, or any other iterable container.
- `auto`: This keyword is used to automatically deduce the correct data type of each element in the collection.


Advantages of the Range-Based `for` Loop:

1. **Readability:** The syntax is concise and self-explanatory, making the code more readable and reducing the chance of off-by-one errors.
2. **Simplicity:** You don't need to manually manage an index variable, which simplifies the code and reduces the risk of index-related bugs.
3. **Safety:** The loop automatically handles bounds checking and prevents you from accidentally accessing elements out of bounds.
4. **Less Boilerplate:** You don't need to deal with index incrementing and decrementing, making the code more focused on the actual task.

#### Index-Based `for` Loop:

The index-based `for` loop is a classic loop that iterates through a collection using an index variable. It provides more control over the loop's behavior, particularly when you need to manipulate the index.

Here's the basic syntax of an index-based `for` loop:

cppCopy code

`for (int i = 0; i < collection.size(); i++) {     // Do something with collection[i] }`

- `i`: This is the index variable that you manually increment or decrement in each iteration.
- `collection.size()`: This gives you the size of the collection, which you use as the loop termination condition.

Advantages of the Index-Based `for` Loop:

1. **Control:** You have direct control over the index, which is useful when you need to perform tasks based on the index or manipulate it.
2. **Flexibility:** You can modify the index in custom ways, such as skipping certain elements or going backward in the collection.
3. **Familiarity:** Programmers familiar with traditional loops in other languages will find this syntax more recognizable.

In Conclusion:

Choose the loop style that best suits your needs and the clarity of your code. If you're simply iterating through a collection and don't need to manipulate the index, the range-based `for` loop is often cleaner and less error-prone. If you need more control over the index or need to perform operations based on the index, the index-based `for` loop is a suitable choice. Ultimately, both methods are valid and serve different purposes in different situations.

# OpenFrameworks 

#OpenFrameworks #CreativeCoding
### 01. Setting a background color

The **ofBackground()** function is used to set the background color of your canvas. Its purpose is to clear the canvas and set it to a specific color before you start drawing new content. This is important because each frame in your animation or application is drawn on top of the previous frame, and if you don't clear the canvas, the previous frame's content will still be visible.

In the context of your code, you have two places where you're using **ofBackground()**:

1. **In setup() function:** You use **ofBackground()** in the **setup()** function to set the initial background color for your canvas. This sets the background color once at the beginning of your program when it starts running. The setup function is typically used for one-time initializations.

```
void ofApp::setup(){
    ofBackground(255, 255, 255); // Set the background color to white
    // ... other setup code ...
}
```

2. **In draw() function:** You also use **ofBackground()** in the **draw()** function to clear the canvas and set the background color before you draw new content on it. This function is called repeatedly in a loop, so it keeps refreshing the screen with new content.

```
void ofApp::draw(){

    ofBackground(255, 255, 255); // Clear the canvas and set background to white

    // ... draw your particles and other content here ...

}
```

In summary, **ofBackground()** in the **setup()** function sets the initial background color, and **ofBackground()** in the **draw()** function clears the canvas and sets the background color before drawing new content. This separation helps ensure that you start each frame with a clean slate and avoid overlapping content from previous frames.

### 02. Particle class

```
class particle {

public:

	ofVec2f position;
	ofVec2f speed;
	int radius;
	ofColor color;

};
```

The particle class is the base for the particle "object" as intended. There are other ways to instantiate particles in the environment space, but for our codebase we will be using the class. The main function of the class is to store variables such as vectors, position, radius and color. The particle class must be added to the `ofApp.h` header file sheet, that contains all the declarations. Whilst it's implementation is done in the `ofApp.cpp` which is the main definition sheet that later gets called in the `ofMain.cpp` sheet of the application. The header file also contains the base imports from the `ofBaseApp.h` library header, that contains all the possible methods that OpenFrameworks gives out.

### 02.1 Constructor

**Constructors** are an essential concept in the C++ programming language, and they're not limited to OpenFrameworks or particle systems. They're a fundamental part of object-oriented programming and are used to initialize objects of a class.

Here's what you need to know about constructors:

1. **Initialization:** When you create an object of a class, the constructor is called automatically. The purpose of a constructor is to initialize the object's attributes (member variables) to some initial values.
2. **Name and Syntax:** The constructor has the same name as the class, and it doesn't have a return type, not even `void`. It is defined within the class just like any other member function.
3. **Parameterized Constructors:** Constructors can take parameters, allowing you to provide initial values when creating an object. These parameters are used to set the attributes of the object.
4. **Default Constructor:** If you don't define any constructor, C++ provides a default constructor with no parameters. However, if you define a constructor with parameters, the default constructor isn't generated automatically, and you need to explicitly define it if you want it.
5. **Overloading Constructors:** You can define multiple constructors with different parameter lists. This is called constructor overloading. It allows you to create objects with various initializations.
6. **Initializer List:** Inside the constructor's definition, you can use an initializer list to directly initialize the attributes. This is usually more efficient than assigning values within the constructor's body.

Here's a simple example of a class with constructors:

```
class Person {
public:
    // Default constructor
    Person() {
        name = "John Doe";
        age = 30;
    }

    // Parameterized constructor
    Person(std::string n, int a) {
        name = n;
        age = a;
    }

    void displayInfo() {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }

private:
    std::string name;
    int age;
};

int main() {
    Person person1; // Calls default constructor
    person1.displayInfo();

    Person person2("Alice", 25); // Calls parameterized constructor
    person2.displayInfo();

    return 0;
}
```

In this example, the `Person` class has a default constructor and a parameterized constructor. When objects `person1` and `person2` are created, their attributes are initialized based on the constructor used.

So, to summarize, constructors are a fundamental concept in C++ and are used to initialize the properties of objects when they're created. They're an important part of object-oriented programming and are not specific to OpenFrameworks or particle systems.

### In Depth: declaration vs implementation

#### Header Files (.h):

1. **Declarations**: In C++, header files (.h) are used for declaring the interface of classes and functions. They contain the class structure, member variables, function prototypes (declarations), and any other information needed for code that interacts with these classes.
2. **Class Declaration**: In the particle class you've provided, the block of code between `class particle {` and `};` is the class declaration. It outlines the structure of the class, including member variables and function declarations.
3. **Member Variables**: The `ofVec2f position`, `ofVec2f speed`, `ofVec2f acceleration`, `ofColor color`, and `float radius` are member variables of the particle class. They represent the properties that each particle object will have.
4. **Constructor Declaration**: The line `particle(int x, int y, int r, int g, int b, int radius);` is the declaration of the constructor for the particle class. It outlines how to create a particle object by passing specific parameters.
5. **Member Function Declarations**: The `void update();` and `void draw();` lines are declarations of member functions. They indicate that particle objects will have these functions that can be called later.

#### Implementation Files (.cpp):

1. **Constructor Implementation**: The lines starting with `particle::particle(int x, int y, int r, int g, int b, int radius) {` and ending with `}` provide the implementation of the constructor. This is where you define what happens when a new particle object is created.
2. **Member Function Implementations**: Similarly, the `void particle::update() { ... }` and `void particle::draw() { ... }` lines provide the implementation of the `update()` and `draw()` member functions respectively.
3. **Scope Resolution Operator (::)**: In the implementation file, the `::` operator is used to link the implementation to the class declared in the header. It tells the compiler that the code inside the block is the implementation of the member functions for the specified class.

#### Why Separate Declaration and Implementation?

The separation of declaration and implementation serves several purposes:

1. **Encapsulation**: By keeping the implementation separate, you only expose the necessary details of the class to external code. This enhances encapsulation and data hiding, preventing direct access to the internal workings of the class.
2. **Readability and Maintainability**: With separate files, the header file provides a clear interface to the class, making it easier to understand and use. The implementation file contains the detailed logic, making the codebase more organized and maintainable.
3. **Compilation Efficiency**: Separation allows you to change the implementation without affecting code that uses the class. This reduces the need for recompilation of unrelated parts of your code when you make changes.
4. **Prevent Duplicate Definitions**: If the implementation were included in header files and the header was included in multiple source files, it could lead to multiple definitions, causing compilation errors.


By adhering to this separation, you create a clean and well-structured codebase that is easier to manage, understand, and maintain.

#### How It Works:

When the compiler compiles your application, it processes the header files and source files separately. During compilation, the compiler needs to know the structure of classes, functions, and their declarations, which is provided by the header files. It then links this information to the actual implementation defined in the source files.

This separation allows you to change the implementation details without affecting the rest of the code. Additionally, the compiled binary only contains the necessary information, making the executable efficient and compact.

Remember that the scope resolution operator (`::`) is used to specify that the code inside a block is part of a specific class, connecting the class declaration to its implementation.

## Behaviors

#behavior #emergent-behavior
### Calculating the distance

Calculating the distance in particle systems is fundamental, because it's the base staple for two entities that want to interact with each other. Most of the interactions between two particles are distance based for this simulation as of now.

```
float Distance(const particle& p1, const particle& p2) { 
	ofVec2f diff = p2.position - p1.position; 
	return diff.length(); 
	}
```

1. `float`: This specifies the return type of the function. It indicates that the function will return a floating-point number (a decimal value) representing the distance between particles.
2. `Distance`: This is the name of the function. You can choose any meaningful name for your function that describes what it does.  
3. `const particle& p1, const particle& p2`: These are the function parameters. The function takes two constant references to `particle` objects as input. The `const` keyword indicates that the function won't modify the particles it receives, and using references (`&`) allows you to work with the original objects without creating copies.
4. `ofVec2f diff = p2.position - p1.position;`: This line calculates the vector difference between the positions of `p2` and `p1`. `p2.position` and `p1.position` are the position vectors of the two particles. Subtracting one vector from the other gives you a new vector that points from `p1` to `p2`.
5. `return diff.length();`: This returns the length (magnitude) of the `diff` vector, which represents the distance between the particles. The `length()` function calculates the Euclidean length of the vector, which is the square root of the sum of squares of its components.

By using this function, you can easily calculate the distance between any two particles in your vector and use it for implementing behaviors based on particle distances.

# Methods

The application presents only a basic simulation that starts the moment that the compiled .exe file is run.  Here I will list as paragraph all the important information and concepts that will explain not only this basic simulation, but eventually what I learned by self-studying:

### 01. ofColor implementation


