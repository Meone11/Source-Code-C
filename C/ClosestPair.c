//Clesest Pair Point Program
#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <math.h>

// Struktur ini dibuat untuk merepresentasikan titak-titik dalam bidang 2 dimensi
typedef struct Point
{
	int x, y;
}Point;

// Mengurutkan Titik - Titik Didalam Array berdasarkan Koordinat x
int compareX(const void* a, const void* b)
{
	Point *p1 = (Point *)a, *p2 = (Point *)b;
	return (p1->x - p2->x);
}

// Mengurutkan Titik - Titik Didalam Array berdasarkan Koordinat y
int compareY(const void* a, const void* b)
{
	Point *p1 = (Point *)a, *p2 = (Point *)b;
	return (p1->y - p2->y);
}

// Fungsi untuk mengembalikan Jarak diantara 2 titik 
float dist(Point p1, Point p2)
{
	return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

// Fungsi Brute Force untuk mengembalikan nilai terpendek dari titik ke dalam array
float bruteForce(Point P[], int n)
{
	float min = FLT_MAX;
	for (int i = 0; i < n; ++i)
		for (int j = i+1; j < n; ++j)
			if (dist(P[i], P[j]) < min)
				min = dist(P[i], P[j]);
	return min;
}

// Fungsi Untuk menemukan jarak minimum
float min(float x, float y)
{
	return (x < y)? x : y;
}


/* fungsi untuk menemukan jarak terdekat dari titik berdasarkan ukuran dari array strip.
Semua Titik diurutkan berdasarkan koordinat y. Titik Tersebut mempunyai batas atas ke jarak minimun d.*/
float stripClosest(Point strip[], int size, float d)
{
	float min = d; // inisialisasikan jarak minimum

    //Fungsi qsort() adalah fungsi yang disediakan oleh C untuk mengurutkan array dengan teknik divided and conquer
	qsort(strip, size, sizeof(Point), compareY);

	// Brute Force semua titik sampai menemukan koordinat y yang lebih kecil dari d
	// Dan ini juga membuktikan bahwa looping hanya berjalan 6 kali
	for (int i = 0; i < size; ++i)
		for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
			if (dist(strip[i],strip[j]) < min)
				min = dist(strip[i], strip[j]);

	return min;
}

// Rekursif Fungsi untuk menemukan jarak terdekat dan semua titik yang terkandung di dalam array berasal dari koordinat x
float closestUtil(Point P[], int n)
{
	// jika terdapat 3 atau lebih kecil maka akan di brute force
	if (n <= 3)
		return bruteForce(P, n);

	// Titik tengah atau kita kenal dengan median
	int mid = n/2;
	Point midPoint = P[mid];

	// Menghitung dl = kiri dari Median dan dr = kanan dari median
	float dl = closestUtil(P, mid);
	float dr = closestUtil(P + mid, n-mid);

	// Mengambil nilai minimum
	float d = min(dl, dr);

	// Membuat array Strip yang terdekat 
	Point strip[n];
	int j = 0;
	for (int i = 0; i < n; i++)
		if (abs(P[i].x - midPoint.x) < d)
			strip[j] = P[i], j++;

	// Menemukan Closest Point di Strip, Mereturn d sebagai minimum dan jarak minimum adalah strip[]
	return min(d, stripClosest(strip, j, d) );
}

// Main fungsi untuk menemukan Closest Pair Point
float closest(Point P[], int n)
{
	qsort(P, n, sizeof(Point), compareX);

	return closestUtil(P, n);
}

// Main Body
int main()
{
	Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
	int n = sizeof(P) / sizeof(P[0]);
	printf("Jarak Terdekat Adalah %f ", closest(P, n));
	return 0;
}
