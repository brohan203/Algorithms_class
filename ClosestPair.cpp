// Closest pair of points
// Rohan 2020

#include<stdio.h>
#include<iostream>
#include <stdlib.h>     /* qsort */
#include <math.h>
using namespace std;

class Point {
	public:
	int x, y; 
};


// Compare functions
int compareX(const void* a, const void* b)  
{  
    Point *p1 = (Point *)a, *p2 = (Point *)b;  
    return (p1->x - p2->x);  
}

int compareY(const void* a, const void* b)  
{  
    Point *p1 = (Point *)a, *p2 = (Point *)b;  
    return (p1->y - p2->y);  
} 


// Calculate distance between two points. Uses pythagorean
float dist(Point p1, Point p2) {
	return sqrt( ((p1.x - p2.x)*(p1.x - p2.x)) + ((p1.y - p2.y)*(p1.y - p2.y)));
}

float bruteForce(Point P[], int n)  
{  
    float min = 99999999.0;  
    for (int i = 0; i < n; ++i)  
        for (int j = i+1; j < n; ++j)  
            if (dist(P[i], P[j]) < min)  
                min = dist(P[i], P[j]);  
    return min;  
}  


// Print all the points in an array
void printPointArray(Point P[], int n) {
	for(int i=0; i<n; i++) {
		std::cout << "(" << P[i].x << ", " << P[i].y << ") ";
	}
	std::cout << "\n";
}

float min(float l, float r) {
	if(l < r) {
		return l;
	}
	else {
		return r;
	}
}

float stripClosest(Point strip[], int n, float d) {
	float min = d;
	qsort(strip, n, sizeof(Point), compareY);

	for(int i = 0; i<n; i++) {
		for(int j = i+1; j < n && strip[j].y - strip[i].y < min; j++) {
			min = dist(strip[i], strip[j]);
		}
	}
	return min;
}

// 
float closestPoints(Point P[], int n) {
	std::cout << "iteration with " << n << " length\n";
	if(n <= 3) {
		std::cout << "Using brute force on " << n << " length\n";
		return bruteForce(P, n);
	}
	int mid = n/2;
	Point midpoint = P[mid];


	float dL = closestPoints(P, mid);
	float dR = closestPoints(P+mid, n-mid);

	std::cout << "Closest points at " << n << " length are " << dL << " and " << dR << "\n";

	float d = min(dL, dR);

	Point strip[n];
	int j = 0;
	for(int i=0; i<n; i++) {
		if(abs(midpoint.x - P[i].x) < d) {
			strip[i] = P[i];
			j++;
		}
	}


	return stripClosest(strip, j, d);
}

// Find the closest points in an array of points
float closest(Point P[], int n) {

	std::cout << "Input array is \n";
	printPointArray(P, n);
	qsort(P, n, sizeof(Point), compareX);
	std::cout << "Array sorted by x is \n";
	printPointArray(P, n);
	return closestPoints(P, n);
}

int main()
{
	Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}, {6,39}};  
	int n = sizeof(P) / sizeof(P[0]);

	float d = closest(P, n);
	printf("The closest points have a distance of \n");
	std::cout << d << "\n";
	return 0;
}