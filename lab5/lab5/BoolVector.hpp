#include <iostream>
#include <cstring>

#pragma once

namespace vb {
    template<class T>
    class BoolVector {
    public:
        BoolVector() { std::cout << "hello, world" << std::endl; }
    };

    template<>
    class BoolVector<bool> {
    public:
        BoolVector() {
            createArray();
        };

        ~BoolVector() {
            delete[] array;
        }

        int size() {
            return bitSize;
        }

        void changeElement(int index, bool value) {
            if ((index >= 0) && (index < bitSize)) {
                int bitIndex = index % 8;
                int arrayIndex = index / 8;
                changeElement(bitIndex, arrayIndex, value);
            }
            else
                throw std::exception();
        }

        bool operator[](int index) const {
            int arrayIndex = index / 8;
            int bitIndex = index % 8;
            return ((1 << bitIndex) & array[arrayIndex]) != 0;
        }

        void pushBack(bool item) {
            bitSize++;
            int index = (bitSize - 1) % 8;
            int arrayIndex = (bitSize - 1) / 8;
            if (((bitSize - 1) % 8 == 0) && (bitSize != 0))
                increaseSizeArray();
            changeElement(index, arrayIndex, item);
        }

        void insert(const int& position, const int& count,
            const bool& value) {
            if ((position < bitSize) && (position >= 0)) {
                if ((bitSize + count) % 9 == 0)
                    increaseSizeArray();
                for (int i = (bitSize - 1) + count; i > position; i--)
                    changeElement(i % 8, i / 8, getItem((i - count) % 8, (i - count) / 8));
                for (int i = position; i < position + count; i++)
                    changeElement(i % 8, i / 8, value);
                bitSize += count;
            }
            else
                std::cout << "Error..." << std::endl;
        }

        void erase(const int& position,
            const int& count) {
            int index = position % 8;
            if ((index < bitSize) && (index >= 0) &&
                ((count + position) < bitSize)) {
                for (int j = position; j < bitSize - 1; j++)
                    changeElement(j % 8, j / 8, getItem((j + count) % 8, (j + count) / 8));
                bitSize -= count;
                if ((bitSize / 8) < (arraySize - 1))
                    decreaseSizeArray();
            }
            else
                std::cout << "Error..." << std::endl;
        }

        void outArray() const {
            for (int i = 0; i < bitSize; i++)
                std::cout << (bool)(*this)[i] << " ";
            std::cout << "| " << bitSize << std::endl;
        }

    private:
        int bitSize = 0;
        int arraySize = 1;
        char* array;

        void createArray() {
            array = new char[arraySize];
            for (int i = 0; i < 8; i++) {
                array[0] = (0 << i) & array[0];
            }
        }

        bool getItem(const int& bitIndex,
            const int& arrayIndex) const {
            return ((1 << bitIndex) & array[arrayIndex]) != 0;
        }

        void changeElement(const int& bitIndex, const int& arrayIndex, const bool item) {
            array[arrayIndex] = (~(1 << bitIndex)) & array[arrayIndex] | (item << bitIndex);
        }

        void increaseSizeArray() {
            char* tempArray = array;
            array = new char[arraySize + 1];
            std::memcpy(array, tempArray, arraySize);
            delete[] tempArray;
            arraySize++;
        }

        void decreaseSizeArray() {
            arraySize--;
            char* tempArray = array;
            array = new char[arraySize];
            std::memcpy(array, tempArray, arraySize);
            delete[] tempArray;
        }
    };
}