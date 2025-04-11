#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
class Name{
    private:
    vector<string> name;
    map<string,int> nameAge;
    int numPeople, pAge, threshold;
    string pName;
    public:
    void getData(){
        cout<<"How many number of people do you want to add?? "<<endl;
        cin>>numPeople;
        cin.ignore();
        getDataNameAge(numPeople);
    }
    void getDataNameAge(int num){
        for(int i=0;i<num;i++){
            cout<<"Enter name: "<<endl;
            getline(cin,pName);
            cout<<"Enter the age: "<<endl;
            cin>>pAge;
            name.push_back(pName);
            cin.ignore();
            nameAge[pName] = pAge;
        }
    }
    void getDataAgeThreshold(){
        cout<<"Enter the age threshold: "<<endl;
        cin>>threshold;
        displayThreshold(threshold);
    }
    void displayThreshold(int thres){
        for(const auto& val : nameAge){
            if(val.second > threshold){
                cout<<"Name: "<<val.first<<" Age: "<<val.second<<endl;
            }
        }
    }
    void sortName(){
        sort(name.begin(),name.end());
        cout<<"Name sorted alphabetically: "<<endl;
        for(const auto& val : name){
            cout<<val<<endl;
        }
    }
};
int main()
{
    Name n1;
    n1.getData();
    n1.getDataAgeThreshold();
    n1.sortName();
return 0;
}