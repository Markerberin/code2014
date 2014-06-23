#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <string>
#include <fstream>
#include <unordered_set>
#include <algorithm> 
using namespace std;


struct point {
    double x;
    double y;
    point (double v1,double v2) {
        x = v1;
        y = v2;
    };
    point() {
    }
    bool operator==(const point &two) const{
        return (two.x == x) &&(two.y == y);
    }
};

struct bridge {
    point one;
    point two;
    bridge (point &o,point &t) {
        one = o;
        two = t;
    }
};

double min( double x1, double x2) {
    if(x1 < x2) return x1;
    return x2;
}
double max(double x1,double x2) {
    if(x1 > x2) return x1;
    return x2;
}
bool is_line(point &a,point &b, point &c) {
    return (a.y-c.y)*(a.x-b.x) == (a.y-b.y)*(a.x-c.x);
}
bool is_touch(bridge &b1,bridge &b2) {
    if(is_line(b1.one,b1.two,b2.one) && b2.one.x > min(b1.one.x,b1.two.x) &&
       b2.one.x < max(b1.one.x,b1.two.x) ) return true;
        
    if(is_line(b1.one,b1.two,b2.two) && b2.two.x > min(b1.one.x,b1.two.x) &&
       b2.two.x < max(b1.one.x,b1.two.x) ) return true;
        
    if(is_line(b2.one,b2.two,b1.one) && b1.one.x > min(b2.one.x,b2.two.x) &&
       b1.one.x < max(b2.one.x,b2.two.x) ) return true;
        
    if(is_line(b2.one,b2.two,b1.two) && b1.two.x > min(b2.one.x,b2.two.x) &&
       b1.two.x < max(b2.one.x,b2.two.x) ) return true;
    
    return false;
}

bool clockwise(point &a, point &b, point &c) {
    return (a.y-c.y)*(a.x-b.x)<(a.y-b.y)*(a.x-c.x);
}
bool is_intersets(bridge &b1, bridge & b2) {
     if(b1.one == b2.one || b1.one == b2.two || b1.two == b2.two || b1.two == b2.one) 
          return true;
     if(is_touch(b1,b2)) 
          return true;
     return (clockwise(b1.one,b1.two,b2.one)!= clockwise(b1.one,b1.two,b2.two)) &&(clockwise(b2.one,b2.two,b1.one) != clockwise(b2.one,b2.two,b1.two));
}
bool check(char c) {
    if(c < '0' || c > '9') {
        if(c != '+' && c != '-') return false;
    }
    return true;
}
int main(int argc,char * argv[]) {
/*Sample code to read in test cases: */

ifstream file;
string lineBuffer;

if(argc <= 1  || argv[1] == NULL) {
    printf("input error!\n");
    return -1;
} 
file.open(argv[1]);
if(!file.is_open()) {
    printf("can't open file\n");
    return -1;
}
vector<bridge> bridges;
while (!file.eof()) 
   {
       getline(file, lineBuffer);
       if (lineBuffer.length() == 0)
           continue; //ignore all empty lines
       else 
       {
           //do something here
           int len = lineBuffer.size();
           string::size_type sz;
           int id = stoi(lineBuffer,&sz);
           while(sz <len && !check(lineBuffer[sz])) sz++;
           lineBuffer = lineBuffer.substr(sz);
           double x1 = std::stod(lineBuffer,&sz);
           while(sz <len && !check(lineBuffer[sz])) sz++;
           lineBuffer = lineBuffer.substr(sz);
           double y1 = stod(lineBuffer,&sz);
           while(sz <len && !check(lineBuffer[sz])) sz++;
           lineBuffer = lineBuffer.substr(sz);
           double x2 = stod(lineBuffer,&sz);
           while(sz <len && !check(lineBuffer[sz])) sz++;
           lineBuffer = lineBuffer.substr(sz);
           double y2 = stod(lineBuffer,&sz);
           point one(x1,y1);
           point two(x2,y2);
           bridge b(one,two);
           bridges.push_back(b);
       }
   }
   int len = bridges.size();
   
   unordered_set<int> intersets[len+1];
   for(int i=1;i<=len;i++) {
       for(int j=i+1;j<=len;j++) {
           if( is_intersets(bridges[i-1],bridges[j-1])) {
                 intersets[i].insert(j);
                 intersets[j].insert(i);
           }
       }
   }
   vector<int> res;
   vector<int> unfin;
   
   for(int i=1;i<=len;i++) unfin.push_back(i);
   int min;
   while(true) {
       len = unfin.size();
       for(int i=len-1;i>=0;i--) {
           if(intersets[unfin[i]].size() == 0) {
                res.push_back(unfin[i]); 
                unfin.erase(unfin.begin() + i); 
           }
       }
       len = unfin.size();
       if(len == 0) break;
       min = 0;
       for(int i=1;i<len;i++) {
           if(intersets[unfin[i]].size() <intersets[unfin[min]].size()) 
               min = i; 
       }
       int minID = unfin[min];
       unordered_set<int>::iterator it = intersets[minID].begin(), iit;
       for(;it != intersets[unfin[min]].end();it++)  {
            int tmp = *it;
            for(iit = intersets[tmp].begin();iit != intersets[tmp].end();iit++) {
                 if(*iit == minID) continue;
                 if(intersets[*iit].find(tmp)!= intersets[*iit].end())
                      intersets[*iit].erase(tmp);
            }
            intersets[tmp].clear();
            for(int i=0;i<unfin.size();i++) {
            	if(unfin[i] == tmp) {
                   unfin.erase(unfin.begin()+i);
                   break;
                }
			}
       }
       intersets[unfin[min]].clear();
   }
   sort(res.begin(),res.end());
   for(int i=0;i<res.size();i++) 
	cout <<res[i]<<endl;
return 0;
}
