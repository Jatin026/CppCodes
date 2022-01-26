#include <iostream>
#include<cmath>
using namespace std;
class Restaurant{
    double mealcost;
    float tippercent;
    float taxpercent;
    public:
        void get_data(){
            cin >> mealcost;
            cin >> tippercent;
            cin >> taxpercent;
        }
        void process(){
            float total;
            total=mealcost*(1+(tippercent/100)+(taxpercent/100));
            cout<<round(total);
        }
};
int main()
{
    Restaurant c1;
    c1.get_data();
    c1.process();
    return 0;
}

