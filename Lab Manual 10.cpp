#include<iostream>
#include<vector>

//TASK 1
using namespace std;

int main() {
vector<int>push;

cout<<"Enter 10 elements for the vector:\n";

for(int i=0;i<10;++i) {
int element;

cin>>element;
push.push_back(element);
}

cout<<"Elements in the vector:";
for(const auto&element:push) {
cout<<element<<" ";
}
cout<<endl;

push.push_back(5);

int position;
cout<<"Enter the position to remove (0 to 9):"; cin>>position;

if(position>=0&&position<push.size()) {
push.erase(push.begin()+position);
}

cout<<"Elements in the vector after pushing 5 and removing element at position (0 to 9):";
for(const auto&element:push) {
cout<<element<<" ";
}
cout<<endl;

return 0;
}


//TASK 2

#include<iostream>
#include<vector>

using namespace std;

void sort(vector<int>& values) {
	
int n=values.size();

for(int i=0;i<n-1;i++) {
for(int j=0;j<n-i-1;j++) {
	
if(values[j]>values[j+1]) {
	
int temp=values[j];

values[j]=values[j+1];
values[j+1]=temp;
}
}
}
}

int median(vector<int>& values) {
sort(values);
int n=values.size();
int median;
if(n%2==0) {
median=(values[n/2-1]+values[n/2])/2;
}
else {
median=values[n/2];
}
return median;
}

int mode(const vector<int>& values) {
int maxfrequency=0;
int modeValue=0;
for(int i=0;i<values.size();i++) {
int frequency=0;
for(int j=0;j<values.size();j++) {
if(values[i]==values[j]) {
frequency++;
}
}
if(frequency>maxfrequency) {
maxfrequency=frequency;
modeValue=values[i];
}
}
return modeValue;
}

void equalgrades(const vector<string>& names,const vector<int>& grades,int mode) {
cout<<"Students with GradeEqual to Modevalue:";
for(int i=0;i<names.size();i++) {
if(grades[i]==mode) {
cout<<names[i]<<" ";
}
}
cout<<endl;
}

int main() {
vector<string> studentNames;
vector<int> studentGrades;
int num,mean,medianValue,modeValue;

cout<<"What is the number of students:";
cin>>num;

for(int i=0;i<num;i++) {
string name;
int grade;

cout<<"Name of student:";
cin>>name;
studentNames.push_back(name);

cout<<"Enter the grade percentage:";
cin>>grade;
studentGrades.push_back(grade);}

int sum=0;
for(int i=0;i<studentGrades.size();i++) {
sum+=studentGrades[i];}
mean=sum/studentGrades.size();
cout<<"Mean:"<<mean<<endl;

medianValue=median(studentGrades);
cout<<"Median:"<<medianValue<<endl;

modeValue=mode(studentGrades);
cout<<"Mode:"<<modeValue<<endl;

equalgrades(studentNames,studentGrades,modeValue);

return 0;
}

