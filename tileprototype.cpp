#include <string>

class TilePrototype {

    private:
        std::string color;
        int number;

    // For every possible tile, there will be one TilePrototype in memory. This prototype will have the
    // corresponding image in memory.


    // Returns the prototype for a specfic color and number combination.
    static TilePrototype GetPrototype(std::string color, int number) {

    }



};