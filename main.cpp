#include <iostream>
#include <vector>

using namespace std;

int predict(vector<int>&input)
{
 vector<int> x;
 for (size_t i = 0 ; i < input.size() - 1 ; ++i)
  x.push_back(input[i+1] - input[i]);

 int f = x[1] / x[0];
 int a = x[1] % x[0];
 int step = x.back() * f + a;

 if (a!=0)
  step = predict(x);

 return (input.back() + step);
}


float predict(vector<float>&input)
{
 vector<float> x;
 for (size_t i=0; i<input.size()-1; i++)
  x.push_back(input[i+1] - input[i]);

 float f = x[1]/x[0];
 return (input.back() + (x.back() * f));
}



template <typename T>
void doPrediction(vector<T>&input)
{
 if (input.size()<3){
  cout << "At least 3 values required for predict next number in the based on the rule!" << endl;
  return;
 }
 for(typename vector<T>::iterator it = input.begin() ; it != input.end() ; ++it)
  cout << *it << " ";

 cout << " ==> " << predict(input) <<endl;
}



int main() {
  cout << "----------Predict next number based on the rule with integer values!----------" << endl << endl;
// Prediction examples
 vector<int> vData1{4,7,13,25,49};
 cout << "Predict 1: " ;
 doPrediction(vData1);
 cout << endl;
// - - - - - - - - - - - - - - - - - - - - -
 vector<int> vData2{2,4,6,8};
 cout << "Predict 2: ";
 doPrediction(vData2);
 cout << endl;
// - - - - - - - - - - - - - - - - - - - - -
 vector<int> vData3{4,9,16,25,36,49,64,81};
 cout << "Predict 3: ";
 doPrediction(vData3);
 cout << endl;
// - - - - - - - - - - - - - - - - - - - - -
 vector<int> vData3_0{8,27,64,125,216};
 cout << "Predict 4: ";
 doPrediction(vData3_0);
 cout << endl;
// - - - - - - - - - - - - - - - - - - - - -
 vector<int> vData3_01 {16,81,256,625,1296,2401};
 cout << "Predict 5: ";
 doPrediction(vData3_01);
 cout << endl;
// - - - - - - - - - - - - - - - - - - - - -
 vector<int> vData3_02{32,243,1024,3125,7776,16807,32768,59049};
 cout << "Predict 6: ";
 doPrediction(vData3_02);
 cout << endl;
// - - - - - - - - - - - - - - - - - - - - - BASICS - - - - - - - - - - - - - - - - - - - - - - - - - - //
 vector<int> vData3_1{19, 20, 21};
 cout << "Linear Predict 7: ";
 doPrediction(vData3_1);
 cout << endl;
// - - - - - - - - - - - - - - - - - - - - -
 vector<int> vData4{5,10,17,26,37,50};
 cout << "Predict 8: ";
 doPrediction(vData4);
 cout << endl;
// - - - - - - - - - - - - - - - - - - - - -
 vector<int> vData5{10,1,2,9,3,8,4,7};
 cout << "Predict 9: ";
 doPrediction(vData5);
 cout << endl;
// - - - - - - - - - - - - - - - - - - - - -
 vector<int> vData6{1,4,9,16,25,36};
 cout << "Predict 10: ";
 doPrediction(vData6);
 cout << endl;
// - - - - - - - - - - - - - - - - - - - - -
 vector<int> vData7{2,5,11,17,23};
 cout << "Predict 11: ";
 doPrediction(vData7);
 cout << endl;

return 0;
}
