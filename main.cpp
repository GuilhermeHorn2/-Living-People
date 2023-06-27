#include <iostream>
#include <vector>

class coord{

public:
	int x;
	int y;
	coord(int a,int b){
		x = a;
		y = b;
	}

	~coord(){
		free(this);
	}
};


int most_num(std::vector<coord*> &v);

int main()
{
	 /* ?\n;||(or) e &&(and)*/

	coord* c1 = new coord(1900,1951);
	coord* c2 = new coord(1901,1903);
	coord* c3 = new coord(1902,1908);
	coord* c4 = new coord(1927,1983);
	coord* c5 = new coord(1900,1971);

	std::vector<coord*> v = {c1,c2,c3,c4};

	std::cout << most_num(v) << '\n';



	return 0;
}


int most_num(std::vector<coord*> &v){

	std::vector<std::string> intervals;
	std::vector<int> overlap;

	//initializing the vectors
	for(int i = 0;i <= 100;i++){
		intervals.push_back("");
		overlap.push_back(0);
	}
	//setting the intervals
	for(int i = 0;i < v.size();i++){
		int x = v[i]->x-1900;
		int y = v[i]->y-1900;
		intervals.at(x) = "(";
		intervals.at(y) = ")";
		overlap.at(x)++;
		overlap.at(y)++;
	}

	//checking the interval with most intersections
	int max = 0;
	int curr = 0;
	int year;
	for(int i = 0;i < intervals.size();i++){
		std::string s = intervals[i];
		if(s == "("){
			curr += overlap[i];
		}
		if(s == ")"){
			if(max <= curr){
				max = curr;
				year = 1900+i;
			}
			curr -= overlap[i];
		}

	}

	return year;
}


