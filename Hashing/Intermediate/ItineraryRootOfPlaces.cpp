#include <iostream>
#include <map>
using namespace std;

void printItinerary(map<string, string> dataSet) 
{
    map<string, string> reversemap; 
    map<string, string>::iterator it;

    for(it = dataSet.begin();it!=dataSet.end();it++){
        reversemap[it->second] = it->first;
    }

    string first;
    for(it=dataSet.begin();it!=dataSet.end();it++){
        if(reversemap.find(it->first)==reversemap.end()){
            first = it->first;
            break;
        }
    }

    if (first.empty()) 
    { 
    cout << "Invalid Input" << endl; 
    return; 
    }

    it = dataSet.find(first);
    while(it!=dataSet.end()){
        cout << it->first << "->" << it->second << endl;
        it=dataSet.find(it->second);
    }
}

int main() {
    map<string, string> dataSet; 
    dataSet["Chennai"] = "Banglore"; 
    dataSet["Bombay"] = "Delhi"; 
    dataSet["Goa"] = "Chennai"; 
    dataSet["Delhi"] = "Goa"; 
  
    printItinerary(dataSet);
    cout<<endl;
	return 0;
}