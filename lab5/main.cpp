#include "lab5/BoolVector.hpp"

int main() {
    vb::BoolVector<bool> boolVector;
    boolVector.pushBack(false);
    boolVector.pushBack(true);
    boolVector.pushBack(true);
    boolVector.pushBack(false);
    boolVector.pushBack(true);
    boolVector.pushBack(false);
    boolVector.pushBack(false);
    boolVector.pushBack(false);
    boolVector.pushBack(true);
    boolVector.pushBack(false);
    boolVector.pushBack(true);
    boolVector.pushBack(true);
    boolVector.pushBack(true);
    boolVector.pushBack(false);
    boolVector.pushBack(false);
    boolVector.pushBack(false);
    boolVector.pushBack(false);
    boolVector.pushBack(false);
    boolVector.pushBack(false);
    boolVector.pushBack(true);
    boolVector.pushBack(false);
    boolVector.pushBack(true);
    boolVector.pushBack(false);
    boolVector.pushBack(false);

    boolVector.outArray();
    boolVector.erase(12, 2);
    boolVector.outArray();
    return 0;
}