# Reference 'Factory' Implementation (C++)

## What is this?
A reference implementation of a Factory structure. This **is not the 
Gang of Four type of Factory**. In this sense, a Factory is an object 
which handles the creation, tracking and deletion of a given type of 
object. This implementation is for C++ as single-header template with 
dependencies on the standard library.

### Why isn't this a Gang of Four Factory?
* I learned about Factories from a game programming book, when young. I 
misremembered what they were exactly.
* I found this structure still worked fantastically though for many of 
my needs.
* So it became known as a Factory, *to me*, and makes sense that way *to 
me*.
* I learned about Gang of Four about 4-5 years after I normalized this, 
and by then it was too late.
* Their version of Factory isn't readily simple to implement as a 
generic without some seriously involved code, and requires an in-depth 
implementation around your specific data types. I call that a factory 
too, but it's not a simple one like this. Yes, working with my 
nomenclature can be confusing.

## Usage
### Setup
1. Grab `Factory_struct.h`
2. Add it to your project.
3. `#include "Factory_struct.h"`
4. `Factory<YourType> yourFactory;`

### Creating an Element
`YourType* ptr = yourFactory.create();` or `YourType* ptr = 
yourFactory.create(someValue);`

### Finding an Element
`yourFactory.find(ptr);` or `yourFactory.getIndex(ptr);`

### Accessing an Element in the Factory Roster
`yourFactory[index];`

### Deleting an Element
`yourFactory.destroy(index);` or `yourFactory.destroy(ptr);`

## To-Do
1. Dependency injection for memory operations should be an option for this structure, so that memory layout can be managed by a structure with a distinct responsibility.
2. Object pooling rather than dynamic fragmented allocation with pointer storage should be the behavior of this ideally.

## License (Simplified)
This is under the MIT license.
1. There is 0 liability if you choose to use this.
2. You can freely use this, mod it, remix it, whatever you want.
3. You don't have to give me credit, but it would be appreciated.
4. Don't try to construe I'm affiliated with or endorse you just because 
you're using this code.
5. Have fun. Okay, I'll come clean - that's not in the normal license, 
but you still should.

## License (Full)
@todo

## Authors
Joseph Juma
