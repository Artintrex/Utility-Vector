// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <iostream>
#include "Vector.h"

int main()
{	
	Vector3 firstVector(10, 8, 0);
	Vector3 secondVector(-2, 3, 0);
 
	Vector3 thirdVector = Vector3::Lerp(firstVector, secondVector, 0.1);

    std::cout << thirdVector.x << " " << thirdVector.y << " " << thirdVector.z << "\n";
	std::cout << "Distance is: " << Vector3::Distance(thirdVector, firstVector) << "\n";

	
	
	std::cout << "Angle between " << Vector3(3, 4, 0).ToString() << " and " << Vector3(0, 5, 5).ToString() << " is "
	<< Vector3::Angle(Vector3(3, 4, 0), Vector3(0, 5, 5)) << "\n";
	
	std::cout << "\n\n";

	return 0;
}