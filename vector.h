#ifndef VECTOR_H
#define VECTOR_H

template <typename Tr>
class Vector {
    public:
        typedef typename Tr::T T;
        typedef typename Tr::Operation Operation;

    private:
        T* data;
        int dataSize;

        int dimensions;
        int* dimensionSizes;

        Operation operation;

    public:
        Vector() : data(nullptr) {};

        Vector(int dimensions, int* dimensionSizes) : dimensions(dimensions) {
            this->dimensionSizes = new int[dimensions];

            for (int i = 0; i < dimensions; i++)
                this->dimensionSizes[i] = dimensionSizes[i];

            dataSize = 1;

            for (int i = 0; i < dimensions; i++)
                dataSize *= dimensionSizes[i];

            data = new T[dataSize]();
        }

        void set(T datum, int* coordinates) {
            *(data + operation(coordinates, dimensionSizes, dimensions)) = datum;
        }

        T get(int* coordinates) {
            return data[operation(coordinates, dimensionSizes, dimensions)];
        }

        ~Vector() {
            delete[] data;
        }
};

#endif
