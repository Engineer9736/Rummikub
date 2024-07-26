#include <string>

// For every possible tile, there will be one TilePrototype in memory. This prototype will have the
// corresponding image in memory.


class TilePrototype {

    private:
        std::string color; // Still have to find out what the right variable type this will be, string for now as a placeholder.
        int number;




    // Returns the prototype for a specfic color and number combination.
    static TilePrototype GetPrototype(std::string color, int number) {

    }



};