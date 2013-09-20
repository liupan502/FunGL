#ifndef triangle_h
#define triangle_h
class Triangle{
private:
	int pointsIndex[3];
public:
	Triangle();
	void GetPointsIndex(int index[3]);
	void SetPointsIndex(const int index[3]);
};
#endif
