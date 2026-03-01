
#include "Array.hpp"

int main()
{
    Array<int> intArray(5);
    Array<float> floatArray(5);
    Array<double> doubleArray(5);

    for (int i = 0; i < intArray.getSize(); i++)
    {
        intArray[i] = i * 10;
        floatArray[i] = i + 1.1f;
        doubleArray[i] = i + 2.2;
    }

	for (int i = 0; i < intArray.getSize(); i++)
		{
			std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
			std::cout << "floatArray[" << i << "] = " << floatArray[i] << std::endl;
			std::cout << "doubleArray[" << i << "] = " << doubleArray[i] << std::endl;
			std::cout << "------------------------" << std::endl;
		}

    try
    {
        std::cout << "Trying out-of-bounds assignment..." << std::endl;
        floatArray[10] = 3.14f;
    }
    catch (std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    return 0;

}
