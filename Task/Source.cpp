/**
* Done by:
* Student Name: Ivan Rudiy
* Student Group: 123
*Pract 1.5
*/
#include <iostream>
#include <vector>

using namespace std;

bool areEqual(int a, int b) {
    int bitSize = sizeof(int) * 8;

    for (int i = 0; i < bitSize; i++) {
        int mask = 1 << i;
        int a_bit = a & mask;
        int b_bit = b & mask;

        if (a_bit != b_bit) {
            return false;
        }
    }
    return true;
}

void printVector(const std::vector<int>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

int countBits(int number, bool bitValue) {
    int count = 0;
    while (number > 0) {
        if ((number & 1) == bitValue) {
            count++;
        }
        number >>= 1;
    }
    return count;
}



int main() {
    {
 

        int a, b;
        std::cout << "Enter A: ";
        std::cin >> a;
        std::cout << "Enter second integer: ";
        std::cin >> b;
        //first solution
       /* int onesCount = countBits(a, 1);
        int zerosCount = countBits(a, 0);

        std::cout << "Numbers of 1: " << onesCount << std::endl;
        std::cout << "Numbers of 0: " << zerosCount << std::endl;

        if (onesCount > zerosCount) {
            std::cout << "More 1" << std::endl;
        }
        else if (onesCount < zerosCount) {
            std::cout << "More 0" << std::endl;
        }
        else {
            std::cout << "The same amount" << std::endl;
        }*/
        
        //second solution
        int onesCount = 0;
        int zerosCount = 0;
        int totalBits = sizeof(a) * 8; 

        for (int i = 0; i < totalBits; ++i) {
            if (a & (1 << i))
            {  
                onesCount++;
            }
            else 
            {
                zerosCount++;
            }
        }

        std::cout << "Number of 1 in variable A: " << onesCount << std::endl;
        std::cout << "Number of 0 in variable A: " << zerosCount << std::endl;

        if (onesCount > zerosCount) {
            std::cout << "More 1" << std::endl;
        }
        else if (onesCount < zerosCount) {
            std::cout << "More 0" << std::endl;
        }
        else {
            std::cout << "The same amount" << std::endl;
        }

       
    }

 

    {

        int n = 10;

        std::vector<int> a(n);
        std::vector<int> b(n);

        for (int i = 0; i < n; i++) {
            a[i] = rand() % 2;
            b[i] = rand() % 2;
        }

        std::cout << "A  : ";
        printVector(a);
        std::cout << "B  : ";
        printVector(b);

        std::vector<int> r_xor(n);

        for (int i = 0; i < n; i++) {
            r_xor[i] = a[i] ^ b[i];
        }
        std::cout << "XOR: ";
        printVector(r_xor);
    }

    return 0;
}