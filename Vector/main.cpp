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

	std::cout << "Negative Infinity: " << Vector3::negativeInfinity.ToString() << "\n";
	std::cout << "Positive Infinity: " << Vector3::positiveInfinity.ToString() << "\n";
	
	std::cout << "Triangle Collision Check: " << Vector2::PointTriangleIntersection(Vector2(3.5,4), Vector2(4,5), Vector2(3,2), Vector2(-5,-3)) << "\n";
	std::cout << "Triangle Area: " << Vector2::TriangleArea(Vector2(4, 5), Vector2(3, 2), Vector2(-5, -3)) << "\n";

	Vector3 intersection;
	bool intersect = Vector3::LinePlaneIntersection(intersection, Vector3(-0.1,-1,0).Normalize(), Vector3(0,10,0), Vector3(3,4,0), Vector3(0,0,-10));
	
	if(intersect) std::cout << "Line intersects plane at: " << intersection.ToString() << "\n";

	intersect = Vector3::LineTriangleIntersection(intersection, Vector3(-0.2, -1, 0.1).Normalize(), Vector3(0, 6, 0),
		Vector3(0, 0, 5), Vector3(-5, 1, -5), Vector3(5, 0, -5));

	if (intersect) std::cout << "Line intersects triangle at: " << intersection.ToString() << "\n";
	
	std::cout << "\n\n";
	return 0;
}