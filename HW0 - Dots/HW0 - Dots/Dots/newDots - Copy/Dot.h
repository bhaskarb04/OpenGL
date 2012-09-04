#include<vector>
using namespace std;

struct point
{
	int x;
	int y;
};
class dot
{
public:
	vector<point>list;
	vector<point>paclist;
	dot();
	~dot();
};